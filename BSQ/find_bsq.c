/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:39 by glucken           #+#    #+#             */
/*   Updated: 2025/07/16 23:40:35 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

int	get_value(int index, int *int_map, t_map smap)
{
	int	n;
	int	diag;
	int	top;
	int	left;

	top = int_map[index - (smap.x)];
	left = int_map[index - 1];
	diag = int_map[index - (smap.x) - 1];
	if (diag <= left && diag <= top)
		n = diag + 1;
	else if (top > left)
		n = left + 1;
	else
		n = top + 1;
	return (n);
}

int	fill_tab(int *int_map, t_map smap)
{
	int	index;
	int	index_max;

	index = smap.x + 1;
	index_max = 0;
	while (index < smap.x * smap.y)
	{
		if (get_x(index, smap) != 0 && int_map[index] != 0)
		{
			int_map[index] = get_value(index, int_map, smap);
			if (int_map[index] > int_map[index_max])
			{
				index_max = index;
			}
		}
		index++;
	}
	return (index_max);
}
