/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   count_boxes_row.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: imalva <marvin@42.fr>                         +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/06 15:30:01 by imalva         #+#    #+#                */
/*   Updated: 2025/07/06 21:01:03 by aseuret        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	count_boxes_row(int tab[4][4], int row)
{
	int	j;
	int	heighest;
	int	count;

	heighest = tab[row][0];
	count = 1;
	j = 0;
	while (j < 3)
	{
		if (heighest < tab[row][j + 1])
		{
			heighest = tab[row][j + 1];
			count++;
			j++;
		}
		else
		{
			j++;
		}
	}
	return (count);
}
/*int	main(void)
{
	int tab[4][4] =	{{4, 3, 2, 1},
				     {3, 4, 1, 1},
					 {3, 1, 4, 2},
				     {1, 3, 2, 4}};
	printf("%d\n", count_boxes_row(tab, 0));
	printf("%d\n", count_boxes_row(tab, 1));
	printf("%d\n", count_boxes_row(tab, 2));
	printf("%d\n", count_boxes_row(tab, 3));


	return 0;
}*/
