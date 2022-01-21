/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:44:38 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/07 19:51:24 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_last(int *a)
{
	*a = 1;
	return (0);
}

int	ft_atoi(const char *str, int *a)
{
	int		cont;
	int		neg;
	long	reg;

	neg = 1;
	cont = 0;
	while (str[cont] == ' ' || (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	reg = 0;
	while (str[cont])
	{
		reg = str[cont] - '0' + reg * 10;
		if (!ft_isdigit(str[cont]) || reg * neg > 2147483647
			|| reg * neg < -2147483648)
			return (ft_last(a));
		cont++;
	}
	return (reg * neg);
}
