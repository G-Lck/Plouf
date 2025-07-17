/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29/06/2025 16:40:04 by glucken           #+#    #+#             */
/*   Updated: 29/06/2025 16:40:04 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
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
			if (str[i] < 'A' || str[i] > 'Z')
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

	c = ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_uppercase("abaBCZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_uppercase("23adsaf*(fq");

	check = c+'0';
	write(1, &check, 1);
} */