/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:15 by imalva            #+#    #+#             */
/*   Updated: 2025/07/06 22:14:32 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_clues(int clues[4][4], int answer[4][4]);
int	count_boxes_column(int tab[4][4], int column);
int	count_boxes_column_reverse(int tab[4][4], int column);
int	count_boxes_row(int tab[4][4], int column);
int	count_boxes_row_reverse(int tab[4][4], int column);

int	check_clues_high(int clues[4][4], int answer[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (clues[i][j] != count_boxes_column(answer, j))
			return (0);
		j++;
	}
	return (1);
}

int	check_clues_bottom(int clues[4][4], int answer[4][4])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < 4)
	{
		if (clues[i][j] != count_boxes_column_reverse(answer, j))
			return (0);
		j++;
	}
	return (1);
}

int	check_clues_left(int clues[4][4], int answer[4][4])
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (j < 4)
	{
		if (clues[i][j] != count_boxes_row(answer, j))
			return (0);
		j++;
	}
	return (1);
}

int	check_clues_right(int clues[4][4], int answer[4][4])
{
	int	i;
	int	j;

	i = 3;
	j = 0;
	while (j < 4)
	{
		if (clues[i][j] != count_boxes_row_reverse(answer, j))
			return (0);
		j++;
	}
	return (1);
}

int	check_clues(int clues[4][4], int answer[4][4])
{
	if (check_clues_high(clues, answer) == 0
		|| check_clues_bottom(clues, answer) == 0
		|| check_clues_left(clues, answer) == 0
		|| check_clues_right(clues, answer) == 0)
		return (0);
	return (1);
}
