/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:43:46 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 11:57:09 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *p)
{
	t_vars	*ptrs;

	ptrs = (t_vars *)p;
	mlx_destroy_image(ptrs->ptr_mlx, ptrs->data->frame);
	mlx_destroy_window(ptrs->ptr_mlx, ptrs->ptr_win);
	mlx_destroy_display(ptrs->ptr_mlx);
	free(ptrs->ptr_mlx);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_window(t_data *frame, t_vars *ptrs)
{
	ptrs->ptr_mlx = mlx_init();
	if (!ptrs->ptr_mlx)
		return ;
	ptrs->scale = 1.0;
	ptrs->mx = 0.0;
	ptrs->my = 0.0;
	ptrs->ptr_win = mlx_new_window(ptrs->ptr_mlx, X_AXIS, Y_AXIS, "fractol");
	ptrs->color = 0x001affff;
	ptrs->data = frame;
	frame->frame = mlx_new_image(ptrs->ptr_mlx, X_AXIS, Y_AXIS);
	frame->addr = mlx_get_data_addr(frame->frame, &frame->bits_per_pixel,
			&frame->line_length, &frame->endian);
	mlx_mouse_hook(ptrs->ptr_win, mouse_zoom, ptrs);
	mlx_hook(ptrs->ptr_win, MotionNotify, PointerMotionMask, mouse_pos, ptrs);
	mlx_hook(ptrs->ptr_win, DestroyNotify, NoEventMask, close_window, ptrs);
	mlx_key_hook(ptrs->ptr_win, input_keyboard, ptrs);
	mlx_loop(ptrs->ptr_mlx);
}
