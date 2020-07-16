/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <jemnedy@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:23:25 by jemendy           #+#    #+#             */
/*   Updated: 2020/01/14 15:43:23 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);
char	*ft_strjoin_free(char *s1, char *s2, int freez1, int freez2);
char	*readone(char *bufr, int fd);
char	*handle_end(char *bufr, int choice);
int		breakchecks(char *str);
#endif
