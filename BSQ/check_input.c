/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:32:08 by glucken           #+#    #+#             */
/*   Updated: 2025/07/16 23:38:30 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

int	check_first_line(char *map)
{
	int	i;
	int	len_line;

	len_line = len_first_line(map);
	if (len_line < 4)
		return (0);
	if (!is_printable(map[len_line - 1]))
		return (0);
	if (!is_printable(map[len_line - 2])
		|| map[len_line - 2] == map[len_line - 1])
		return (0);
	if (!is_printable(map[len_line - 3])
		|| map[len_line - 3] == map[len_line - 1]
		|| map[len_line - 3] == map[len_line - 2])
		return (0);
	i = 0;
	while (i != len_line - 3)
	{
		if (!is_num(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	len_first_line(char *map)
{
	int	i;
	int	len_tot;

	i = 0;
	while (map[i] != '\0')
		i++;
	len_tot = i;
	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	if (len_tot == i)
		return (0);
	return (i);
}

int	check_lines(char *map, t_map struct_map)
{
	int		i;
	int		count_column;
	int		count_row;

	count_row = 0;
	i = until_next_line(map);
	while (map[i] != '\0')
	{
		count_column = 0;
		while (map[i] == struct_map.block
			|| map[i] == struct_map.full
			|| map[i] == struct_map.empty)
		{
			i++;
			count_column++;
		}
		printf("%d\n", count_column);
		if (map[i] != '\n' || count_column != struct_map.x)
			return (0);
		count_row++;
		i++;
	}
	if (count_row != struct_map.y)
		return (0);
	return (1);
}

int	check_all_map(char *map)
{
	t_map	map_struct;

	if (!check_first_line(map))
	{
		ft_putstr("map error");
		return (0);
	}
	map_struct = struct_map(map);
	if (!check_lines(map, map_struct))
	{
		ft_putstr("map error");
		return (0);
	}
	return (1);
}
