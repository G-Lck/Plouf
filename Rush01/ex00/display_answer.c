/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:05:49 by imalva            #+#    #+#             */
/*   Updated: 2025/07/06 19:28:20 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int c, int j)
{
	if (j == 3)
	{
		c += 48;
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else
	{
		c += 48;
		write(1, &c, 1);
		write(1, " ", 1);
	}
}

void	display_answer(int answer[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			print(answer[i][j], j);
			j++;
		}
		j = 0;
		i++;
	}
}
/*int main()
{
    int test[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    display_answer(test);

    return 0;
}*/
