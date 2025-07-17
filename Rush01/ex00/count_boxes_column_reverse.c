/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   count_boxes_column_reverse.c                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: imalva <marvin@42.fr>                         +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/07/06 16:31:06 by imalva         #+#    #+#                */
/*   Updated: 2025/07/06 20:40:07 by imalva         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	count_boxes_column_reverse(int tab[4][4], int column)
{
	int	i;
	int	heighest;
	int	count;

	i = 3;
	heighest = tab[3][column];
	count = 1;
	while (i > 0)
	{
		if (heighest < tab[i - 1][column])
		{
			heighest = tab[i + 1][column];
			count++;
			i--;
		}
		else
		{
			i--;
		}
	}
	return (count);
}
/*int	main(void)
{
	int	tab[4][4] = {	{3, 4, 1, 2},
						{2, 1, 4, 3},
						{1, 3, 2, 4},
						{4, 2, 3, 1}};
	printf("%d\n", count_boxes_column_reverse(tab, 0));	
    printf("%d\n", count_boxes_column_reverse(tab, 1));
    printf("%d\n", count_boxes_column_reverse(tab, 2));
    printf("%d\n", count_boxes_column_reverse(tab, 3));
	return 0;
}*/
