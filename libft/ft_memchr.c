/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:44:46 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:54 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	c2;

	i = 0;
	p = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == c2)
			return (p + i);
		i++;
	}
	return (NULL);
}
