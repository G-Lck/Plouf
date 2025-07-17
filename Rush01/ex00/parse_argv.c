/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:03:46 by imalva            #+#    #+#             */
/*   Updated: 2025/07/06 20:10:19 by aseuret        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

void	parse_argv(char *str, int clues[4][4])
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (*str == ' ')
			{
				str++;
			}
			else
			{
				clues[i][j] = *str - 48;
				str++;
				j++;
			}
		}
		j = 0;
		i++;
	}
}
/*int main()
{
    char test[] = "1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4";
    int arr1[4][4];

    
    parse_argv(test, arr1);
    display_answer(arr1);
    return 0;
}*/
