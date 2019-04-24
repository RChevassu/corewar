/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:30:24 by jlemahie          #+#    #+#             */
/*   Updated: 2019/01/22 11:36:35 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_jump(char *str, int i)
{
	if (str == NULL)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '#')
	{
		if (str[i] == '#')
		{
			while (str[i] != '\n' && str[i] != 0)
				i++;
		}
		i++;
	}
	if (str[i] == 0)
		return (-1);
	return (i);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_blank(char *str, int i)
{
	if (str == NULL)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

void	ft_set_octal(t_data *data, int type, int index)
{
	int temp;

	if (type == 1)
		temp = 1;
	else if (type == 2)
		temp = 2;
	else
		temp = 3;
	temp = temp << ((3 - index) * 2);
	data->values[data->op_index + 1] += temp;
}
