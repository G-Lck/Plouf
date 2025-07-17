/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:16:04 by imalva            #+#    #+#             */
/*   Updated: 2025/07/06 21:21:01 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_len(int len)
{
	if (len != 31)
	{
		return (1);
	}
	return (0);
}

int	check_input(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((i % 2 == 0) && !(str[i] >= '1' && str[i] <= '4'))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if ((i % 2 == 1) && (str[i] != ' '))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		len++;
		i++;
	}
	if (check_len(len) == 1)
		return (1);
	return (0);
}
/*int	main(void)
{
	char test[] = "1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 ";
	check_input(test);
	return 0;
}*/
