/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:44:23 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/15 09:44:24 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int		ft_atoi(const char *nptr);
static float	ft_itod(int nbr);

float	ft_atof(char *nptr)
{
	float	nbr;
	int		integer;
	int		decimal;

	nbr = 0.0;
	integer = ft_atoi(nptr);
	decimal = 0;
	while(nptr &&  *nptr != '.')
		nptr++;
	if (*nptr == '.')
		decimal = ft_atoi(nptr + 1);
	nbr = (float)integer + ft_itod(decimal) * (integer >= 0);
	nbr += ft_itod(decimal) * -(integer < 0);
	return (nbr);
}

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static	float ft_itod(int nbr)
{
	int		i;
	float	decimal;

	i = 1;
	while(nbr / i > 0)
		i *= 10;
	decimal = (float)nbr / i;
	return (decimal);
}
