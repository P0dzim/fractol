/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:48:23 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 14:14:42 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	move_control(int keycode, t_vars *ptrs);

int	mouse_pos(int x, int y, void *p)
{
	t_vars	*ptrs;

	ptrs = (t_vars *)p;
	ptrs->x = x;
	ptrs->y = y;
	if (ptrs->frac == 'j')
		put_fractal(ptrs);
	return (0);
}

int	mouse_zoom(int button, int x, int y, void *p)
{
	t_vars	*ptrs;
	float	new_mouse_re;
	float	new_mouse_im;
	float	mouse_re;
	float	mouse_im;

	ptrs = (t_vars *)p;
	mouse_re = -2 + ((float)x / X_AXIS) * 4.0 / ptrs->scale;
	mouse_im = 2 - ((float)y / Y_AXIS) * 4.0 / ptrs->scale;
	if (button == 4)
		ptrs->scale *= ZOOM_SCALE;
	else if (button == 5)
		ptrs->scale /= ZOOM_SCALE;
	else
		return (0);
	new_mouse_re = -2 + ((float)x / X_AXIS) * 4.0 / ptrs->scale;
	new_mouse_im = 2 - ((float)y / Y_AXIS) * 4.0 / ptrs->scale;
	ptrs->mx += mouse_re - new_mouse_re;
	ptrs->my += new_mouse_im - mouse_im;
	put_fractal(ptrs);
	return (0);
}

int	input_keyboard(int keycode, void *param)
{
	t_vars	*ptrs;

	ptrs = (t_vars *) param;
	if (keycode == XK_Escape)
		(void) close_window(param);
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		generate_palette(ptrs);
	if (keycode >= XK_Left && keycode <= XK_Down)
		move_control(keycode, ptrs);
	put_fractal(ptrs);
	return (0);
}

static void	move_control(int keycode, t_vars *ptrs)
{
	if (keycode == XK_Left)
		ptrs->mx -= 0.1;
	else if (keycode == XK_Right)
		ptrs->mx += 0.1;
	else if (keycode == XK_Up)
		ptrs->my -= 0.1;
	else if (keycode == XK_Down)
		ptrs->my += 0.1;
}
