/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:30:24 by vess              #+#    #+#             */
/*   Updated: 2021/11/30 23:21:25 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "get_next_line.h"

int	get_next_line(int fd, char **line) //1, 0, -1
{
	int ret;
	char buf[BUFFER_SIZE + 1];
	static char *str = NULL;
	char *tmp;

	ret = BUFFER_SIZE;
	if(fd < 0 || fd > 1023 || !line || BUFFER_SIZE < 0)
		return(-1); // On retourne une erreur
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE); // Reqd retourne le nombre d'octet
		if (ret == -1)
			return (-1);
		buf[ret] = '\0'; // on ajoute le 0 a la fin de la string
		tmp = str;
		str = (ft_strjoin(tmp, buf));
		free(tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	*line = ft_strleft(str, &ret);
	tmp = str;
	str = ft_strright(tmp);
	free(tmp);
	/*
	if (ret == 0 && (*str)[0] == 0)
	{
		free(str);
		*str = NULL;
	}
	*/
	return (ret);
}

int main ()
{
	char *line = NULL;
	int fd;
	int ret;

	fd = open("text.txt", O_RDONLY);
	while ( ret != 0)
	{
		printf("%s\n", line);
		ret = get_next_line(fd, &line);
	}
	return (0);
}
