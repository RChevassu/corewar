/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:06:03 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:52:51 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/includes/ft_printf.h"

void		ft_free_labs(void *content, size_t size_content)
{
	t_label	*lab;

	lab = (t_label*)content;
	ft_strdel(&lab->label);
	free(lab);
	(void)size_content;
}

static	int	ft_error_lab(t_data *data, int l, int err)
{
	ft_lstdel(&data->labels, ft_free_labs);
	ft_strdel(&data->file);
	if (err == -1)
		ft_printf("Syntax error line [%d]\n", l);
	else
		ft_printf("Allocation error\n");
	return (-1);
}

static	int	ft_add_label(t_data *data, int start, int i)
{
	t_label	lab;
	t_list	*new;

	if (!(lab.label = ft_strndup(data->file + start, i)))
		return (0);
	lab.index = data->index;
	if (!(new = ft_lstnew(&lab, sizeof(lab))))
	{
		free(lab.label);
		return (0);
	}
	ft_lstadd(&data->labels, new);
	return (1);
}

int			ft_get_label_index(t_data *data, t_list *lst, int start, int i)
{
	t_label	*lab;
	int		len;

	while (lst)
	{
		lab = (t_label*)lst->content;
		len = ft_strlen(lab->label);
		if (ft_strncmp(data->file + start, lab->label, i) == 0
			&& ft_strncmp(data->file + start, lab->label, len) == 0)
			return (lab->index);
		lst = lst->next;
	}
	return (-1);
}

int			ft_getlabel(t_data *data, int start, int l)
{
	int	i;

	while (data->file[start] == ' ' || data->file[start] == '\t')
		start++;
	i = 0;
	while (ft_strchr(LABEL_CHARS, data->file[start + i]))
		i++;
	if (data->file[start + i] != LABEL_CHAR)
		return (start);
	if (i == 0)
		return (ft_error_lab(data, l, -1));
	if (ft_get_label_index(data, data->labels, start, i) != -1)
		return (start + i + 1);
	if (!(ft_add_label(data, start, i)))
		return (ft_error_lab(data, l, -2));
	return (start + i + 1);
}
