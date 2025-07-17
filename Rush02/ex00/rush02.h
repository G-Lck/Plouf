#ifndef RUSH02_H
#define RUSH02_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_NUMBER_LENGTH 40

typedef struct s_dict
{
    char *key;
    char *value;
    struct s_dict *next;
} t_dict;

// Fonctions utilitaires
int     ft_strlen(char *str);
char    *ft_strdup(char *str);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strcat(char *dest, char *src);
int     ft_strcmp(char *s1, char *s2);
int     ft_atoi(char *str);
char    *ft_itoa(int n);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strtrim(char *str);

// Fonctions de validation
int     is_valid_number(char *str);
int     is_only_digits(char *str);

// Fonctions de dictionnaire
t_dict  *parse_dictionary(char *dict_path);
void    free_dictionary(t_dict *dict);
char    *find_in_dict(t_dict *dict, char *key);
t_dict  *create_dict_node(char *key, char *value);
void    add_to_dict(t_dict **dict, t_dict *new_node);

// Fonctions de conversion
char    *convert_number(char *dict_path, char *number_str);
char    *convert_to_words(t_dict *dict, char *number_str);
char    *convert_group(t_dict *dict, char *group);
char    *get_scale_word(t_dict *dict, int scale);
char    *convert_hundreds(t_dict *dict, int num);
char    *get_scale_name(int group_index);
char    *multiply_by_1000(char *number);
int     compare_numbers(char *num1, char *num2);
char    *power_of_1000(int power);

#endif