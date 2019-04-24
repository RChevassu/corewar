/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:12:14 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:54:29 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/asm.h"

int			ft_isreg(t_data *data, int start, int end)
{
	if (!(ft_isdigit(data->file[start])))
		return (0);
	start++;
	if (ft_isspace(data->file[start]) || start == end
		|| data->file[start] == SEPARATOR_CHAR)
		return (1);
	if (data->file[start - 1] != '1')
		return (0);
	if (ft_isdigit(data->file[start]) != 1)
		return (0);
	if (data->file[start] > '6')
		return (0);
	start++;
	if (ft_isspace(data->file[start]) || data->file[start] == SEPARATOR_CHAR
		|| start == end)
		return (1);
	return (0);
}

static int	ft_isdirbis(t_data *data, int start, int end)
{
	int tmp;

	if (data->file[start] == '-')
		start++;
	tmp = start;
	while (ft_isdigit(data->file[start]))
		start++;
	if ((ft_isspace(data->file[start]) ||
		data->file[start] == SEPARATOR_CHAR || start == end) && start != tmp)
		return (T_DIR);
	return (0);
}

int			ft_isdir(t_data *data, int start, int end)
{
	int ret;
	int tmp;

	ret = 0;
	if (data->file[start] == LABEL_CHAR)
	{
		ret += T_LAB;
		start++;
		if (ft_isspace(data->file[start]) || start == end
			|| data->file[start] == SEPARATOR_CHAR)
			return (0);
	}
	if (ret != 0)
	{
		tmp = start;
		while (ft_strchr(LABEL_CHARS, data->file[start]))
			start++;
		if ((ft_isspace(data->file[start])
			|| data->file[start] == SEPARATOR_CHAR || start == end)
				&& start != tmp)
			return (T_DIR + ret);
	}
	else
		return (ft_isdirbis(data, start, end));
	return (0);
}

static int	ft_isindbis(t_data *data, int start, int end)
{
	int tmp;

	if (data->file[start] == '-')
		start++;
	tmp = start;
	while (ft_isdigit(data->file[start]))
		start++;
	if ((ft_isspace(data->file[start]) || data->file[start] == SEPARATOR_CHAR
		|| start == end) && start != tmp)
		return (T_IND);
	return (0);
}

int			ft_isind(t_data *data, int start, int end)
{
	int ret;
	int tmp;

	ret = 0;
	if (data->file[start] == LABEL_CHAR)
	{
		ret += T_LAB;
		start++;
		if (ft_isspace(data->file[start]) || start == end
			|| data->file[start] == SEPARATOR_CHAR)
			return (0);
	}
	if (ret != 0)
	{
		tmp = start;
		while (ft_strchr(LABEL_CHARS, data->file[start]))
			start++;
		if ((ft_isspace(data->file[start])
			|| data->file[start] == SEPARATOR_CHAR || start == end)
			&& start != tmp)
			return (T_IND + ret);
	}
	else
		return (ft_isindbis(data, start, end));
	return (0);
}
