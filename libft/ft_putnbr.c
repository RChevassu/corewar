/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:06:43 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:05:55 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_putnbr(int nb)
{
	unsigned int nb2;

	if (nb < 0)
	{
		nb2 = nb * (-1);
		ft_putchar('-');
	}
	else
		nb2 = nb;
	if (nb2 > 9)
	{
		ft_putnbr(nb2 / 10);
		ft_putnbr(nb2 % 10);
	}
	else
		ft_putchar('0' + nb2);
}
