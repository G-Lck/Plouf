/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinchon <cpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:03:40 by cpinchon          #+#    #+#             */
/*   Updated: 2025/07/13 18:36:02 by cpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**numbers_needed(void);
char *ft_strncpy(char *dest, char *src, int n);
char **find_letters(char*str, char **numbers, char **letters, int j);
char **find_numbers(char *str, char **numbers,char **letters, int j);
char	*read_original_dict(void);


int finish_string(char *str)
{
    int i;

    i = 0;

    while(str[i] != '\n' && str[i] != '\0')
    {
    
        if(!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            return 0; // on a pas terminer la string
        i++;
    }
    return 1;
}

char **find_numbers(char *str, char **numbers,char **letters, int j)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(numbers[j] != NULL)
    {
        while(numbers[j][i] = str[i] && numbers[j][i] != '\0')
        {
            i++;
        }
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            letters = find_letters( str+i, numbers, letters, j);
        }
    }
    return letters;
}

char **find_letters( char*str, char **numbers, char **letters, int j)
{
    int i;
    int len;
    char *letters_j;

    i = 0;
    len = 0;
    while(str[i] != ':'&& str[i] != '\n' && str[i] != '\0')
    {
        i++;
    }
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }
    while(finish_string(str+i))
    {
        len++;
        i++;
    }
    letters_j = malloc(sizeof (char)*len +1);
    ft_strncpy(letters_j, str, len);
    return letters_j;
}

char **ft_fill_letters(char *str, char **numbers, char **letters)
{
    int i;
    int j;
    
    int nb;
    char res;

    i = 0;
    j = 0;
    while(str[i] != '\0')
    {
        i++;
        while(str[i] == '\n')
        {
            i++;
        }
        while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        {
            i++;
        }
        if(str[i] >= '0' && str[i] <= '9')
        {
            while(numbers[j] != NULL)
            {
                while(numbers[j][i] = str[i] && numbers[j][i] != '\0')
                {
                    i++;
                }
                if(!(str[i] >= '0' && str[i] <= '9'))
                {
                    letters = find_letters( str+i, numbers, letters, j);
                }
            }
                letters = find_numbers(str, numbers, letters); 
                }
        i++;
    }
    return(letters);
}

/*int main()
{
    char **letters;
    char **numbers;
    char *str;

    str = read_original_dict();

    numbers = numbers_needed();

    letters = (char**)malloc(sizeof(char*) * 40 + 1);
    letters[41] = NULL;
    letters = find_letters(str, numbers, letters, 10);
    free(letters);
    free(numbers);
    return (0);
    
}*/