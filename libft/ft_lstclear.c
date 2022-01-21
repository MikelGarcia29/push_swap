/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:00:34 by mikgarci          #+#    #+#             */
/*   Updated: 2021/06/20 18:45:45 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (*lst)
	{
		while (*lst)
		{
			buf = *lst;
			del((*lst)->content);
			free(*lst);
			(*lst) = buf->next;
		}
		*lst = NULL;
	}
}
