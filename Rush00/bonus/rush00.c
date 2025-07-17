/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   Rush00.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: aallensp <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/06/28 15:04:38 by aallensp       #+#    #+#                */
/*   Updated: 2025/06/29 18:45:11 by aallensp       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	print_char_if(int l, int c, int x, int y)

{
	if ((l == 1 && c == 1) || (l == y && c == 1))
		ft_putchar('o');
	else if ((l == 1 && c == x) || (l == y && c == x))
		ft_putchar('o');
	else if (l == y || l == 1)
		ft_putchar('-');
	else if (c == x || c == 1)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	error_message(void)
{
	write(1, "You are kindly requested tu put a strict positif number\n", 56);
}

void	rush(int x, int y)

{
	int	l;
	int	c;

	l = 1;
	c = 1;
	if (x < 1 || y < 1)
		error_message ();
	{
		while (l <= y)
		{
			while (c <= x)
			{
				print_char_if(l, c, x, y);
				c++;
			}
			l++;
			ft_putchar ('\n');
			c = 1;
		}
	}
}
