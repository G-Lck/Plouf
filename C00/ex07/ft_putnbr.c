/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 10:37:55 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 10:37:55 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_digit(int d);

void	display_digit(int d)
{
	char	c;

	if (d >= 0 && d < 9)
	{
		c = '0' + d;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 12);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb <= 9)
	{
		display_digit(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

/* int		main(void)
{
	int		nb;
	nb = 23;
	display_digit(23);
	ft_putnbr(-123);
	return(0);

} */