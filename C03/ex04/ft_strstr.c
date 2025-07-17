/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:47:14 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 16:47:14 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	l;

	l = ft_strlength(to_find);
	if (l == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			j = 0;
			while (str[i + j] == to_find[j] && str[i + j] != '\0' && j < l)
			{
				j++;
			}
			if (j == l)
				return (str + i);
		}
		i++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>

int main()
{
	printf("%s\n",strstr("salut toi 737r", "w"));
	printf("%s\n",ft_strstr("salut toi 737r", "t"));

} */