/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:24:38 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 16:52:23 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
		fact = ft_recursive_factorial(nb - 1) * nb;
	return (fact);
}

/* #include <stdio.h>

int main()
{
	printf("%s", "factorial: ");
	printf("%d", ft_recursive_factorial(1));
	return(0);
} */