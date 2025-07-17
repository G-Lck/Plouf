/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:03:47 by glucken           #+#    #+#             */
/*   Updated: 2025/07/06 22:53:22 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursion(int clues[4][4], int answer[4][4], int r, int c);
int	is_valid(int clues[4][4], int answer[4][4], int r, int c);

int	i_loops(int clues[4][4], int answer[4][4], int r, int c)
{
	int	i;

	i = 4;
	while (i != 0)
	{
		answer[r][c] = i;
		if (is_valid(clues, answer, r, c) == 1)
		{
			if (recursion(clues, answer, r + 1, c) == 0)
			{
				return (0);
			}
			answer[r][c] = 0;
		}
		i--;
	}
	return (1);
}

int	recursion(int clues[4][4], int answer[4][4], int r, int c)
{
	if (c == 4)
		return (0);
	else if (r == 4)
		return (recursion(clues, answer, 0, c + 1));
	else if (answer[r][c] != 0)
		return (recursion(clues, answer, r + 1, c));
	else
	{
		if (i_loops(clues, answer, r, c) == 0)
			return (0);
		else
			return (1);
	}
}

/* #include <unistd.h>
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
	char	i;
	char	j;
	char	c;

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


#include <stdio.h>


int main()
{
	int answer[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int clues[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	recursion(clues, answer, 0, 0);
	display_answer(answer);
	return (0);
} 

 */
