/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:43:54 by jcampagn          #+#    #+#             */
/*   Updated: 2021/12/05 11:51:44 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buf;
	int		rd_bytes;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = 0;
		tmp = left_str;
		left_str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

/*
int main ()
{
	char *line = NULL;
	int fd1 = open("text1.txt", O_RDONLY);
	int fd2 = open("text2.txt", O_RDONLY);
	int fd3 = open("text3.txt", O_RDONLY);
	int i;
	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s",i,  line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s",i,  line);
		free(line);	
		line = get_next_line(fd3);
		printf("line [%02d]: %s",i,  line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
