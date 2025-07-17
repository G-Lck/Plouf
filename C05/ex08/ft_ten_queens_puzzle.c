/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:28:24 by glucken           #+#    #+#             */
/*   Updated: 2025/07/10 13:20:16 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_ten_queens_puzzle(void);

void	ft_putstr(char	*str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_valid(char *str, int index, int position)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == position
			|| i + str[i] == index + position
			|| i - str[i] == index - position)
			return (0);
		i++;
	}
	return (1);
}

void	fill_of_zero(char *str)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
}

int	recursion(char *str, int index, int *count)
{
	char	position;

	if (index > 9)
	{
		(*count)++;
		str[index] = '\0';
		ft_putstr(str);
		ft_putstr("\n");
		return (0);
	}
	position = '0';
	while (position <= '9')
	{
		if (is_valid(str, index, position))
		{
			str[index] = position;
			if (recursion(str, index + 1, count))
				return (1);
			str[index] = '0';
		}
		position ++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	str[10];
	int		index;
	int		count;

	count = 0;
	fill_of_zero(str);
	index = 0;
	recursion(str, index, &count);
	return (count);
}

/* int	main()
{
	ft_ten_queens_puzzle();
	printf("total:%d",ft_ten_queens_puzzle());
} */