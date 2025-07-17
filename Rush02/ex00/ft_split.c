/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:48:25 by glucken           #+#    #+#             */
/*   Updated: 2025/07/12 20:29:21 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	is_in(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_s(char	*str, char *charset)
{
	int	i;

	i = 0;
	while (!is_in(str[i], charset) && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	if (ft_strlen_s(str, "\0") == 0)
		return (0);
	if (!is_in(str[0], charset))
		count++;
	i = 1;
	while (str[i] != '\0')
	{
		if (is_in(str[i - 1], charset))
		{
			if (!is_in(str[i], charset))
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_copyword(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && !is_in(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		count;
	int		i;

	count = 0;
	split = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!split)
		return NULL;
	i = 0;
	if (ft_strlen_s(str, "\0") == 0)
	{
		split[0] = malloc(sizeof(char) * ft_strlen_s(str, charset) + 1);
		split[0] = '\0';
		return (split);
	}
	while (str[i] != '\0')
	{
		if (!is_in(str[i], charset) && (i == 0 || is_in(str[i - 1], charset)))
		{
			split[count] = malloc (ft_strlen_s(str + i, charset) + 1);
			if(!split[count])
				return NULL;
			split[count] = ft_copyword(split[count], str + i, charset);
			count++;
		}
		i++;
	}
	split[count] = NULL;
	return (split);
}
