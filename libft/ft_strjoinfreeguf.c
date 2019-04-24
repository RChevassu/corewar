/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreeguf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:18:36 by gufortel          #+#    #+#             */
/*   Updated: 2019/02/13 19:18:39 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoinfreeguf(char *s1, char *s2, int opt)
{
	char *str;

	str = NULL;
	if (!s1 && s2)
		str = ft_strdup(s2);
	else if (s1 && !s2)
		str = ft_strdup(s1);
	else if (s1 && s2)
		str = ft_strjoin(s1, s2);
	if (opt == 1)
		ft_strdel(&s1);
	if (opt == 2)
		ft_strdel(&s2);
	if (opt == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
