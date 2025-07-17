/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 19:32:09 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 19:32:09 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	t;

	n = 0;
	while (n < size / 2)
	{
		t = tab[n];
		tab[n] = tab[size - n - 1];
		tab[size - n - 1] = t;
		n++;
	}
}

/* 
void	ft_puttab(int *tab, int size)
{
	int	i;
	char	pretty;

	i = 0;
	while (i < size)
	{
		pretty = '0'+ tab[i];
		write(1, &pretty, 1);
		i++;
	}
}

int	 main()
{
int tableau[4];

tableau[0] = 2;

tableau[1] = 1;

tableau[2] = 5;

tableau[3] = 8;

int size;
size = 4;

ft_rev_int_tab(tableau, size);
} */