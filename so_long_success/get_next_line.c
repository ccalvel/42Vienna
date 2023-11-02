/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:59:37 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/27 14:46:18 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*alloc_line(char **line)
{
	*line = (char *)malloc(1);
	if (!*line)
	{
		return (NULL);
	}
	*line[0] = '\0';
	return (*line);
}

char	*error_no_line(char *line, int ret)
{
	if (ret < 0)
	{
		free(line);
		return (NULL);
	}
	if (ret == 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	buf;
	int		ret;
	char	*line;
	int		i;
	char	*new_line;

	if (!alloc_line(&line))
		return (NULL);
	i = 0;
	ret = read(fd, &buf, 1);
	while (ret > 0 && buf != '\n')
	{
		new_line = (char *)malloc(i + 2);
		if (!new_line)
			return (NULL);
		ft_memcpy(new_line, line, i);
		new_line[i++] = buf;
		new_line[i] = '\0';
		free(line);
		line = new_line;
		ret = read(fd, &buf, 1);
	}
	return (error_no_line(line, ret));
}
