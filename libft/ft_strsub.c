/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:30:16 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:10:19 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	if (s)
	{
		sub = malloc((len + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		i = 0;
		while (i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
