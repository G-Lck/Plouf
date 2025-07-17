/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:14:24 by glucken           #+#    #+#             */
/*   Updated: 2025/06/29 20:02:50 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);

int	ft_str_is_alphanum(char s)
{
	if (s >= 'a' && s <= 'z')
		return (0);
	if (s >= 'A' && s <= 'Z')
		return (0);
	if (s >= '0' && s <= '9')
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char s)
{
	if (s >= 'a' && s <= 'z')
		return (0);
	return (1);
}

int	ft_str_is_uppercase(char s)
{
	if (s >= 'A' && s <= 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (ft_str_is_lowercase(str[0]) == 0)
		str[0] = str[0] - 'a' + 'A';
	while (str[i] != '\0')
	{
		if (ft_str_is_alphanum(str[i - 1]) == 1)
		{
			if (ft_str_is_lowercase(str[i]) == 0)
				str[i] = str[i] - 'a' + 'A';
		}
		if (ft_str_is_alphanum(str[i - 1]) == 0)
		{
			if (ft_str_is_uppercase(str[i]) == 0)
				str[i] = str[i] + 'a' - 'A';
		}
		i++;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* int main()
{
	char str[] = "5eci es*7t un 42test";
	char *result;
	result = ft_strcapitalize(str);
	ft_putstr(result);
} */