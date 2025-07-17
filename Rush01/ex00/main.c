/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:05:52 by glucken           #+#    #+#             */
/*   Updated: 2025/07/06 21:57:29 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		recursion(int clues[4][4], int answer[4][4], int r, int c);
int		check_input(char *str);
void	parse_argv(char *str, int clues[4][4]);
void	display_answer(int answer[4][4]);
int		is_valid(int clues[4][4], int answer[4][4], int r, int c);
void	create_empty_array(int answer[4][4]);

int	main(int argc, char **argv)
{
	int	clues[4][4];
	int	answer[4][4];

	create_empty_array(answer);
	if (argc != 2 || check_input(argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_argv(argv[1], clues);
	recursion(clues, answer, 0, 0);
	display_answer(answer);
	return (0);
}

void	create_empty_array(int answer[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			answer[i][j] = 0;
			j++;
		}
		i++;
	}
}
