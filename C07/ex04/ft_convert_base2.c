/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:08:57 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 17:11:10 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

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
