/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:28:36 by vess              #+#    #+#             */
/*   Updated: 2021/11/30 23:13:15 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = 0;
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}	
	dest[i] = 0;
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char * ft_strleft(char *buf, int *ret)
{

  int i ;

  i = 0;

  char *dest;

  while (buf && buf[i] && buf[i] != '\n')
    i++;
  dest = malloc(i + 1);
  if (!dest)
    return (NULL);
  if (ft_strchr(buf,'\n') != 0)
    *ret = 1;
  i = 0;
  while (buf && buf[i] && buf[i] != '\n')
  {
    dest[i] = buf[i];
    i++;
  }
  dest[i] = 0;
  return (dest);
}

char * ft_strright(char *buf)
{

  int i;
  int j;
  char *dest;

  i = 0;
  while (buf && buf[i] && buf[i] != '\n')
    i++;
  dest = malloc(sizeof(char) *(ft_strlen(buf) - i + 1));
  if (!dest)
    return (NULL);
j = 0;
while (buf && buf[i])
  dest[j++] = buf[++i]; // On incremente avant apres le /n
dest[j] = 0;
return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}

