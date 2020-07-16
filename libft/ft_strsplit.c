/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:10:24 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/24 16:00:50 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word);
}

static size_t	ft_words_len(char const *s, char c, size_t j)
{
	size_t	len;

	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		len++;
		j++;
	}
	return (len);
}

static char		**ft_free(char **res)
{
	int		i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	word;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	word = ft_count_words(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	while (i < word && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		len = ft_words_len(s, c, j);
		if (!(res[i++] = ft_strsub(s, j, len)))
			return (ft_free(res));
		j = j + len;
	}
	res[i] = NULL;
	return (res);
}
