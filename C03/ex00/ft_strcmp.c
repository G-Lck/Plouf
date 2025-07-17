/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:55:55 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 13:03:37 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* int main()
{
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", ft_strcmp("", "abc"));
	printf("%d\n", ft_strcmp("abc", ""));
	printf("%d\n", ft_strcmp("ab", "abc"));
	printf("%d\n", ft_strcmp("abc", "ab"));
	printf("%d\n", ft_strcmp("acc", "abc"));
	return(0);
} */