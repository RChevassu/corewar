/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 08:58:51 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:10:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char	*get_word(char const *s, char c, int *i)
{
	char	*str;
	int		k;
	int		l;

	while (s[*i] == c && s[*i])
		*i += 1;
	k = *i;
	while (s[k] != c && s[k])
		k++;
	if (!(str = (char *)malloc(sizeof(char) * (1 + k - *i))))
		return (NULL);
	l = 0;
	while (s[*i] != c && s[*i])
	{
		str[l] = s[*i];
		*i += 1;
		l++;
	}
	str[l] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**tab;
	int		i;
	int		j;

	if (s)
	{
		nb_words = count_words(s, c);
		if (!(tab = (char **)malloc(sizeof(tab) * (nb_words + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (s[i] == c && s[i])
		{
			i++;
		}
		while (j < nb_words && s[i])
		{
			tab[j] = get_word(s, c, &i);
			j++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
