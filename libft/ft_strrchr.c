/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:10:56 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:09:29 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char *)str;
	while (i > 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return (s + i);
	return (NULL);
}
