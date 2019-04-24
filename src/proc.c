/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:55:00 by gufortel          #+#    #+#             */
/*   Updated: 2019/03/14 17:51:00 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/proto.h"

int		clone_proc(t_env *env, t_proc *proc, int pos)
{
	int i;

	i = 0;
	if (!(add_new_proc(env)))
		return (0);
	env->process->carry = proc->carry;
	env->process->pc = pos & (MEM_SIZE - 1);
	while (i < REG_NUMBER)
	{
		env->process->reg[i] = proc->reg[i];
		i++;
	}
	env->process->live = proc->live;
	env->process->nbplayer = proc->nbplayer;
	ft_save_op(env, env->process);
	return (1);
}

int		add_new_proc(t_env *env)
{
	t_proc *new;

	if (!(new = (t_proc *)malloc(sizeof(t_proc))))
		return (0);
	if (env->process)
		new->next = env->process;
	else
		new->next = NULL;
	env->process = new;
	return (1);
}

void	kill_procs(t_env *env)
{
	t_proc *process;
	t_proc *prev_process;

	process = env->process;
	prev_process = NULL;
	while (process)
	{
		if (process->live == 0)
		{
			if (prev_process)
				prev_process->next = process->next;
			else
				env->process = process->next;
			free(process);
			process = (env->process) ? env->process : NULL;
			if (prev_process)
				process = prev_process->next;
		}
		else
		{
			process->live = 0;
			prev_process = process;
			process = process->next;
		}
	}
}

void	ft_clean_proc(t_proc **begin)
{
	t_proc *p;
	t_proc *tmp;

	if (!(*begin))
		return ;
	p = *begin;
	while (p)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*begin = NULL;
}
