/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinchon <cpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:13:42 by glucken           #+#    #+#             */
/*   Updated: 2025/07/13 13:17:32 by cpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
int		count_words(char *str, char *charset);

char	*read_original_dict(void)
{
	int		fd;
	int		sz;
	char	*str;

	str = (char *)malloc(sizeof(char) * 690 + 1);
	if (!str)
		return (NULL);
	fd = open("numbers.dict", O_RDONLY);
	sz = read(fd, str, 690);
	str[sz] = '\0';
	return (str);
}

char	*row_numbers(char *str)
{
	int		i;
	int		j;
	char	*row_numbers;

	row_numbers = (char *)malloc(sizeof(char) * 691);
	if (!row_numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ':')
		{
			row_numbers[j] = str[i];
			j++;
		}
		i++;
	}
	row_numbers[j] = '\0';
	return (row_numbers);
}

char	**numbers_needed(void)
{
	char	*str_original_file;
	char	*str_row_numbers;
	char	**tab_numbers;

	str_original_file = read_original_dict();
	str_row_numbers = row_numbers(str_original_file);
	free(str_original_file);
	tab_numbers = ft_split(str_row_numbers, ":");
	free(str_row_numbers);
	return (tab_numbers);
}

 /*int main()
{
	 char **str3;
	 str3 = numbers_needed();
	 free(str3);
	return(0);
} */