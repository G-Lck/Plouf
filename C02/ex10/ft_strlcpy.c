/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:49:04 by glucken           #+#    #+#             */
/*   Updated: 2025/07/07 16:42:07 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (ft_strlen(src));
}

/* #include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char destination[10] = "Hello";
    char *source = "erereretggtrtgtgr";
    unsigned int total_length;

    total_length = ft_strlcpy(destination, source, sizeof(destination));
    printf("copied string: %s\n", destination);
    printf("Total length: %d\n", total_length);

} */