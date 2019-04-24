/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2019/03/08 00:16:45 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/proto.h"

static int	ft_winscreen(t_env *p)
{
	ft_clean_proc(&p->process);
	if (p->visu == 2)
		return (1);
	ft_printf("Contestant %d, %s, has won !\n",
		p->last_live, p->play[p->last_live - 1].name);
	return (1);
}

static void	ft_resave(t_env *p)
{
	t_proc *proc;

	proc = p->process;
	while (proc)
	{
		if (proc->mv == 1)
			ft_save_op(p, proc);
		proc = proc->next;
	}
}

static int	do_op(t_env *p)
{
	t_proc *proc;

	proc = p->process;
	while (proc)
	{
		p->map_2[proc->pc] = 1;
		if (proc->cycle == 0)
		{
			if (proc->op != -1)
			{
				if (!(ft_exec_op(p, proc)))
					return (0);
			}
			else
				move_pc(proc, 1);
		}
		proc->cycle = (proc->cycle <= 0) ? 0 : proc->cycle - 1;
		proc = proc->next;
	}
	ft_resave(p);
	return (1);
}

static void	ft_check_lives(t_env *p)
{
	if (p->nblives >= NBR_LIVE)
	{
		p->check = 0;
		p->nblives = 0;
		p->cycle_die -= CYCLE_DELTA;
		if (p->cycle_die < 0)
			p->cycle_die = 0;
	}
	else
		p->check++;
	if (p->check == MAX_CHECKS)
	{
		p->check = 0;
		p->nblives = 0;
		p->cycle_die -= CYCLE_DELTA;
		if (p->cycle_die < 0)
			p->cycle_die = 0;
	}
}

int			loop(t_env *p)
{
	p->cycle = 0;
	p->check = 0;
	p->cycle_die = CYCLE_TO_DIE;
	while (p->process)
	{
		p->cycle_act = 0;
		p->nblives = 0;
		while (p->cycle_act < p->cycle_die)
		{
			ft_bzero(p->map_2, MEM_SIZE);
			if (!(do_op(p)))
				return (0);
			p->cycle_act++;
			p->cycle++;
			if (p->visu == 2)
				ft_curses(p);
			if (p->cycle == p->dump)
				return (dump(p));
		}
		kill_procs(p);
		ft_check_lives(p);
	}
	return (ft_winscreen(p));
}
