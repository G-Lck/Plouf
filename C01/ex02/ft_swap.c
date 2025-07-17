/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 15:35:01 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 15:35:01 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int*b);

void	ft_swap(int *a, int*b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/* void	display_digit(int d)
{
	char	c;

	if (d >= 0 && d < 9)
	{
		c = '0' + d;
		write(1, &c, 1);
	}
}


int main()
{
	int a = 2;
	int b = 7;

	display_digit(a);
	display_digit(b);

	int *p1 = &a;
	int *p2 = &b;

	ft_swap(p1, p2);

	display_digit(a);
	display_digit(b);
} */