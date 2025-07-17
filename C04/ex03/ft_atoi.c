/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:19:11 by glucken           #+#    #+#             */
/*   Updated: 2025/07/02 18:07:01 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi(char *str)
{
	int	i;
	int	parite;
	int	nbr;

	i = erase_space(str);
	parite = 1;
	nbr = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			parite = parite * -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbr = nbr * 10 + str[i] - '0';
			i++;
		}
		else
			return (nbr * parite);
	}
	return (nbr * parite);
}

/* #include <stdlib.h>
#include <stdio.h>

int main()
{   
	char x[] = "-12fdd34";
	printf("%s", "atoi: ");
	printf("%d\n", atoi(x));
	printf("%s", "ma fonction: ");
	printf("%d\n", ft_atoi(x));
} */