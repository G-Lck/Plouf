/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:47:05 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 19:07:56 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				enddest;

	enddest = 0;
	while (dest[enddest] != '\0')
	{
		enddest++;
	}
	i = 0;
	while (nb-- && src[i] != '\0')
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
	char example[3];
	example[0]='A';
	printf("%s\n", ft_strncat(example, "abc", 4));


	return(0);
} */