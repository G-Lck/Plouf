/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:43 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 19:14:43 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	enddest;

	enddest = 0;
	while (dest[enddest] != '\0')
	{
		enddest++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[enddest] = src[i];
		i++;
		enddest++;
	}
	dest[enddest] = '\0';
	return (dest);
}

/* 
int main()
{
	char example[100];
	example[0]='A';
	printf("%s\n", ft_strcat(example, "abc"));


	return(0);
} */