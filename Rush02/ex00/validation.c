/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karrive <karrive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:23:12 by karrive           #+#    #+#             */
/*   Updated: 2025/07/13 08:14:53 by karrive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_only_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int i = 0;

	if (!str || !str[0])
		return (0);

	if (ft_strlen(str) > 37)
		return (0);

	while (str[i] == '0' && str[i + 1])
		i++;

	if (!is_only_digits(str + i))
		return (0);

	return (1);
}
