/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.l                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:06:47 by glucken           #+#    #+#             */
/*   Updated: 2025/06/30 17:16:16 by glucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	i;

	l = ft_strlen(dest);
	if (size <= l)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && l + 1 < size)
	{
		dest[l] = src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}

/* #include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char destination[20] = "Hello, ";
    char *source = "World!";
    unsigned int total_length;

    total_length = ft_strlcat(destination, source, sizeof(destination));
    printf("Concatenated string: %s\n", destination);
    printf("Total length: %du\n", total_length);

	char destination2[7] = "Hello, ";
    char *source2 = "World!";
    unsigned int total_length2;

    total_length2 = ft_strlcat(destination2, source2, sizeof(destination2));
    printf("Concatenated string: %s\n", destination2);
    printf("Total length: %du\n", total_length2);
    return (0);
} */