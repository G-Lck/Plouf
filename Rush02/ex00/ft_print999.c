/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print999.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinchon <cpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:46:46 by cpinchon          #+#    #+#             */
/*   Updated: 2025/07/13 20:18:54 by cpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *dest, char *src, int n);

int ft_strlen(char *str);

char **numbers_needed(void);

void ft_putstr(char *str);

int	ft_convert_char(char nb);

void ft_print999(char *nb, char **letters)
{
    int i;
    int unite;
    int len;
    
    i = 0;
    len = ft_strlen(nb);
    if(len > 3)
    {
        write(1, "error\n", 7);
        return;
    }
    if(len == 3)
    {
        if(nb[0] =='1')
            i++;
        else
            ft_putstr(letters[ft_convert_char(nb[0])]);
        ft_putstr(letters[28]);
    
    }
    if(len >= 2)
    {
        i = len -2;
        if(nb[i] == '1')
        {
            unite = ft_convert_char(nb[i+1]);
            ft_putstr(letters[unite+10]);
            return;
        }
        else
        {
            ft_putstr(letters[ft_convert_char(nb[i])+18]);
            i = len -1;
            if(nb[i] != '0')
                ft_putstr(letters[ft_convert_char(nb[i])]);
            return;
        }
    }
    if(len == 1)
    {
        ft_putstr(letters[ft_convert_char(nb[0])]);
        return;
    }
}

/*char **ft_power()
{
    char **power3 = {"1000","1000000","1000000000","1000000000000","1000000000000000","1000000000000000000","1000000000000000000000","1000000000000000000000000","1000000000000000000000000000","1000000000000000000000000000000","1000000000000000000000000000000000","1000000000000000000000000000000000000"};  
    return power3;
}*/

void ft_print3(char *nb, char **letters)
{
    int len;
    int block;
    int i;
    char *dest;
    
    i = 0;
    len = ft_strlen(nb);
    block = len / 3;

    if(len % 3 != 0)
    {
        dest = malloc(sizeof(char)*(len % 3 +1));
        dest = ft_strncpy(dest, nb+i, (len % 3));
        dest[len % 3] = '\0';
        ft_print999(dest, letters);
        free(dest);
        i = i + (len % 3);
    }
    
    while(block > 0)
    {
        dest = malloc((sizeof(char)*3)+1);
        dest = ft_strncpy(dest, nb + i, 3);
        dest[3] = '\0';
        ft_print999(dest, letters);
        free(dest);
        block--;
        i = i + 3;
    }
}

int main()
{
    char nb[] = "19";
    char **letters = numbers_needed();
    //char *letters[] = {"je", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fivteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"};
    // printf("%d", ft_convert_char(nb[0]));
    // printf("%s", letters[6]);
    // printf("%s", letters[ft_convert_char(nb[0])]);
    ft_print3("68", letters);
/*      char *str;

    str = "650123";
    printf("%s\n", str+1);
    printf("%s", str + 2);
    printf("%s", str); */
    
    return 0;
}

