/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:54:03 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 16:51:10 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result;

	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else
		result = 1;
	if (index >= 2)
		result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}

/* #include <stdio.h>

int main()
{
	printf("%s", "fibobo: ");
	printf("%d", ft_fibonacci(4));
	return(0);
} */