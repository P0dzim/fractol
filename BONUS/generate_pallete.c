/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_pallete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:59:08 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/15 12:59:09 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	generate_pallete(t_vars *ptrs)
{
	int	i;
	int	id;
	t_pallete *palette;

	i = 0;
	ptrs->palete_id = (ptrs->palete_id + 1) % MAX_SCHEMES;
	id = ptrs->palete_id;
	palette = ptrs->palete;
	while (i < PALETTE_SIZE)
	{
		palette[i].r = (unsigned char)(sin(0.024 * i + id) * 127 + 128);
		palette[i].g = (unsigned char)(sin(0.024 * i + id + 2) * 127 + 128);
		palette[i].b = (unsigned char)(sin(0.024 * i + id + 4) * 127 + 128);
		palette[i].a = 0;
		i++;
	}
}
