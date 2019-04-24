/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:06:43 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:05:50 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	unsigned int nb2;

	if (nb < 0)
	{
		nb2 = nb * (-1);
		ft_putchar_fd('-', fd);
	}
	else
		nb2 = nb;
	if (nb2 > 9)
	{
		ft_putnbr_fd(nb2 / 10, fd);
		ft_putnbr_fd(nb2 % 10, fd);
	}
	else
		ft_putchar_fd('0' + nb2, fd);
}
