/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 16:37:29 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 16:37:39 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
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
	int x = 7;
	int y = 2;

	display_digit(x);
	display_digit(y);

	int v = 10;
	int w = 20;
	int *div = &v;
	int *mod = &w;



 	ft_div_mod(x, y, div, mod);

	display_digit(*div);
	display_digit(*mod);

 	return(0);

}  */
/* pour tester on doit avoir dabord mis le pointeur sur quelque chose,
 sinon on ne peut pas lutiliser */