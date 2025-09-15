/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:39:37 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 14:16:13 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>

# define X_AXIS 720
# define Y_AXIS 720
# define X 0
# define Y 1
# define R 0
# define I 1
# define ZOOM_SCALE 1.1
# define PALETTE_SIZE 256
# define MAX_SCHEMES 10

typedef struct s_data
{
	void	*frame;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef union u_palette
{
	unsigned int	value;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}	t_palette;

typedef struct s_vars
{
	void			*ptr_mlx;
	void			*ptr_win;
	t_data			*data;
	char			frac;
	int				x;
	int				y;
	float			scale;
	float			my;
	float			mx;
	float			cr;
	float			ci;
	int				palete_id;
	t_palette		palete[PALETTE_SIZE];
	int				max_iter;
	void			(*iter)(int, int, unsigned int, struct s_vars*);
}					t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(void *p);
void	generate_palette(t_vars *ptrs);
float	ft_atof(char *nptr);
int		param_check(int argc, char **argv, t_vars *ptrs);
int		ft_strcmp(const char *s1, const char *s2);

int		input_keyboard(int keycode, void *param);
int		mouse_pos(int x, int y, void *p);
void	init_window(t_data *frame, t_vars *ptrs);
int		mouse_zoom(int button, int x, int y, void *p);

void	bsf_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	julia_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	fix_julia_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	mandelbrot_interation(int x, int y, unsigned int color, t_vars *ptrs);
void	put_fractal(t_vars *ptrs);

#endif
