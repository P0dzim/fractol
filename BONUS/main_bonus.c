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
static int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(int argc, char **argv)
{
	t_vars	ptrs;
	t_data	frame;

	if (argc != 2)
		return (print_options());
	if (!ft_strncmp(argv[1], "Mandelbrot", 10))
	{
		ptrs.frac = 'm';
		ptrs.iter = mandelbrot_interation;
	}
	else if (!ft_strncmp(argv[1], "Julia", 10))
	{
		ptrs.frac = 'j';
		ptrs.iter = julia_interation;
	}
	else if (!ft_strncmp(argv[1], "Burning-Ship", 10))
	{
		ptrs.frac = 'b';
		ptrs.iter = bsf_interation;
	}
	else
		return (print_options());
	init_window(&frame, &ptrs);
	return (0);
}

static int	print_options(void)
{
	write(2, "Mandelbrot\nJulia\nBurning-Ship\n", 30);
	return (1);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (((unsigned char)s1[index] || (unsigned char)s2[index]) && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}
