/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilsa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:56:13 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 18:56:28 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"
#include <stdlib.h>

void	ft_swapa(t_list **heada)
{
	int		swap1;
	int		swap2;
	t_list	*temp;

	if (ft_lstsize(*heada) < 2)
		return ;
	temp = *heada;
	swap1 = (*heada)->content;
	temp = temp->next;
	swap2 = temp->content;
	temp->content = swap1;
	(*heada)->content = swap2;
	write(1, "sa\n", 3);
}

void	ft_pushb(t_list **heada, t_list **headb)
{
	t_list	*temp;
	t_list	*temp2;

	if (!heada)
		return ;
	temp = ft_lstnewnode((*heada)->content);
	ft_lstadd_front(headb, temp);
	temp2 = *heada;
	*heada = (*heada)->next;
	free(temp2);
	write(1, "pb\n", 3);
}

void	ft_rotatea(t_list **heada)
{
	t_list	*temp;

	if (ft_lstsize(*heada) < 2)
		return ;
	ft_lstadd_back(heada, ft_lstnewnode((*heada)->content));
	temp = *heada;
	*heada = (*heada)->next;
	free(temp);
	write(1, "ra\n", 3);
}

void	ft_reverserotatea(t_list **heada)
{
	t_list	*temp;
	t_list	*new;

	if (ft_lstsize(*heada) < 2)
		return ;
	new = ft_lstlast(*heada);
	ft_lstadd_front(heada, ft_lstnewnode(new->content));
	temp = *heada;
	while ((temp->next)->next)
		temp = (temp)->next;
	free(temp->next);
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_fillvalues(t_list *heada, t_list *headb, t_content *value)
{
	if (heada)
		(value)->firsta = heada->content;
	if (headb)
		(value)->firstb = headb->content;
	value->sizea = ft_lstsize(heada);
	value->sizeb = ft_lstsize(headb);
}
