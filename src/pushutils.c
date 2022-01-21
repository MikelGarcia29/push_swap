/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:47:01 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 18:53:31 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnewnode(int content)
{
	t_list	*newnode;

	newnode = (t_list *) malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

void	ft_fillstacks(t_list **heada, t_list **headb, int argc, char *argv[])
{
	int		cont;
	int		index;
	char	**split;
	t_list	*temp;
	int		a;

	(void) headb;
	a = 0;
	cont = 1;
	while (cont < argc)
	{
		split = ft_split(argv[cont], ' ');
		index = 0;
		while (split[index])
		{
			temp = ft_lstnewnode(ft_atoi(split[index], &a));
			ft_lstadd_back(heada, temp);
			free(split[index]);
			index++;
		}
		free(split);
		cont++;
	}
}

int	ft_orderstacka(t_list *heada, t_content *value)
{
	int	cont;

	cont = 1;
	while (heada)
	{
		if (heada->content != value->list[cont])
			return (0);
		heada = heada->next;
		cont++;
	}
	return (1);
}

int	ft_lstposition(t_list *heada, int value)
{
	int	cont;

	cont = 1;
	while (heada)
	{
		if (heada->content == value)
			return (cont);
		cont++;
		heada = heada->next;
	}
	return (cont);
}

int	ft_mediumnum(int *temp, int size, t_content *value)
{
	int	change;
	int	count;
	int	pos;

	count = 1;
	while (count < size + 1)
	{
		pos = count + 1;
		while (pos < size + 1)
		{
			if (temp[count] > temp[pos])
			{
				change = temp[count];
				temp[count] = temp[pos];
				temp[pos] = change;
			}
			pos++;
		}
		count++;
	}
	value->small = temp[1];
	return (temp[size / 2]);
}
