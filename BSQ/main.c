/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:52:47 by tzanetti          #+#    #+#             */
/*   Updated: 2025/07/16 23:42:06 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*return_dest(char *str1, char *str2, int a, int b)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(a + b + 1);
	if (!dest)
		return (NULL);
	while (i++ < a)
	{
		dest[i] = str1[i];
		i++;
	}
	while (i++ < a + b)
	{
		dest[i - 1] = str2[i - 1 - a];
		i++;
	}
	dest[i] = '\0';
	free(str1);
	return (dest);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	i = 0;
	while (str1 && str1[a])
		a++;
	while (str2 && str2[b])
		b++;
	return (return_dest(str1, str2, a, b));
}

void	bsq(char *map)
{
	t_map	smap;
	int		*int_map;
	int		index_max;
	char	*output_map;
	char	*str;

	if (check_all_map(map))
	{
		smap = struct_map(map);
		str = map + ft_strlen(map) - (smap.x + 1) * (smap.y);
		int_map = get_int_map(str, smap);
		free(map);
		index_max = fill_tab(int_map, smap);
		printf("ID MAX %d\n", index_max);
		output_map = put_array(int_map, index_max, smap);
		free(int_map);
		ft_putstr(output_map);
		free(output_map);
	}
}

int	main(int argc, char **argv)
{
	char	*map;
	int		i;

	i = 1;
	if (argc == 1)
	{
		return (0);
	}
	else
	{
		while (i < argc)
		{
			map = read_map(argv[i]);
			printf(" READ : %s\n", map);
			bsq(map);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
