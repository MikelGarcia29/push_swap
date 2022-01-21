/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushutils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:06:25 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 19:40:14 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

int	*ft_createlist(int *list, t_list *temp, int sizea)
{
	int	cont;

	cont = 0;
	list = (int *) malloc((sizea + 1) * sizeof(int));
	while (temp)
	{
		list[cont] = temp->content;
		temp = temp->next;
		cont++;
	}
	return (list);
}

void	ft_mainmoves(t_list	**heada, t_list **headb, t_content *value)
{
	int	cont;

	if (value->sizea == 3)
		ft_smallmoves(heada, value);
	else if (value->sizea > 7)
		ft_moves(heada, headb, value);
	else if (value->sizea < 8 && value->sizea > 3)
		ft_mediummove(heada, headb, value);
	else
	{
		if (value->sizea == 2)
		{
			cont = (*heada)->next->content;
			if ((*heada)->content > cont)
				ft_swapa(heada);
		}
	}
	ft_freeall(value, heada);
}

void	ft_mediummove2(t_content *value, t_list **heada, int index)
{
	int	b;

	b = ft_lstposition(*heada, value->list[index]);
	if (b <= ft_lstsize(*heada) / 2)
	{
		while (--b)
			ft_rotatea(heada);
	}
	else
	{
		while (b++ <= ft_lstsize(*heada))
			ft_reverserotatea(heada);
	}
}
