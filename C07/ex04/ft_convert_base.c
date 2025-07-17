/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:22:56 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 17:10:56 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
int		check_base(char *str);

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

long int	size_string_needed(long int nbr_10, char *base_to)
{
	long int	l;
	int			i;

	i = 1;
	l = ft_strlen(base_to);
	while ((nbr_10 / l) != 0)
	{
		nbr_10 = nbr_10 / l;
		i++;
	}
	return (i);
}

char	*recursive_putnbr_base(char *result, char *base_to, int nbr, int i)
{
	int			l;
	long int	long_nbr;

	long_nbr = nbr;
	if (nbr < 0)
	{
		result[0] = '-';
		long_nbr = long_nbr * (-1);
	}
	l = ft_strlen(base_to);
	if (long_nbr >= l)
		recursive_putnbr_base(result, base_to, long_nbr / l, i - 1);
	result[i] = base_to[long_nbr % l];
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nbr_10;
	char		*result;
	long int	size;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	nbr_10 = ft_atoi_base(nbr, base_from);
	size = size_string_needed(nbr_10, base_to);
	if (nbr_10 < 0)
		size = size + 1;
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	result = recursive_putnbr_base(result, base_to, nbr_10, size - 1);
	result[size] = '\0';
	return (result);
}

/* int main(void)
{
	printf("hop! %s\n",ft_convert_base("-0", "0123456789", "ab"));
} */