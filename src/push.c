/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:45:48 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/16 19:27:58 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_moves(t_list **heada, t_list **headb, t_content *value)
{
	int	index;
	int	group;
	int	x;
	int	change;

	group = ft_groups(value);
	x = 1;
	change = 0;
	ft_fillvalues(*heada, *headb, value);
	index = 1;
	while (value->sizea > 1)
	{
		if (value->firsta < value->list[x + group]
			&& value->firsta >= value->list[x])
			change = ft_move3(heada, headb, change);
		else
		{
			index = ft_searchvalue(value->list[x + group],
					value->list[x], value, *heada);
			ft_move1(heada, headb, value, index);
		}
		ft_move2(&change, group, &x, value);
		ft_fillvalues(*heada, *headb, value);
	}
	ft_move4(heada, headb, value);
}

void	ft_frombtoa(t_list **heada, t_list **headb, t_content *value)
{
	int	cont;
	int	index;

	cont = 0;
	index = value->sizeb;
	while (*headb)
	{
		ft_frombtoa2(heada, headb, value, index);
		ft_pusha(heada, headb);
		ft_fillvalues(*heada, *headb, value);
		index--;
	}
}

int	ft_searchvalue(int x, int y, t_content *value, t_list *heada)
{
	int		cont;
	t_list	*temp;
	int		*list;

	list = NULL;
	list = ft_createlist(list, heada, value->sizea);
	cont = 0;
	temp = heada;
	while (cont++ < value->sizea)
	{
		if (x > list[cont] && y <= list[cont])
		{
			free(list);
			return (cont);
		}
		if (x > list[value->sizea - cont - 1]
			&& y <= list[value->sizea - cont - 1])
		{
			free(list);
			return (value->sizea - cont - 1);
		}
	}
	free(list);
	return (0);
}

int	ft_fillmedium(char **argv, int argc, t_content *value, int size)
{
	int		cont;
	int		index;
	char	**split;
	int		a;

	cont = 1;
	a = 1;
	value->list = (int *) malloc((size + 1) * sizeof(int));
	while (cont < argc)
	{
		split = ft_split(argv[cont], ' ');
		index = 0;
		while (split[index])
		{
			value->list[a] = ft_atoi(split[index], &value->error);
			a++;
			free(split[index]);
			index++;
		}
		free(split);
		cont++;
	}
	value->sizea = size;
	value->sizeb = 0;
	return (ft_mediumnum(value->list, size, value));
}

int	main(int argc, char *argv[])
{
	t_list		*heada;
	t_list		*headb;
	t_content	value;	

	value.error = 0;
	if (ft_check(argc, argv) || argc == 1)
		return (0);
	heada = NULL;
	headb = NULL;
	ft_fillstacks(&heada, &headb, argc, argv);
	value.medium = ft_fillmedium(argv, argc, &value, ft_lstsize(heada));
	if (value.error || ft_watchrepeat(&value, value.sizea))
	{
		ft_freeall(&value, &heada);
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_orderstacka2(heada, &value))
	{
		ft_freeall(&value, &heada);
		return (0);
	}
	ft_fillvalues(heada, headb, &value);
	ft_mainmoves(&heada, &headb, &value);
}
