/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:23:45 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 14:14:47 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_fractal(t_vars *ptrs)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < Y_AXIS)
	{
		while (x < X_AXIS)
		{
			ptrs->iter(x, y, 0, ptrs);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(ptrs->ptr_mlx,
		ptrs->ptr_win, ptrs->data->frame, 0, 0);
}

void	mandelbrot_interation(int x, int y, unsigned int color, t_vars *ptrs)
{
	float	z_next[2];
	float	z_curr[2];
	float	coords[2];
	int		i;

	i = 0;
	coords[X] = -2 + ((float)x / (float)X_AXIS / ptrs->scale) * 4 + ptrs->mx;
	coords[Y] = 2 - ((float)y / (float)Y_AXIS / ptrs->scale) * 4 - ptrs->my;
	z_curr[R] = 0.0;
	z_curr[I] = 0.0;
	while (i < ptrs->max_iter)
	{
		z_next[R] = z_curr[R] * z_curr[R] - z_curr[I] * z_curr[I];
		z_next[I] = 2 * z_curr[R] * z_curr[I];
		if (z_next[I] > 2.0 || z_next[I] < -2.0
			|| z_next[R] > 2.0 || z_next[I] < -2.0)
			break ;
		z_curr[R] = z_next[R] + coords[R];
		z_curr[I] = z_next[I] + coords[I];
		i++;
	}
	color = ptrs->palete[(i % ptrs->max_iter % PALETTE_SIZE)].value;
	if (i == ptrs->max_iter)
		my_mlx_pixel_put(ptrs->data, x, y, 0);
	else
		my_mlx_pixel_put(ptrs->data, x, y, color);
}

void	julia_interation(int x, int y, unsigned int color, t_vars *ptrs)
{
	float	pixels[2];
	float	temp;
	float	mouse[2];
	int		i;

	pixels[X] = -2 + ((float)x / (float)X_AXIS / ptrs->scale) * 4 + ptrs->mx;
	pixels[Y] = 2 - ((float)y / (float)Y_AXIS / ptrs->scale) * 4 - ptrs->my;
	mouse[R] = -2 + ((float)ptrs->x / (float)X_AXIS) * 4;
	mouse[I] = -2 + ((float)ptrs->y / (float)Y_AXIS) * 4;
	i = 0;
	while (!(pixels[I] > 2.0 || pixels[I] < -2.0
		|| pixels[R] > 2.0 || pixels[I] < -2.0) && i < 50)
	{
		temp = pixels[R];
		pixels[R] = pixels[R] * pixels[R] - pixels[I] * pixels[I] + mouse[R];
		pixels[I] = 2 * temp * pixels[I] + mouse[I];
		i++;
	}
	color = ptrs->palete[(i % ptrs->max_iter % PALETTE_SIZE)].value;
	if (i == 50)
		my_mlx_pixel_put(ptrs->data, x, y, 0);
	else
		my_mlx_pixel_put(ptrs->data, x, y, color);
}

void	bsf_interation(int x, int y, unsigned int color, t_vars *ptrs)
{
	float	pixels[2];
	float	temp;
	float	z_nbr[2];
	int		i;

	pixels[X] = -2 + ((float)x / (float)X_AXIS / ptrs->scale) * 4 + ptrs->mx;
	pixels[Y] = -2 + ((float)y / (float)X_AXIS / ptrs->scale) * 4 + ptrs->my;
	i = 0;
	z_nbr[R] = pixels[X];
	z_nbr[I] = pixels[Y];
	while (!(z_nbr[I] > 2.0 || z_nbr[I] < -2.0
			|| z_nbr[R] > 2.0 || z_nbr[I] < -2.0) && i < ptrs->max_iter)
	{
		temp = z_nbr[R] * z_nbr[R] - z_nbr[I] * z_nbr[I] + pixels[R];
		z_nbr[I] = 2 * z_nbr[R] * z_nbr[I];
		z_nbr[I] = z_nbr[I] * (1 - (z_nbr[I] < 0) * 2) + pixels[I];
		z_nbr[R] = temp;
		i++;
	}
	color = ptrs->palete[(i % ptrs->max_iter % PALETTE_SIZE)].value;
	if (i == ptrs->max_iter)
		my_mlx_pixel_put(ptrs->data, x, y, 0);
	else
		my_mlx_pixel_put(ptrs->data, x, y, color);
}

void	fix_julia_interation(int x, int y, unsigned int color, t_vars *ptrs)
{
	float	pixels[2];
	float	temp;
	int		i;

	pixels[X] = -2 + ((float)x / (float)X_AXIS / ptrs->scale) * 4 + ptrs->mx;
	pixels[Y] = 2 - ((float)y / (float)Y_AXIS / ptrs->scale) * 4 - ptrs->my;
	i = 0;
	while (!(pixels[I] > 2.0 || pixels[I] < -2.0
		|| pixels[R] > 2.0 || pixels[I] < -2.0) && i < ptrs->max_iter)
	{
		temp = pixels[R];
		pixels[R] = pixels[R] * pixels[R] - pixels[I] * pixels[I];
		pixels[R] += ptrs->cr;
		pixels[I] = 2 * temp * pixels[I] + ptrs->ci;
		i++;
	}
	color = ptrs->palete[(i + ptrs->max_iter % ptrs->max_iter % PALETTE_SIZE)].value;
	if (i == ptrs->max_iter)
		my_mlx_pixel_put(ptrs->data, x, y, 0);
	else
		my_mlx_pixel_put(ptrs->data, x, y, color);
}