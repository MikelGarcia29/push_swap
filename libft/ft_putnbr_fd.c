/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:35:06 by mikgarci          #+#    #+#             */
/*   Updated: 2021/06/07 19:42:37 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_long(int nb, int fd)
{
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb <= 2147483647 || nb >= -2147483648)
	{
		if (nb == -2147483648)
		{
			ft_putnbr_fd(nb / 10, fd);
			write(fd, "8", 1);
		}
		else if (nb < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-nb, fd);
		}	
		else
			ft_long(nb, fd);
	}
}
