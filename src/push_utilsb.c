/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilsb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:56:22 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 18:55:31 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"
#include <stdlib.h>

void	ft_swapb(t_list **headb)
{
	int		swap1;
	int		swap2;
	t_list	*temp;

	if (ft_lstsize(*headb) < 2)
		return ;
	temp = *headb;
	swap1 = (*headb)->content;
	temp = temp->next;
	swap2 = temp->content;
	temp->content = swap1;
	(*headb)->content = swap2;
	write(1, "sb\n", 3);
}

void	ft_pusha(t_list **heada, t_list **headb)
{
	t_list	*temp;
	t_list	*temp2;

	if (!headb)
		return ;
	temp = ft_lstnewnode((*headb)->content);
	ft_lstadd_front(heada, temp);
	temp2 = *headb;
	*headb = (*headb)->next;
	free(temp2);
	write(1, "pa\n", 3);
}

void	ft_rotateb(t_list **headb)
{
	t_list	*temp;

	if (ft_lstsize(*headb) < 2)
		return ;
	ft_lstadd_back(headb, ft_lstnewnode((*headb)->content));
	temp = *headb;
	*headb = (*headb)->next;
	free(temp);
	write(1, "rb\n", 3);
}

void	ft_reverserotateb(t_list **headb)
{
	t_list	*temp;
	t_list	*new;

	if (ft_lstsize(*headb) < 2)
		return ;
	new = ft_lstlast(*headb);
	ft_lstadd_front(headb, ft_lstnewnode(new->content));
	temp = *headb;
	while ((temp->next)->next)
		temp = (temp)->next;
	free(temp->next);
	temp->next = NULL;
	write(1, "rrb\n", 4);
}
