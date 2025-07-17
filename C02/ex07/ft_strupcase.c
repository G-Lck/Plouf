/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:44:41 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 17:45:37 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	i;
	int	diff;

	i = 0;
	diff = 'A' - 'a';
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + diff;
		i++;
	}
	return (str);
}

/* int	main(void)
{
	int c;
	char	check;

	c = ft_strupcase("abcdefghijkl");

	check = c+'0';
	write(1, &check, 1);

		c = ft_strupcase("abcghij[`aBCZ");

	check = c+'0';
	write(1, &check, 1);

		c = ft_strupcase("23adsaffq");

	check = c+'0';
	write(1, &check, 1);
} */