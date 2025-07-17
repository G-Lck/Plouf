/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:26:15 by glucken           #+#    #+#             */
/*   Updated: 2025/07/16 23:22:25 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

char	fill_one_by_one(int *int_map, int i, int index_max, t_map smap)
{
	char	a;

	if (int_map[i] == 0)
		a = smap.block;
	else if (get_x(index_max, smap) - get_x(i, smap) < int_map[index_max]
		&& get_x(index_max, smap) - get_x(i, smap) >= 0
		&& get_y(index_max, smap) - get_y(i, smap) < int_map[index_max]
		&& get_y(index_max, smap) - get_y(i, smap) >= 0)
		a = smap.full;
	else
		a = smap.empty;
	return (a);
}

char	*put_array(int *int_map, int index_max, t_map smap)
{
	int		i;
	int		j;
	char	*output_map;

	output_map = (char *)malloc(sizeof(char) * (smap.x + 1) * (smap.y) + 1);
	if (! output_map)
		return (NULL);
	i = 0;
	j = 0;
	while (i < smap.x * smap.y && j < ((smap.x + 1) * smap.y))
	{
		output_map[j] = fill_one_by_one(int_map, i, index_max, smap);
		j++;
		if (get_x(i, smap) == smap.x - 1 && j < ((smap.x + 1) * smap.y))
		{
			output_map[j] = '\n';
			j++;
		}
		i++;
	}
	output_map[(smap.x + 1) * (smap.y)] = '\0';
	return (output_map);
}
