/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:12:48 by glucken           #+#    #+#             */
/*   Updated: 2025/06/29 16:14:41 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}

/* int	main(void)
{
	int c;
	char	check;

	c = ft_str_is_numeric("1234567890");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_numeric("378((*_))");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_numeric("");

	check = c+'0';
	write(1, &check, 1);
} */