/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:43:56 by glucken           #+#    #+#             */
/*   Updated: 2025/06/26 12:43:56 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int	xint;

	xint = '0';
	while (xint <= '9')
	{
		write(1, &xint, 1);
		xint++;
	}
}

/* int	main()
{
	ft_print_numbers();

	return(0);
}
 */