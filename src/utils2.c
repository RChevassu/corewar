/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:54:27 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/14 18:05:15 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/proto.h"

int	ft_is_reg(unsigned char c)
{
	if (c >= 1 && c <= 16)
		return (1);
	return (0);
}

int	get_ind_all(int val, t_env *p, int pc, int size)
{
	int	total;

	total = 0;
	if (size == 2)
	{
		total += p->map[(pc + val + 1) & (MEM_SIZE - 1)];
		total += p->map[(pc + val) & (MEM_SIZE - 1)] * 256;
	}
	else
	{
		total += p->map[(pc + val + 3) & (MEM_SIZE - 1)];
		total += p->map[(pc + val + 2) & (MEM_SIZE - 1)] * 256;
		total += p->map[(pc + val + 1) & (MEM_SIZE - 1)] * 256 * 256;
		total += p->map[(pc + val) & (MEM_SIZE - 1)] * 256 * 256 * 256;
	}
	return (total);
}

int	get_ind(int val, t_env *p, int pc, int size)
{
	return (get_ind_all(val % IDX_MOD, p, pc, size));
}

int	get_arg_len(int argtype)
{
	if (argtype == 1)
		return (1);
	if (argtype == 2)
		return (4);
	if (argtype == 3)
		return (2);
	return (0);
}

int	ft_supp_axo(t_env *p, t_proc *c, int fi)
{
	if (fi == REG_CODE && ft_is_reg(c->save[2]))
		return (c->reg[c->save[2] - 1]);
	else if (fi == DIR_CODE)
		return (argint(c->save, 2, 4));
	else
		return (get_ind(argint(c->save, 2, 2), p, c->pc, 4));
}
