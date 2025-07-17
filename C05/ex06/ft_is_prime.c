/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:59:20 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 16:48:43 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	max;

	i = 2;
	max = nb;
	if (nb <= 1)
		return (0);
	while (i < max)
	{
		if (nb % i == 0)
			return (0);
		i++;
		max = nb / i;
	}
	return (1);
}

/* #include <stdio.h>

int main()
{
	printf("%s", "is prime ? 0=no 1=yes: \n");
	printf("%d  \n", ft_is_prime(-1));
	printf("%d  \n", ft_is_prime(0));
	printf("%d  \n", ft_is_prime(1));
	printf("%d  \n", ft_is_prime(2));
	printf("%d  \n", ft_is_prime(3));
	printf("%d  \n", ft_is_prime(4));
	printf("%d  \n", ft_is_prime(5));
	printf("%d  \n", ft_is_prime(18));
	printf("%d  \n", ft_is_prime(1997));
	return(0);
} */