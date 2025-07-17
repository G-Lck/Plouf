/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:45:15 by glucken           #+#    #+#             */
/*   Updated: 2025/06/26 12:45:15 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_print_beautiful(char x1, char x2, char x3, char x4)
{
	write(1, &x1, 1);
	write(1, &x2, 1);
	write(1, " ", 1);
	write(1, &x3, 1);
	write(1, &x4, 1);
	if (x1 != '9' || x2 != '8' || x3 != '9' || x4 != '9')
	{
		write(1, ", ", 2);
	}
}

void	conditions(char x1, char x2, char x3, char x4)
{
	if (x1 < x3)
	{
		ft_print_beautiful(x1, x2, x3, x4);
	}
	if (x1 == x3 && x2 < x4)
	{
		ft_print_beautiful(x1, x2, x3, x4);
	}
	x4++;
}

void	ft_loops(char x1, char x2, char x3, char x4)
{
	while (x1 <= '9')
	{
		x2 = '0';
		while (x2 <= '9')
		{
			x3 = '0';
			x4 = '0';
			while (x3 <= '9')
			{
				x4 = '0';
				while (x4 <= '9')
				{
					conditions(x1, x2, x3, x4);
					x4++;
				}
				x3++;
			}
			x2++;
		}
		x1++;
	}
}

void	ft_print_comb2(void)
{
	char	x1;
	char	x2;
	char	x3;
	char	x4;

	x1 = '0';
	x2 = '0';
	x3 = '0';
	x4 = '0';
	ft_loops(x1, x2, x3, x4);
}

/* 
int	main(void)
{
	ft_print_comb2();
	return (0);
}
 */