/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:39:37 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 14:16:56 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define X_AXIS 720
# define Y_AXIS 720
# define X 0
# define Y 1
# define R 0
# define I 1

typedef struct s_data
{
	void	*frame;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void			*ptr_mlx;
	void			*ptr_win;
	unsigned int	color;
	t_data			*data;
	char			frac;
	int				x;
	int				y;
	float			scale;
	float			my;
	float			mx;
	void			(*iter)(int, int, unsigned int, struct s_vars*);
}					t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(void *p);

int		input_keyboard(int keycode, void *param);
int		mouse_pos(int x, int y, void *p);
void	init_window(t_data *frame, t_vars *ptrs);
int		mouse_zoom(int button, int x, int y, void *p);

void	bsf_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	julia_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	mandelbrot_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	put_fractal(t_vars *ptrs, unsigned int color);

#endif
