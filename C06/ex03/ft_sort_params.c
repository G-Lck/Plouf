/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:33:00 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 10:33:18 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_sort_param(char *str[], int len)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (i <= len)
	{
		j = 2;
		while (j < len)
		{
			if (ft_strcmp(str[j], str[j - 1]) < 0)
			{
				copy = str[j - 1];
				str[j - 1] = str[j];
				str[j] = copy;
			}
			j++;
		}
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	int		i;

	argv = ft_sort_param(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
