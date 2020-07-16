/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <jemendy@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:23:25 by jemendy           #+#    #+#             */
/*   Updated: 2018/01/14 15:43:36 by jemdndy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int freez1, int freez2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	s = ft_strncat(s, s1, ft_strlen(s1));
	s = ft_strncat(s, s2, ft_strlen(s2));
	(freez1 > 0) ? free(s1) : 0;
	(freez2 > 0) ? free(s2) : 0;
	return (s);
}

char	*readone(char *bufr, int fd)
{
	char	shot[BUFF_SIZE + 1];
	int		lec;

	lec = read(fd, shot, BUFF_SIZE);
	shot[lec] = '\0';
	if (lec == 0)
	{
		ft_strclr(bufr);
		return (NULL);
	}
	bufr = ft_strjoin("", shot);
	return (bufr);
}

char	*handle_end(char *bufr, int choice)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while ((bufr[i]) && (bufr[i] != '\n'))
		i++;
	if (choice == 1)
	{
		str = ft_strnew(i);
		while ((bufr[j]) && (bufr[j] != '\n'))
		{
			str[j] = bufr[j];
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	str = ft_strnew(ft_strlen(bufr) - (i++));
	while (bufr[i])
		str[j++] = bufr[i++];
	free(bufr);
	return (str);
}

int		breakchecks(char *str)
{
	unsigned long i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_strchr(str, '\n') != NULL)
		return (1);
	while (i < BUFF_SIZE)
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bufr = "\0";

	if (fd < 0 || !line || read(fd, bufr, 0) == -1)
		return (-1);
	*line = ft_strnew(0);
	while (1)
	{
		if ((bufr != NULL) && (bufr[0] != '\0') &&
			((ft_strchr(bufr, '\n') == NULL) || breakchecks(bufr) == 0))
			*line = ft_strjoin_free(*line, bufr, 1, 1);
		else if ((bufr != NULL) && (breakchecks(bufr) == 1))
			break ;
		if ((bufr = readone(bufr, fd)) == NULL)
			return (ft_strlen(*line) == 0 ? 0 : 1);
		if (breakchecks(bufr) == 1)
			break ;
		*line = ft_strjoin_free(*line, bufr, 1, 1);
		bufr = "\0";
	}
	*line = ft_strjoin_free(*line, handle_end(bufr, 1), 1, 1);
	if (bufr)
		bufr = handle_end(bufr, 0);
	ft_strdel(&bufr);
	return (1);
}
