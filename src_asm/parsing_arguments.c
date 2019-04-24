/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:38:56 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:52:43 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_value(t_data *data, int start, int type, int *value)
{
	int i;
	int temp;

	if (type < 5)
		temp = ft_atoi(data->file + start);
	else
	{
		i = 0;
		while (ft_strchr(LABEL_CHARS, data->file[start + i]))
			i++;
		if ((temp = ft_get_label_index(data, data->labels, start, i)) == -1)
			return (0);
	}
	if ((type & 8) && ((type & 2 && data->line.dir_size) || (type & 4)))
		temp = ((short)temp) - data->op_index;
	else if (type & 8)
		temp = temp - data->op_index;
	else if (type & 4)
		temp = (short)temp;
	else if ((type & 2) && data->line.dir_size)
		temp = (short)temp;
	else if (type & 1)
		temp = (char)temp;
	*value = temp;
	return (1);
}

int		ft_parse_arguments(t_data *data, int start, int type)
{
	int i;

	if (type < 5)
		while (ft_isdigit(data->file[start]) == 0 && data->file[start] != '-')
			start++;
	else
		while (ft_strchr(LABEL_CHARS, data->file[start]) == 0)
			start++;
	if (!get_value(data, start, type, &i))
		return (0);
	if ((type & 2) && data->line.dir_size == 0)
	{
		data->values[data->index++] = (i & 0xFF000000) >> 24;
		data->values[data->index++] = (i & 0x00FF0000) >> 16;
	}
	if (type & 2 || type & 4)
		data->values[data->index++] = (i & 0xFF00) >> 8;
	data->values[data->index++] = i & 0x00FF;
	while (data->file[start] != SEPARATOR_CHAR && data->file[start] != '\n')
		start++;
	return (start);
}
