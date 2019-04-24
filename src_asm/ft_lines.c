/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:39:25 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:49:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_findend(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '\n' && str[i] != ';' && str[i] != '#')
		i++;
	return (i);
}

int	next_line(char *str, int line_end)
{
	if (str[line_end] == '#')
	{
		while (str[line_end] != 0 && str[line_end] != '\n')
			line_end++;
	}
	if (!str[line_end])
		return (line_end);
	if (str[line_end] == '\n' || str[line_end] == ';')
		return (line_end + 1);
	return (0);
}

int	ft_checkline(char *str, int start, int end)
{
	while (start != end)
	{
		if (str[start] != ' ' && str[start] != '\t')
			return (1);
		start++;
	}
	return (0);
}
