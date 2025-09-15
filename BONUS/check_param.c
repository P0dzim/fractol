/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:48:58 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/15 16:49:00 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	check_julia_param(char **argv, t_vars *ptrs);
static int	check_complex(char *acomplex);

int	param_check(int argc, char **argv, t_vars *ptrs)
{
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
		ptrs->iter = mandelbrot_interation;
	else if (!ft_strcmp(argv[1], "Julia") && argc == 4)
		return(check_julia_param(argv, ptrs));
	else if (!ft_strcmp(argv[1], "Burning-Ship") && argc == 2)
		ptrs->iter = bsf_interation;
	else if (!ft_strcmp(argv[1], "julia-mouse") && argc == 2)
	{
		ptrs->frac = 'j';
		ptrs->iter = julia_interation;
	}
	else
		return (0);
	return (1);
}

static int	check_julia_param(char **argv, t_vars *ptrs)
{
	if (!check_complex(argv[2]) && !check_complex(argv[3]))
		return (0);
	ptrs->cr = ft_atof(argv[2]);
	ptrs->ci = ft_atof(argv[3]);
	ptrs->iter = fix_julia_interation;
	return (1);
}

static int	check_complex(char *acomplex)
{
	int	i;

	i = 0;
	if (acomplex[i] == '+' || acomplex[i] == '-')
		i++;
	while (acomplex[i] >= '0' && acomplex[i] <= '9')
		i++;
	if (acomplex[i] == '.')
		i++;
	while (acomplex[i] >= '0' && acomplex[i] <= '9')
		i++;
	if (acomplex[i] == 0)
		return (1);
	return (0);
}