/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:12:41 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 16:48:00 by glucken          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 0)
	{
		return (ft_find_next_prime(nb + 1));
	}
	return (nb);
}

/* #include <stdio.h>

int main()
{
	printf("%s", "next prime is: \n");
	printf("%d  \n", ft_find_next_prime(-1));
	printf("%d  \n", ft_find_next_prime(0));
	printf("%d  \n", ft_find_next_prime(1));
	printf("%d  \n", ft_find_next_prime(2));
	printf("%d  \n", ft_find_next_prime(3));
	printf("%d  \n", ft_find_next_prime(4));
	printf("%d  \n", ft_find_next_prime(1990));
	printf("%d  \n", ft_find_next_prime(2025));
	return(0);
} */