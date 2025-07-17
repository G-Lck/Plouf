/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rush03.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: aallensp <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/06/29 15:18:57 by aallensp       #+#    #+#                */
/*   Updated: 2025/06/29 18:45:42 by aallensp       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	print_char_if(int l, int c, int x, int y)

{
	if ((l == 1 && c == 1) || (l == y && c == 1))
		ft_putchar('A');
	else if ((l == 1 && c == x) || (l == y && c == x))
		ft_putchar('C');
	else if (c == 1 || c == x || l == 1 || l == y)
		ft_putchar('B');
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
