/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:30:24 by vess              #+#    #+#             */
/*   Updated: 2021/11/29 00:26:50 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *str)
{
	int		i;
	char	*cpy;
	int		len;

	i = 0;
	cpy = 0;
	len = ft_strlen((char *)str);
	cpy = (char *)malloc (sizeof(*cpy) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

int	get_next_line(int fd, char **line) //1, 0, -1
{
	int byte_was_read;
	char buf[BUFFER_SIZE];

	*line = "\0";
	while ((byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE] = '\0';
		*line = ft_strdup(buf);
	}
	return (0);
}

int main ()
{
	char *line;

	int fd;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

}
