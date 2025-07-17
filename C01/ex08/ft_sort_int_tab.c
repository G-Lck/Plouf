/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/06/2025 20:20:52 by glucken           #+#    #+#             */
/*   Updated: 26/06/2025 20:20:52 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
			j++;
		}
		i++;
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

ft_sort_int_tab(tableau, size);
}

 */