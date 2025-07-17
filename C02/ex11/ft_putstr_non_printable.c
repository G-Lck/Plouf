/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:12:09 by glucken           #+#    #+#             */
/*   Updated: 2025/07/07 16:38:17 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_char_is_printable(char a)
{
	if (a < 32 || a > 126)
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	change_to_hexa(int nb)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[nb / 16], 1);
	write(1, &base[nb % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]) == 0)
			change_to_hexa(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

/* int	main()
{
	ft_putstr_non_printable("Hello\nHow are you?");
	return(0);
} */