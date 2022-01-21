/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushUtils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:56:02 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/05 19:20:49 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_frombtoa2(t_list **heada, t_list **headb,
		t_content *value, int index)
{
	int	position;

	position = ft_lstposition(*headb, value->list[index]);
	if (position <= value->sizeb / 2)
	{
		while (value->firstb != value->list[index])
		{
			ft_rotateb(headb);
			ft_fillvalues(*heada, *headb, value);
		}
	}	
	else
	{
		position = value->sizeb - position + 1;
		while (value->firstb != value->list[index])
		{
			ft_reverserotateb(headb);
			ft_fillvalues(*heada, *headb, value);
		}
	}
}

void	ft_move1(t_list **heada, t_list **headb, t_content *value, int index)
{
	if (index <= value->sizea / 2)
	{
		while (index-- > 0)
		{
			ft_rotatea(heada);
			ft_fillvalues(*heada, *headb, value);
		}
	}
	else
	{
		index = value->sizea - index;
		while (index-- > 0)
		{
			ft_reverserotatea(heada);
			ft_fillvalues(*heada, *headb, value);
		}
	}
}

void	ft_move2(int *change, int group, int *x, t_content *value)
{
	if (*change == group)
	{
		*change = 0;
		*x = group + *x;
		if (*x + group >= value->sizea + value->sizeb)
			*x = value->sizea + value->sizeb - group;
	}
}

int	ft_move3(t_list **heada, t_list **headb, int change)
{
	ft_pushb(heada, headb);
	return (change + 1);
}

void	ft_move4(t_list **heada, t_list **headb, t_content *value)
{
	ft_pushb(heada, headb);
	ft_fillvalues(*heada, *headb, value);
	ft_frombtoa(heada, headb, value);
}
