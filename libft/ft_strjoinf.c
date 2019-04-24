/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:39:52 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:27:24 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoinf(char *s1, char *s2, int k)
{
	int		i;
	char	*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc((i + 1) * sizeof(char))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		if (k == 1)
			free(s1);
		else if (k == 2)
			free(s2);
		else if (k == 3)
		{
			free(s1);
			free(s2);
		}
		return (str);
	}
	return (NULL);
}
