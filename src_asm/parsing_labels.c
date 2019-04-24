/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:14:10 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:51:48 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/includes/ft_printf.h"

static	int	ft_error_first(t_data *data, int l)
{
	ft_lstdel(&data->labels, ft_free_labs);
	ft_strdel(&data->file);
	ft_printf("Syntax error line [%d]\n", l);
	return (0);
}

static	int	ft_parseline_first(t_data *data, int start, int end, int l)
{
	int i;
	int t;

	if ((start = ft_getlabel(data, start, l)) < 0)
		return (0);
	if ((start = ft_getop(data, start)) < 0)
		return ((start == -1) ? 1 : ft_error_first(data, l));
	data->index += (1 + data->line.octal);
	i = 0;
	while (i < data->line.arg_num)
	{
		if (!(data->line.param_type[i] & (t = ft_gettype(data, start, end, i))))
			return (ft_error_first(data, l));
		if (t == 1)
			data->index++;
		else if (t == 2 || t == 10)
			data->index += (data->line.dir_size ? 2 : 4);
		else if (t == 4 || t == 12)
			data->index += 2;
		i++;
		start++;
		while (start < end && data->file[start] != ',')
			start++;
	}
	return (data->file[start] == ',' ? ft_error_first(data, l) : 1);
}

int			ft_parse_labels(t_data *data, int start)
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
			if (!(ft_parseline_first(data, start, end, l)))
				return (0);
		start = next_line(data->file, end);
		if (data->file[start - 1] == '\n')
			l++;
	}
	return (1);
}
