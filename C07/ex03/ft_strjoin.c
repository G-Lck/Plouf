/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:36:14 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 21:39:22 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	len_tot;
	int	i;

	i = 0;
	len_tot = 0;
	while (i < size)
	{
		len_tot = len_tot + ft_strlen(strs[i]);
		i ++;
	}
	len_tot = len_tot + ((size - 1) * ft_strlen(sep));
	return (len_tot);
}

char	*ft_strcat(char	*dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest_tot;

	i = 0;
	if (size == 0)
	{
		dest_tot = malloc(sizeof(char) * 1);
		*dest_tot = '\0';
		return (dest_tot);
	}
	dest_tot = malloc((sizeof(char) * total_len(size, strs, sep)) + 1);
	*dest_tot = '\0';
	while (i < size)
	{
		ft_strcat(dest_tot, strs[i]);
		if (i < size - 1)
			ft_strcat(dest_tot, sep);
		i++;
	}
	dest_tot[total_len(size, strs, sep) + 1] = '\0';
	return (dest_tot);
}

/* int main(void)
{
	char *strs[] = {"Salut", "ca", "va"};
	char *sep = ", ";
	int	size = 3;
	printf("%s\n", ft_strjoin(size, strs, sep));

	char *strs[] = {"Salut", "ca", "va"};
	char *sep = "";
	int	size = 3;
	printf("%s\n", ft_strjoin(size, strs, sep));

	char *strs[] = {};
	char *sep = "-";
	int	size = 0;
	printf("%s\n", ft_strjoin(size, strs, sep));

	char *strs[] = {"Salut"};
	char *sep = "-";
	int	size = 1;
	printf("%s\n", ft_strjoin(size, strs, sep));

	char *strs[] = {"Salut", "", "va"};
	char *sep = ", ";
	int	size = 3;
	printf("%s\n", ft_strjoin(size, strs, sep));
} */