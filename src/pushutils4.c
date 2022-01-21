/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushutils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:25:00 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/16 19:26:20 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_freeall(t_content *value, t_list **heada)
{
	t_list	*buf;

	free(value->list);
	while (*heada)
	{
		buf = (*heada);
		(*heada) = (*heada)->next;
		free(buf);
	}
	*heada = NULL;
}

int	ft_watchrepeat(t_content *value, int size)
{
	int	x;
	int	y;

	x = 1;
	while (x <= size)
	{
		y = x + 1;
		while (y <= size)
		{
			if (value->list[x] == value->list[y])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_check(int argc, char *argv[])
{
	int	cont;
	int	index;

	cont = 1;
	while (cont < argc)
	{
		index = 0;
		while (argv[cont][index])
		{
			if (ft_isdigit(argv[cont][index]) || argv[cont][index] == ' '
					|| argv[cont][index] == '-' | argv[cont][index] == '+')
				index++;
			else
			{
				write(1, "Error\n", 6);
				return (1);
			}
		}
		cont++;
	}
	return (0);
}
