/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:13:06 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:09:14 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnewc(size_t size, char c)
{
	char	*str;
	size_t	i;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
