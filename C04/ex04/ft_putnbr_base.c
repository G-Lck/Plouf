/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:39:17 by glucken           #+#    #+#             */
/*   Updated: 2025/07/03 15:59:59 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			l;
	long int	long_nbr;

	long_nbr = nbr;
	if (check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		long_nbr = long_nbr * (-1);
	}
	l = ft_strlen(base);
	if (long_nbr < l)
	{
		ft_putchar(base[long_nbr]);
	}
	else
	{
		ft_putnbr_base(long_nbr / l, base);
		ft_putnbr_base(long_nbr % l, base);
	}
}

/* int	main()
{
	ft_putnbr_base(-2147483648, "01");
	return(0);
} */