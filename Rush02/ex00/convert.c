/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karrive <karrive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:27:42 by karrive           #+#    #+#             */
/*   Updated: 2025/07/13 08:14:30 by karrive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*power_of_1000(int power)
{
	char	*result;
	int		i;
	char	*temp;

	result = ft_strdup("1");
	i = 0;
	while (i < power)
	{
		temp = multiply_by_1000(result);
		free(result);
		result = temp;
		i++;
	}
	return (result);
}

char	*multiply_by_1000(char *number)
{
	int		len;
	char	*result;

	len = ft_strlen(number);
	result = malloc(len + 4);
	if (!result)
		return (NULL);
	ft_strcpy(result, number);
	ft_strcat(result, "000");
	return (result);
}

char	*get_scale_name(int group_index)
{
	static char *scale_names[] = {
		"",
		"thousand",
		"million",
		"billion",
		"trillion",
		"quadrillion",
		"quintillion",
		"sextillion",
		"septillion",
		"octillion",
		"nonillion",
		"decillion",
		"undecillion"};
	if (group_index >= 0 && group_index < 13)
		return (scale_names[group_index]);
	return (NULL);
}

char	*get_scale_word(t_dict *dict, int scale)
{
	char	*scale_str;
	char	*result;

	scale_str = power_of_1000(scale);
	result = find_in_dict(dict, scale_str);
	free(scale_str);
	return (result);
}

char	*convert_hundreds(t_dict *dict, int num)
{
	char	*result;
	int		hundreds;
	int		remainder;
	char	*hun_str;
	char	*hun_word;
	char	*hundred_word;
	char	*rem_str;
	char	*rem_word;
	int		tens;
	int		units;
	char	*tens_str;
	char	*tens_word;
	char	*units_str;
	char	*units_word;

	result = malloc(1000);
	if (!result)
		return (NULL);
	result[0] = '\0';
	hundreds = num / 100;
	remainder = num % 100;
	if (hundreds > 0)
	{
		hun_str = ft_itoa(hundreds);
		hun_word = find_in_dict(dict, hun_str);
		free(hun_str);
		if (!hun_word)
		{
			free(result);
			return (NULL);
		}
		ft_strcat(result, hun_word);
		ft_strcat(result, " ");
		hundred_word = find_in_dict(dict, "100");
		if (!hundred_word)
		{
			free(result);
			return (NULL);
		}
		ft_strcat(result, hundred_word);
		if (remainder > 0)
			ft_strcat(result, " ");
	}
	if (remainder > 0)
	{
		rem_str = ft_itoa(remainder);
		rem_word = find_in_dict(dict, rem_str);
		if (rem_word)
		{
			ft_strcat(result, rem_word);
		}
		else
		{
			tens = remainder / 10;
			units = remainder % 10;
			if (tens > 0)
			{
				tens_str = ft_itoa(tens * 10);
				tens_word = find_in_dict(dict, tens_str);
				free(tens_str);
				if (!tens_word)
				{
					free(rem_str);
					free(result);
					return (NULL);
				}
				ft_strcat(result, tens_word);
				if (units > 0)
					ft_strcat(result, " ");
			}
			if (units > 0)
			{
				units_str = ft_itoa(units);
				units_word = find_in_dict(dict, units_str);
				free(units_str);
				if (!units_word)
				{
					free(rem_str);
					free(result);
					return (NULL);
				}
				ft_strcat(result, units_word);
			}
		}
		free(rem_str);
	}
	return (result);
}

char	*remove_leading_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	return (str + i);
}

char	*convert_to_words(t_dict *dict, char *number_str)
{
	char	*clean_number;
	int		len;
	char	*result;
	char	*zero_word;
	int		group_count;
	int		pos;
	int		first_group;
	int		start;
	int		group_len;
		char group_str[4];
	int		i;
	int		group_num;
	char	*group_words;
	char	*scale_word;
	char	*temp_result;

	clean_number = remove_leading_zeros(number_str);
	len = ft_strlen(clean_number);
	result = malloc(50000);
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (len == 1 && clean_number[0] == '0')
	{
		zero_word = find_in_dict(dict, "0");
		if (zero_word)
		{
			ft_strcpy(result, zero_word);
			return (result);
		}
		free(result);
		return (NULL);
	}
	group_count = 0;
	pos = len;
	first_group = 1;
	while (pos > 0)
	{
		start = (pos - 3 > 0) ? pos - 3 : 0;
		group_len = pos - start;
		i = 0;
		while (i < group_len)
		{
			group_str[i] = clean_number[start + i];
			i++;
		}
		group_str[i] = '\0';
		group_num = ft_atoi(group_str);
		if (group_num > 0)
		{
			group_words = convert_hundreds(dict, group_num);
			if (!group_words)
			{
				free(result);
				return (NULL);
			}
			scale_word = NULL;
			if (group_count > 0)
			{
				scale_word = get_scale_word(dict, group_count);
				if (!scale_word)
				{
					free(group_words);
					free(result);
					return (NULL);
				}
			}
			temp_result = malloc(50000);
			if (!temp_result)
			{
				free(group_words);
				free(result);
				return (NULL);
			}
			ft_strcpy(temp_result, group_words);
			if (scale_word)
			{
				ft_strcat(temp_result, " ");
				ft_strcat(temp_result, scale_word);
			}
			if (!first_group)
			{
				ft_strcat(temp_result, " ");
				ft_strcat(temp_result, result);
			}
			free(result);
			result = temp_result;
			first_group = 0;
			free(group_words);
		}
		pos -= 3;
		group_count++;
		if (group_count >= 13)
			break ;
	}
	return (result);
}

char	*convert_number(char *dict_path, char *number_str)
{
	t_dict *dict = parse_dictionary(dict_path);
	if (!dict)
		return (NULL);

	char *result = convert_to_words(dict, number_str);

	free_dictionary(dict);
	return (result);
}
