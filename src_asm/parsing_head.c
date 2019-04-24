/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:54:58 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:52:33 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/includes/ft_printf.h"

static	int	ft_error_head(t_data *data, int i)
{
	free(data->file);
	if (i == 1)
		ft_printf("Syntax error : name\n");
	else
		ft_printf("Syntax error : comment\n");
	return (0);
}

static	int	ft_fillname(t_data *data, int i)
{
	int	l;

	l = 0;
	while (data->file[i] != 0 && data->file[i] != '"' && l <= PROG_NAME_LENGTH)
	{
		data->header.prog_name[l] = data->file[i];
		l++;
		i++;
	}
	while (l != PROG_NAME_LENGTH + 2)
	{
		data->header.prog_name[l] = 0;
		l++;
	}
	if (data->file[i] == '"')
		return (i);
	return (0);
}

int			ft_parsename(t_data *data)
{
	int i;
	int l;

	if ((i = ft_jump(data->file, 0)) == -1)
		return (ft_error_head(data, 1));
	if (ft_strncmp(NAME_CMD_STRING, data->file + i,
		l = ft_strlen(NAME_CMD_STRING)) != 0 ||
		ft_isspace(data->file[i + l]) != 1)
		return (ft_error_head(data, 1));
	i = ft_blank(data->file, i + l);
	if (data->file[i] != '"')
		return (ft_error_head(data, 1));
	i++;
	i = ft_fillname(data, i);
	if (i == 0)
		return (ft_error_head(data, 1));
	i = ft_blank(data->file, i + 1);
	if (data->file[i] == '#')
	{
		while (data->file[i] != '\n' && data->file[i] != 0)
			i++;
	}
	if (i == -1 || data->file[i] != '\n')
		return (ft_error_head(data, 1));
	return (i + 1);
}

static	int	ft_fillcomment(t_data *data, int i)
{
	int	l;

	l = 0;
	while (data->file[i] != 0 && data->file[i] != '"' && l <= COMMENT_LENGTH)
	{
		data->header.comment[l] = data->file[i];
		l++;
		i++;
	}
	while (l != COMMENT_LENGTH + 2)
	{
		data->header.comment[l] = 0;
		l++;
	}
	if (data->file[i] == '"')
		return (i);
	return (0);
}

int			ft_parsecomment(t_data *data, int i)
{
	int l;

	if ((i = ft_jump(data->file, i)) == -1)
		return (ft_error_head(data, 2));
	if (ft_strncmp(COMMENT_CMD_STRING, data->file + i,
		l = ft_strlen(COMMENT_CMD_STRING)) != 0 ||
		ft_isspace(data->file[i + l]) != 1)
		return (ft_error_head(data, 2));
	i = ft_blank(data->file, i + l);
	if (data->file[i] != '"')
		return (ft_error_head(data, 2));
	i++;
	i = ft_fillcomment(data, i);
	if (i == 0)
		return (ft_error_head(data, 2));
	i = ft_blank(data->file, i + 1);
	if (data->file[i] == '#')
	{
		while (data->file[i] != '\n' && data->file[i] != 0)
			i++;
	}
	if (i == -1 || data->file[i] != '\n')
		return (ft_error_head(data, 2));
	return (i + 1);
}
