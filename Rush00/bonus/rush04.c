/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:36:16 by glucken           #+#    #+#             */
/*   Updated: 2025/06/29 18:36:16 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	error_message(void)
{
	write(1, "You are kindly requested to enter ", 35);
	write(1, "a strictly positif integer.\n", 28);
	write(1, "Values less than or equal to zero are not allowed.\n", 52);
	write(1, "If you don't know what is an integer, RTFM.\n", 45);
}

void	print_char_if(int l, int c, int x, int y)

{
	if (l == 1 && c == 1)
		ft_putchar('A');
	else if (l == 1 && c == x)
		ft_putchar('C');
	else if (l == y && c == 1)
		ft_putchar('C');
	else if (l == y && c == x)
		ft_putchar('A');
	else if (c == 1 || c == x || l == 1 || l == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	c = 1;
	if (y <= 0 || x <= 0)
		error_message();
	while (l <= y)
	{
		while (c <= x)
		{
			print_char_if(l, c, x, y);
			c++;
		}
		l++;
		ft_putchar('\n');
		c = 1;
	}
}
