/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:05:57 by tzanetti          #+#    #+#             */
/*   Updated: 2025/07/16 23:22:57 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

t_map	null_map(void)
{
	t_map	map;

	map.x = 0;
	map.y = 0;
	map.empty = '\0';
	map.block = '\0';
	map.full = '\0';
	return (map);
}

t_map	struct_map(char *str)
{
	t_map	map;
	int		i;
	int		len_line;
	char	*nba;

	len_line = len_first_line(str);
	nba = malloc(sizeof(char) * (len_line - 2));
	if (!nba)
		return (null_map());
	i = 0;
	while (i < len_line - 3)
	{
		nba[i] = str[i];
		i++;
	}
	nba[i] = '\0';
	map.x = get_column(str);
	map.y = ft_atoi(nba);
	free(nba);
	map.empty = str[len_line - 3];
	map.block = str[len_line - 2];
	map.full = str[len_line - 1];
	return (map);
}
