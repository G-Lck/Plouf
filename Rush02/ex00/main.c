/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karrive <karrive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:37:22 by karrive           #+#    #+#             */
/*   Updated: 2025/07/13 08:14:43 by karrive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char *dict_path;
	char *number_str;
	char *result;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if (argc == 2)
	{
		dict_path = "numbers.dict";
		number_str = argv[1];
	}
	else
	{
		dict_path = argv[1];
		number_str = argv[2];
	}

	if (!is_valid_number(number_str))
	{
		write(1, "Error\n", 6);
		return (1);
	}

	result = convert_number(dict_path, number_str);
	if (!result)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}

	write(1, result, ft_strlen(result));
	write(1, "\n", 1);

	free(result);
	return (0);
}
