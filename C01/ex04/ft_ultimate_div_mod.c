/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 17:41:35 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 17:41:35 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/* void	display_digit(int d)
{
	char	c;

	if (d >= 0 && d < 9)
	{
		c = '0' + d;
		write(1, &c, 1);
	}
	else
	{
		write(1, "!", 1);
	}
}
int	main()
{	
	int quinze = 15;
	int sept = 7;
	int	*a = &quinze;
	int *b = &sept;

	ft_ultimate_div_mod(a, b);

	display_digit(*a);
	display_digit(*b);
} */