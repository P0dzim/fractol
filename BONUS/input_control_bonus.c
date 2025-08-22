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
		put_fractal(ptrs, ptrs->color);
	return (0);
}

int	mouse_zoom(int button, int x, int y, void *p)
{
	t_vars	*ptrs;

	ptrs = (t_vars *)p;
	ptrs->x = x;
	ptrs->y = y;
	if (button < 4 || button > 5)
		return (0);
	if (button == 4)
		ptrs->scale += 0.25;
	else
		ptrs->scale -= 0.25;
	ptrs->mx += (x - X_AXIS / 2) * (4.0 / X_AXIS) * (ptrs->scale / ptrs->scale);
	ptrs->my += (y - Y_AXIS / 2) * (4.0 / Y_AXIS) * (ptrs->scale / ptrs->scale);
	put_fractal(ptrs, ptrs->color);
	return (0);
}

int	input_keyboard(int keycode, void *param)
{
	t_vars	*ptrs;

	ptrs = (t_vars *) param;
	if (keycode == XK_Escape)
	{
		(void) close_window(param);
		return (0);
	}
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		ptrs->color = (unsigned int)(ptrs->color << 1);
	if (!ptrs->color)
		ptrs->color = 0x001affff;
	put_fractal(ptrs, ptrs->color);
	if (keycode >= XK_Left && keycode <= XK_Down)
		move_control(keycode, ptrs);
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
