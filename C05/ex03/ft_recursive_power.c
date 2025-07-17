/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:43:01 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 16:51:48 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power >= 1)
		result = ft_recursive_power(nb, power -1) * nb;
	return (result);
}

/* #include <stdio.h>

int main()
{
	printf("%s", "power: ");
	printf("%d", ft_recursive_power(2,3));
	return(0);
} */