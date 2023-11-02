/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:33:16 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/29 11:33:18 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		ret;
	char	*tmp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		if (!str)
			str = ft_strdup ("");
		tmp = str;
		str = ft_strjoin (tmp, buffer);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	free (buffer);
	return (str);
}

static char	*cut(char *line)
{
	char	*str;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] != '\n' || line[i + 1] == '\0')
		return (NULL);
	str = ft_substr(line, i + 1, ft_strlen(line)-i);
	if (*str == '\0')
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	line = read_line(fd, str);
	if (!line)
		return (NULL);
	str = cut (line);
	return (line);
}
/*
int main()
{
	int fd;
	fd = open("get_texto.txt", O_RDONLY);
//	get_next_line(fd);
	printf("%s", get_next_line(fd));
//	printf("\n----------------\n");
	printf("%s", get_next_line(fd));
//	printf("\n----------------\n");	
	printf("%s", get_next_line(fd));
//	printf("\n----------------\n");	
	printf("%s", get_next_line(fd));
//	printf("\n----------------\n");	
	printf("%s", get_next_line(fd));
//	printf("\n----------------\n");	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
}
*/
