/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:46:37 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:27:44 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strndup(const char *s1, int j)
{
	int		length;
	int		i;
	char	*str;

	length = ft_strlen(s1);
	if (length > j)
		length = j;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
