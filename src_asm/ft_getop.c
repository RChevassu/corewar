/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:34:40 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:53:00 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op_asm	g_opasm_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{{0}, 0, {0}, 0, 0, {0}, 0, 0}
};

int			ft_getop(t_data *data, int start)
{
	int	i;
	int	len;

	data->line = g_opasm_tab[16];
	while (ft_isspace(data->file[start]))
		start++;
	if (data->file[start] == '\n' || data->file[start] == COMMENT_CHAR)
		return (-1);
	i = 0;
	while (i != 16)
	{
		len = ft_strlen(g_opasm_tab[i].name);
		if (ft_strncmp(data->file + start, g_opasm_tab[i].name, len) == 0
			&& ft_isspace(data->file[start + len]) == 1)
		{
			data->line = g_opasm_tab[i];
			return (start + len);
		}
		i++;
	}
	return (-2);
}

int			ft_gettype(t_data *data, int start, int end, int i)
{
	while (ft_isspace(data->file[start]) == 1 && start < end)
		start++;
	if (start == end)
		return (0);
	if (i != 0 && data->file[start] != SEPARATOR_CHAR)
		return (0);
	if (i != 0)
	{
		start++;
		while (ft_isspace(data->file[start]) == 1 && start < end)
			start++;
		if (start == end)
			return (0);
	}
	if (data->file[start] == DIRECT_CHAR)
		return (ft_isdir(data, start + 1, end));
	if (data->file[start] == 'r' && ft_isreg(data, start + 1, end))
		return (T_REG);
	return (ft_isind(data, start, end));
}
