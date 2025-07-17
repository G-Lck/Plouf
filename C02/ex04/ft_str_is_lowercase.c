/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:38:09 by glucken           #+#    #+#             */
/*   Updated: 2025/06/29 16:38:09 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
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
			if (str[i] < 'a' || str[i] > 'z')
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

	c = ft_str_is_lowercase("abcdefghijkl");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_lowercase("abaBCZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_lowercase("23adsaf*(fq");

	check = c+'0';
	write(1, &check, 1);
} */