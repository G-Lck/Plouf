/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinchon <cpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:37:51 by cpinchon          #+#    #+#             */
/*   Updated: 2025/07/13 13:12:02 by cpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_find_nb(char *nb)
{
    int i;
    int j;
    char **nbavl;

    i = 0;
    j = 0;;
    /* recuperer les nb
    Gerer le cas du zero*/
    while(nb[i] != '\n')
        i++;
    while (nb[i] == ' ' || (nb[i] >= 9 && nb[i] <= 13))
		++i;
    while(nb[i] >= '1' && nb[i] <= '9')
    {
        j = 0;
        while(j <= 41)
        {
            while(nbavl[j] == nb[i] || nbavl[j] != '\0')
            {
                i++;
                j++;
            }
            if(!(nb[i] >= '0' && nb[i] <= '9'))
            //copier le nom correspondant a lindex j dans un nouveau tableau
          
            // 
        }
        i++;
    }
}