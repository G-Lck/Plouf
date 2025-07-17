/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:03:47 by glucken           #+#    #+#             */
/*   Updated: 2025/07/06 21:25:56 by aseuret        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int clues[4][4], int answer[4][4], int r, int c);
int	check_uniqueness(int answer[4][4], int r, int c);
int	check_clues(int clues[4][4], int answer[4][4]);

int	check_uniqueness(int answer[4][4], int r, int c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != c && answer[r][i] == answer[r][c])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (i != r && answer[i][c] == answer[r][c])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(int clues[4][4], int answer[4][4], int r, int c)
{
	if (check_uniqueness(answer, r, c) == 0)
		return (0);
	if (r == 3 && c == 3 && check_clues(clues, answer) == 0)
		return (0);
	return (1);
}
