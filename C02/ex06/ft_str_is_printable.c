/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29/06/2025 17:00:13 by glucken           #+#    #+#             */
/*   Updated: 29/06/2025 17:00:13 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
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
			if (str[i] < 32 || str[i] > 126)
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

	c = ft_str_is_printable("abcdefghijkl");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_printable("abcghij[`aBCZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_str_is_printable("23adsaffq");

	check = c+'0';
	write(1, &check, 1);
} */