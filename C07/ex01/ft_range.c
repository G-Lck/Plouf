/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:42:40 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 17:28:13 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;

	if (min >= max)
		return (0);
	dest = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i + min < max)
	{
		dest[i] = i + min;
		i++;
	}
	return (dest);
}

/* #include <stdio.h>

int main()
{
	printf("%ls", ft_range(3, 6));
	return 0;
} */