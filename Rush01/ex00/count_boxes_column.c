/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   count_boxes_column.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: imalva <marvin@42.fr>                         +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/06 16:31:21 by imalva         #+#    #+#                */
/*   Updated: 2025/07/06 20:32:42 by imalva         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	count_boxes_column(int tab[4][4], int column)
{
	int	i;
	int	heighest;
	int	count;

	i = 0;
	heighest = tab[0][column];
	count = 1;
	while (i < 3)
	{
		if (heighest < tab[i + 1][column])
		{
			heighest = tab[i + 1][column];
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}
/*int	main(void)
{
	int test[4][4] = {	{1, 4, 3, 2},
						{2, 3, 1, 4},
						{3, 2, 4, 1},
						{4, 1, 2, 3}};

	printf("%d\n", count_boxes_column(test, 0));
    printf("%d\n", count_boxes_column(test, 1));
    printf("%d\n", count_boxes_column(test, 2));
    printf("%d\n", count_boxes_column(test, 3));
}*/
