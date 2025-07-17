/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:25:18 by tzanetti          #+#    #+#             */
/*   Updated: 2025/07/16 23:40:13 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int		get_column(char *str);
int		ft_strlen(char *str);
char	*read_map(char *name);
int		ft_atoi(char *str);
int		until_next_line(char *str);
int		is_num(char a);
int		is_printable(char a);
int		check_first_line(char *map);
int		len_first_line(char *map);
void	ft_putstr(char *str);
char	*ft_strjoin2(char *str1, char *str2);
char	*ft_strcat(char *dest, char *src);

typedef struct s_map
{
	int		x;
	int		y;
	char	empty;
	char	block;
	char	full;
}	t_map;

t_map	struct_map(char *str);
t_map	null_map(void);
int		check_all_map(char *map);
int		*get_int_map(char *map, t_map smap);
int		get_x(int index, t_map smap);
int		get_y(int index, t_map smap);
int		get_value(int index, int *int_map, t_map smap);
int		fill_tab(int *int_map, t_map smap);
char	*put_array(int *int_map, int index_max, t_map smap);

#endif
