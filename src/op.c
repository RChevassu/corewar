/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/03/14 18:04:30 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/proto.h"
#include "../libft/includes/ft_printf.h"

t_op g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int	(*g_list_op[16])(t_env *, t_proc *) =
{
	op_live, \
	op_ld, \
	op_st, \
	op_add, \
	op_sub, \
	op_and, \
	op_or, \
	op_xor, \
	op_zjmp, \
	op_ldi, \
	op_sti, \
	op_fork, \
	op_lld, \
	op_lldi, \
	op_lfork, \
	op_aff
};

t_op		*buildtab(void)
{
	t_op	*pt;

	pt = g_op_tab;
	return (pt);
}

void		ft_save_op(t_env *env, t_proc *proc)
{
	int i;

	i = 0;
	if (env->map[proc->pc] > 0 && env->map[proc->pc] < 17)
	{
		while (i < 15)
		{
			proc->save[i] = env->map[(proc->pc + i) & (MEM_SIZE - 1)];
			i++;
		}
		proc->op = env->map[proc->pc & (MEM_SIZE - 1)] - 1;
		proc->cycle = env->op_tab[proc->op].cycles - 1;
	}
	else
	{
		proc->cycle = 0;
		proc->op = -1;
	}
	proc->mv = 0;
}

static int	ft_next_jump(unsigned char octal, int dir_size)
{
	unsigned char	tmp;
	int				total;

	total = 2;
	if ((tmp = (octal & 0b11000000) >> 6) == REG_CODE)
		total += 1;
	else if (tmp == DIR_CODE)
		total += 4 - dir_size * 2;
	else if (tmp == IND_CODE)
		total += 2;
	if ((tmp = (octal & 0b110000) >> 4) == REG_CODE)
		total += 1;
	else if (tmp == DIR_CODE)
		total += 4 - dir_size * 2;
	else if (tmp == IND_CODE)
		total += 2;
	if ((tmp = (octal & 0b1100) >> 2) == REG_CODE)
		total += 1;
	else if (tmp == DIR_CODE)
		total += 4 - dir_size * 2;
	else if (tmp == IND_CODE)
		total += 2;
	return (total);
}

int			ft_exec_op(t_env *env, t_proc *proc)
{
	int i;

	i = 1;
	while (i < 15)
	{
		proc->save[i] = env->map[(proc->pc + i) & (MEM_SIZE - 1)];
		i++;
	}
	if (proc->op == 0)
		proc->jp = 5;
	else if (env->op_tab[proc->op].octal == 0)
		proc->jp = 3;
	else
		proc->jp = ft_next_jump(proc->save[1], env->op_tab[proc->op].dir_size);
	if (!(i = g_list_op[proc->op](env, proc)))
		return (0);
	return (move_pc(proc, proc->jp));
}
