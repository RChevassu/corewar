/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:39:19 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:04:50 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_2;
	const unsigned char	*src_2;

	dest_2 = (unsigned char *)dest;
	src_2 = (unsigned char *)src;
	if (src_2 < dest_2)
	{
		while (n--)
			dest_2[n] = src_2[n];
	}
	else
		ft_memcpy(dest_2, src_2, n);
	return (dest_2);
}
