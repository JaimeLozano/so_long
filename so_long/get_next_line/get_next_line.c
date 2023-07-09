/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:12:29 by jlozano-          #+#    #+#             */
/*   Updated: 2023/05/02 13:12:06 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strncpy_gnl(t_buffer *buffer, int fd)
{
	int	i_bytes_readed;
	int	i_bytes_to_copy;

	i_bytes_to_copy = strchr_gnl(buffer->c_array + buffer->ui_index, '\n');
	if (i_bytes_to_copy == 0)
	{
		i_bytes_readed = read(fd, buffer->c_array, BUFFER_SIZE);
		if (i_bytes_readed >= 0)
		{
			buffer->c_array[i_bytes_readed] = '\0';
			buffer->ui_index = 0;
		}
		else
			return (0);
		i_bytes_to_copy = strchr_gnl(buffer->c_array + buffer->ui_index, '\n');
	}
	return (i_bytes_to_copy);
}

char	*strnjoin_gnl(char *s1, t_buffer *buffer, int *i_line_index, int n)
{
	int	i_line_start;

	if (n < 1)
		return (NULL);
	*i_line_index += n;
	s1 = str_realloc(s1, *i_line_index);
	if (n >= *i_line_index)
		i_line_start = 0;
	else
		i_line_start = *i_line_index - n - 1;
	if (s1)
		buffer->ui_index += ft_strncpy(s1 + i_line_start, \
						buffer->c_array + buffer->ui_index, n + 1);
	return (s1);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;
	unsigned int	ui_bytes_to_copy;
	int				i_bytes_readed;
	int				i_line_index;

	i_bytes_readed = BUFFER_SIZE;
	ui_bytes_to_copy = strncpy_gnl(&buffer, fd);
	line = NULL;
	i_line_index = 1;
	while (ui_bytes_to_copy > 0)
	{
		if (ui_bytes_to_copy > 0)
		{
			line = strnjoin_gnl(line, &buffer, &i_line_index, ui_bytes_to_copy);
			if (line == NULL)
				return (NULL);
			if (line[i_line_index - 2] == '\n')
				return (line);
		}
		ui_bytes_to_copy = strncpy_gnl(&buffer, fd);
	}
	if (i_line_index == '\0')
		return (free(line), (char *) NULL);
	return (line);
}
