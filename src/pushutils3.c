/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushutils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:57:31 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 19:40:42 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_smallmoves(t_list **heada, t_content *value)
{
	ft_allposition(*heada, value);
	if (value->lasta < value->seconda && value->firsta < value->lasta)
	{
		ft_reverserotatea(heada);
		ft_swapa(heada);
	}
	else if (value->lasta < value->firsta && value->firsta < value->seconda)
		ft_reverserotatea(heada);
	else if (value->lasta > value->firsta && value->firsta > value->seconda)
		ft_swapa(heada);
	else if (value->lasta < value->firsta && value->lasta > value->seconda)
		ft_rotatea(heada);
	else if (value->lasta < value->firsta && value->lasta < value->seconda)
	{
		ft_swapa(heada);
		ft_reverserotatea(heada);
	}
}

void	ft_allposition(t_list *heada, t_content *value)
{
	if (ft_lstsize(heada) > 2)
	{
		value->firsta = heada->content;
		heada = heada->next;
		value->seconda = heada->content;
		heada = heada->next;
		while (heada->next)
			heada = heada->next;
		value->lasta = heada->content;
	}
	else
	{
		if (heada)
		{
			value->firsta = heada->content;
			heada = heada->next;
			if (heada)
				value->seconda = heada->content;
		}
	}
}

int	ft_groups(t_content *value)
{
	int	cont;

	if (value->sizea >= 150)
		return (value->sizea / 12);
	else
	{
		cont = value->sizea / 6;
		if (cont == 0)
			cont = 1;
	}
	return (cont);
}

void	ft_mediummove(t_list **heada, t_list **headb, t_content *value)
{
	int	index;

	index = 1;
	while (ft_lstsize(*heada) >= 4)
	{
		ft_allposition(*heada, value);
		if (value->list[index] == value->firsta)
		{
			ft_pushb(heada, headb);
			index++;
		}
		else
			ft_mediummove2(value, heada, index);
	}
	ft_smallmoves(heada, value);
	while (ft_lstsize(*headb))
		ft_pusha(heada, headb);
}

int	ft_orderstacka2(t_list *heada, t_content *value)
{
	int	cont;

	(void) value;
	cont = 1;
	while (heada->next)
	{
		if (heada->content > heada->next->content)
			return (0);
		heada = heada->next;
		cont++;
	}
	return (1);
}
