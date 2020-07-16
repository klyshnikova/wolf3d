/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:02:56 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/25 14:02:57 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*q;

	q = (t_list *)malloc(sizeof(t_list));
	if (q == NULL)
		return (NULL);
	if (!content)
	{
		q->content_size = 0;
		q->content = NULL;
	}
	else
	{
		if (!(q->content = (malloc(content_size))))
		{
			free(q);
			return (NULL);
		}
		ft_memcpy(q->content, content, content_size);
		q->content_size = content_size;
	}
	q->next = NULL;
	return (q);
}
