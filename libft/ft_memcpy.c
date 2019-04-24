/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:07:52 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:33:21 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*s;

	i = 0;
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
