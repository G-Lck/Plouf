/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:44:43 by glucken           #+#    #+#             */
/*   Updated: 2025/06/26 12:44:43 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	beautiful_print(char x1, char x2, char x3);

void	beautiful_print(char x1, char x2, char x3)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	if (x1 < x2 && x2 < x3)
	{
		write(1, &x1, 1);
		write(1, &x2, 1);
		write(1, &x3, 1);
		if (x1 != '7' || x2 != '8' || x3 != '9')
		{
			write(1, &comma, 1);
			write (1, &space, 1);
		}
	}
}

void	ft_print_comb(void)
{
	char	x1;
	char	x2;
	char	x3;

	x1 = '0';
	x2 = '1';
	x3 = '2';
	while (x1 <= '7')
	{
		x2 = '0';
		while (x2 <= '8')
		{
			x3 = '0';
			while (x3 <= '9')
			{
				beautiful_print(x1, x2, x3);
				x3++;
			}
			x2++;
		}
		x1++;
	}
}

/* void	ft_print_comb_str(void)
{

	char	comma;
	char	space;
	char	x[] = "012";

	comma = ',';
	space = ' ';

	while (x[0] <= '7')
	{
		x[1] = '0';
		while (x[1] <= '8')
		{
			x[2] = '0';
			while (x[2] <='9')
			{
				if (x[0] < x[1] && x[1] < x[2] )
				{
					write(1, &x[0], 3);

					if ( x[0] != '7' || x[1] != '8' || x[2] != '9')
					{
						write(1, &comma, 1);
						write (1, &space, 1);
					}
				}
				x[2]++;
			}
			x[1]++;
		}
		x[0]++;
	}
} */

/*
int	main()
{
	ft_print_comb_str();

	return(0);
}
*/