/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:54:56 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:24 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (p[i] == (unsigned char)c)
			return (p + 1 + i);
		i++;
	}
	return (NULL);
}
