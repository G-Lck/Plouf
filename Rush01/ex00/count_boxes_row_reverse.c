/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   count_boxes_row_reverse.c                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: imalva <marvin@42.fr>                         +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/06 15:31:58 by imalva         #+#    #+#                */
/*   Updated: 2025/07/06 20:55:57 by aseuret        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	count_boxes_row_reverse(int tab[4][4], int row)
{
	int	j;
	int	heighest;
	int	count;

	count = 1;
	heighest = tab[row][3];
	j = 3;
	while (j > 0)
	{
		if (heighest < tab[row][j - 1])
		{
			heighest = tab[row][j - 1];
			count++;
			j--;
		}
		else
		{
			j--;
		}
	}
	return (count);
}
/*int	main(void)
{
	int tab[4][4] = {	{3, 4, 1, 2},
						{4, 1, 2, 3},
						{1, 2, 3, 4},
						{2, 3, 4, 1}};
	printf("%d\n", count_boxes_row_reverse(tab, 0));
	printf("%d\n", count_boxes_row_reverse(tab, 1));
	printf("%d\n", count_boxes_row_reverse(tab, 2));
	printf("%d", count_boxes_row_reverse(tab, 3));
	return 0;
}*/
