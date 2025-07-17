/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:52:05 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 21:49:58 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	length = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * length);
	if (!*range)
		return (-1);
	i = 0;
	while (i < length)
	{
		(*range)[i] = min++;
		i++;
	}
	return (i);
}

/* #include <stdio.h>

    int main(){
	int n = 100;
	int *p;
	int **range;

	
	
	p = &n;
	range = &p;

	int min = 10;
	int max = 100;
	
	ft_ultimate_range(range, min, max);

	int i;
	i = 0;
	while (i + min < max)
	{
		printf("%d\n",range[0][i]);
		i++;
	}
	return(0);
} */