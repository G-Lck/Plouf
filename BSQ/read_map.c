/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:47:01 by tzanetti          #+#    #+#             */
/*   Updated: 2025/07/16 23:23:44 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

char	*read_map(char *name)
{
	int		fd;
	int		nb_bytes;
	char	*buffer;
	char	*last_buffer;
	int		i;

	i = 0;
	nb_bytes = 0;
	fd = open(name, O_RDONLY);
	buffer = malloc (2147479551);
	nb_bytes = read(fd, buffer, 2147479551);
	last_buffer = malloc(nb_bytes + 1);
	while (i <= nb_bytes)
	{
		last_buffer[i] = buffer[i];
		i++;
	}
	last_buffer[nb_bytes + 1] = '\0';
	free(buffer);
	close(fd);
	return (last_buffer);
}
