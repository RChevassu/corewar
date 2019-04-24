/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:21:57 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:52:39 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/includes/ft_printf.h"

static	int	ft_error_second(t_data *data, int l)
{
	ft_lstdel(&data->labels, ft_free_labs);
	ft_strdel(&data->file);
	ft_strdel(&data->values);
	ft_printf("Syntax error line [%d]\n", l);
	return (0);
}

static int	ft_skiplabel(t_data *data, int start)
{
	int i;

	i = 0;
	while (ft_isspace(data->file[start]))
		start++;
	while (ft_strchr(LABEL_CHARS, data->file[start + i]))
		i++;
	if (data->file[start + i] != LABEL_CHAR)
		return (start);
	else
		return (start + i + 1);
}

static	int	ft_parseline_second(t_data *data, int start, int end, int l)
{
	int i;
	int type;

	start = ft_skiplabel(data, start);
	if ((start = ft_getop(data, start)) < 0)
		return (1);
	data->op_index = data->index;
	data->values[data->index++] = data->line.hexa;
	if (data->line.octal)
		data->values[data->index++] = 0;
	i = 0;
	while (i < data->line.arg_num)
	{
		type = ft_gettype(data, start, end, i);
		if (data->line.octal)
			ft_set_octal(data, data->line.param_type[i] & type, i);
		if (!(start = ft_parse_arguments(data, start, type)))
			return (ft_error_second(data, l));
		i++;
	}
	return (1);
}

int			ft_parse_code(t_data *data, int start)
{
	int	end;
	int	ok;
	int	l;

	data->index = 0;
	l = 0;
	while (data->file[start])
	{
		end = ft_findend(data->file, start);
		ok = ft_checkline(data->file, start, end);
		if (ok)
			if (!(ft_parseline_second(data, start, end, l)))
				return (0);
		start = next_line(data->file, end);
		if (data->file[start - 1] == '\n')
			l++;
	}
	return (1);
}
