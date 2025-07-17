/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karrive <karrive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:22:54 by karrive           #+#    #+#             */
/*   Updated: 2025/07/13 08:14:25 by karrive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*create_dict_node(char *key, char *value)
{
	t_dict	*node;

	node = malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	return (node);
}

void	add_to_dict(t_dict **dict, t_dict *new_node)
{
	if (!*dict)
	{
		*dict = new_node;
		return ;
	}
	new_node->next = *dict;
	*dict = new_node;
}

char	*find_in_dict(t_dict *dict, char *key)
{
	while (dict)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

void	free_dictionary(t_dict *dict)
{
	t_dict	*temp;

	while (dict)
	{
		temp = dict->next;
		free(dict->key);
		free(dict->value);
		free(dict);
		dict = temp;
	}
}

char	*read_file(char *filename)
{
	int		fd;
	char	*buffer;
	char	*content;
	int		bytes_read;
	int		total_size;
	char	*new_content;

	total_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	content = malloc(1);
	if (!content)
	{
		close(fd);
		return (NULL);
	}
	content[0] = '\0';
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(content);
		close(fd);
		return (NULL);
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		new_content = malloc(total_size + bytes_read + 1);
		if (!new_content)
		{
			free(content);
			free(buffer);
			close(fd);
			return (NULL);
		}
		if (total_size > 0)
			ft_strcpy(new_content, content);
		else
			new_content[0] = '\0';
		ft_strcat(new_content, buffer);
		free(content);
		content = new_content;
		total_size += bytes_read;
	}
	free(buffer);
	close(fd);
	return (content);
}

char	*parse_line(char *line, char **key, char **value)
{
	int		i;
	int		colon_pos;
	char	*temp_key;
	char	*temp_value;

	i = 0;
	colon_pos = -1;
	while (line[i])
	{
		if (line[i] == ':')
		{
			colon_pos = i;
			break ;
		}
		i++;
	}
	if (colon_pos == -1)
		return (NULL);
	temp_key = malloc(colon_pos + 1);
	if (!temp_key)
		return (NULL);
	i = 0;
	while (i < colon_pos)
	{
		temp_key[i] = line[i];
		i++;
	}
	temp_key[i] = '\0';
	*key = ft_strtrim(temp_key);
	free(temp_key);
	temp_value = ft_strdup(line + colon_pos + 1);
	if (!temp_value)
	{
		free(*key);
		return (NULL);
	}
	*value = ft_strtrim(temp_value);
	free(temp_value);
	return ((*key && *value) ? *key : NULL);
}

t_dict	*parse_dictionary(char *dict_path)
{
	char *content = read_file(dict_path);
	if (!content)
		return (NULL);

	t_dict *dict = NULL;
	char *line_start = content;
	int i = 0;

	while (content[i])
	{
		if (content[i] == '\n' || content[i] == '\0')
		{
			content[i] = '\0';

			if (ft_strlen(line_start) > 0)
			{
				char *key, *value;
				if (parse_line(line_start, &key, &value))
				{
					if (is_only_digits(key))
					{
						t_dict *node = create_dict_node(key, value);
						if (node)
							add_to_dict(&dict, node);
					}
					free(key);
					free(value);
				}
			}

			line_start = content + i + 1;
		}
		i++;
	}

	free(content);
	return (dict);
}
