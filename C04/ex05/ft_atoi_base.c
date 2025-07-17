/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:55:57 by glucken           #+#    #+#             */
/*   Updated: 2025/07/03 15:51:36 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	where_is_digit(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] != a && base[i] != '\0')
	{
		i++;
	}
	if (i == ft_strlen(base))
		return (-1);
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13))
			return (0);
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

int	erase_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	parite;
	int	nbr;
	int	l;

	i = erase_space(str);
	parite = 1;
	nbr = 0;
	l = ft_strlen(base);
	if (check_base(base) == 0)
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			parite = parite * -1;
		i++;
	}
	while (str[i] != '\0' && where_is_digit(str[i], base) != -1)
	{
		nbr = nbr * l + where_is_digit(str[i], base);
		i++;
	}
	return (nbr * parite);
}

/* #include <stdlib.h>
#include <stdio.h>

int main()
{   
	printf("%d\n", ft_strlen("01"));
	printf("%s", "ma fonction: ");
	printf("%d\n", ft_atoi_base("-01011","01"));
}  */