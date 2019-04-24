/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:54:54 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:33:56 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	size_t i;

	i = 0;
	while (source[i] && i < num)
	{
		destination[i] = source[i];
		i++;
	}
	while (i < num)
	{
		destination[i] = '\0';
		i++;
	}
	return (destination);
}
