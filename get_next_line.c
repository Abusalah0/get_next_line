/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:35:46 by abdsalah          #+#    #+#             */
/*   Updated: 2024/09/04 17:35:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **global_buffer, char *read_buffer)
{
	free(*global_buffer);
	*global_buffer = NULL;
	free(read_buffer);
	return (NULL);
}

char	*ft_read_into_buffer(char **global_buffer, int fd)
{
	int		read_value;
	char	*read_buffer;
	char	*temp_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (ft_free(*global_buffer, read_buffer));
	while (!ft_strchr(*global_buffer, '\n'))
	{
		read_value = read(fd, read_buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (ft_free(global_buffer, read_buffer));
		if (read_value == 0)
		{
			if (read_buffer[0] == '\0')
				return (NULL);
			break ;
		}
		temp_buffer = ft_strjoin(*global_buffer, read_buffer);
		if (!temp_buffer)
			return (ft_free(*global_buffer, read_buffer));
		free(global_buffer);
		*global_buffer = temp_buffer;
	}
	return (global_buffer);
}

char	*extract_line(char **global_buffer)
{
	char	*pos;
	char	*str;
	int		offset;

	pos = ft_strchr(*global_buffer, '\n');
	offset = pos - global_buffer + 1;
	str = malloc(offset);
	if (!str)
		return (ft_free(*global_buffer, NULL));
	str = ft_strncpy(str, *global_buffer, offset);
	*global_buffer += offset;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*global_buffer = NULL;
	char		*str;

	if (fd == -1)
		return (NULL);
	if (!global_buffer)
	{
		global_buffer = ft_strdup("");
		if (!global_buffer)
			return (NULL);
	}
	if (!ft_read_into_buffer(&global_buffer, fd))
		return (NULL);
	str = extract_line(&global_buffer);
	if (!str)
		return (ft_free(&global_buffer, NULL));

	return (str);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	printf ("%s\n", )
}
