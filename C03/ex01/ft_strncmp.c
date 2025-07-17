/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:31:03 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 14:32:18 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* int main()
{
	printf("%d\n", ft_strncmp("abc", "abc", 3));
	printf("%d\n", ft_strncmp("", "", 4));
	printf("%d\n", ft_strncmp("abd", "abc", 2));
	printf("%d\n", ft_strncmp("abc", "abcd", 3));
	printf("%d\n", ft_strncmp("abc", "abcd", 4));
	printf("%d\n", ft_strncmp("abcf", "abcd", 4));
	printf("%d\n", ft_strncmp("wbcf", "abcd", 4));
	return(0);
} */