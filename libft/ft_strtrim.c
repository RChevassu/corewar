/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 08:45:57 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:27:56 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	ft_countspaces(char const *s, int *i, int *j)
{
	*i = 0;
	while (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t')
		*i += 1;
	*j = ft_strlen(s) - 1;
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		*j -= 1;
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s)
	{
		ft_countspaces(s, &i, &j);
		if (i <= j)
			str = (char *)malloc(sizeof(char) * (j - i + 2));
		else
			str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		k = 0;
		while (i <= j)
		{
			str[k] = s[i];
			i++;
			k++;
		}
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
