/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:31:06 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/19 14:14:41 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	print_options(void);

int	main(int argc, char **argv)
{
	t_vars	ptrs;
	t_data	frame;

	if (argc < 2)
		return (print_options());
	ptrs.scale = 1.0;
	ptrs.mx = 0.0;
	ptrs.my = 0.0;
	ptrs.palete_id = 0;
	ptrs.max_iter = 200;
	ptrs.data = &frame;
	ptrs.frac = 'X';
	if (param_check(argc, argv, &ptrs))
		init_window(&frame, &ptrs);
	else
		return (print_options());
	return (0);
}

int	print_options(void)
{
	write(2, "Mandelbrot\nJulia\njulia-mouse\nBurning-Ship\n", 42);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (((unsigned char)s1[index] || (unsigned char)s2[index]))
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

