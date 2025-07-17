/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29/06/2025 15:41:06 by glucken           #+#    #+#             */
/*   Updated: 29/06/2025 15:41:06 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
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
			if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
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

	c = ft_str_is_alpha("abcdefghijkl");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_alpha("abcghij[`aBCZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_alpha("23adsaffq");

	check = c+'0';
	write(1, &check, 1);
} */