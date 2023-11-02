/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:33:16 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/29 11:33:18 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[FDC];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = read_line(fd, str[fd]);
	if (!line)
		return (NULL);
	str[fd] = cut (line);
	return (line);
}
/*
int main()
{
	char	*s;
	char	*s1;
	char	*s2;
	int fd1;
	int fd2;
	int fd3; 
	fd1= open("get_texto.txt", O_RDONLY);
	fd2= open("get_texto2.txt", O_RDONLY);
	fd3= open("get_texto3.txt", O_RDONLY);
	
	while(s != NULL)
	{
		s = get_next_line(fd1);
		s1 = get_next_line(fd2);
		s2 = get_next_line(fd3);
		printf("%s", s);
		printf("%s", s1);
		printf("%s", s2);
		
		
		
	}
	printf("\n");
	return 0;	
}
*/
