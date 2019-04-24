/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:00:18 by gufortel          #+#    #+#             */
/*   Updated: 2019/03/08 00:49:41 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/proto.h"
#include "../libft/includes/ft_printf.h"
#include <ncurses.h>

void		init_ncurses(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
}

int			init_proc(t_env *env, int j, int pos)
{
	int i;

	if (!(add_new_proc(env)))
		return (0);
	env->process->carry = 0;
	env->process->pc = pos;
	i = 0;
	while (i < REG_NUMBER)
	{
		env->process->reg[i] = 0;
		i++;
	}
	env->process->reg[0] = -(j + 1);
	env->process->live = 0;
	env->process->nbplayer = j + 1;
	env->last_live = j + 1;
	return (1);
}

static int	bz_map(t_env *p)
{
	ft_bzero(p->map, MEM_SIZE);
	ft_bzero(p->map_2, MEM_SIZE);
	ft_bzero(p->map_3, MEM_SIZE);
	if (p->visu != 2)
		ft_printf("Introducing contestants...\n");
	return (0);
}

int			init_arena(t_env *p)
{
	int j;
	int s;
	int i;

	j = bz_map(p);
	while (j < p->nbplayers)
	{
		s = (j * MEM_SIZE) / p->nbplayers;
		if (!(init_proc(p, j, s)))
			return (0);
		if (p->visu != 2)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			j + 1, p->play[j].size_champ, p->play[j].name, p->play[j].comment);
		i = 0;
		while (i < CHAMP_MAX_SIZE)
		{
			p->map[s] = p->play[j].champ[i];
			p->map_3[s] = i < p->play[j].size_champ ? p->play[j].id_player : 0;
			s++;
			i++;
		}
		ft_save_op(p, p->process);
		j++;
	}
	return (1);
}
