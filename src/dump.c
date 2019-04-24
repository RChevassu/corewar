/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:07:11 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/14 18:31:08 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "../libft/includes/ft_printf.h"
#include "../includes/proto.h"

void	ft_get_color(t_env *env, int i)
{
	if (env->map_2[i])
		attron(COLOR_PAIR(3));
	else if (env->map_3[i] == 2)
		attron(COLOR_PAIR(2));
	else if (env->map_3[i] == 1)
		attron(COLOR_PAIR(1));
	else if (env->map_3[i] == 3)
		attron(COLOR_PAIR(5));
	else if (env->map_3[i] == 4)
		attron(COLOR_PAIR(6));
	else
		attron(COLOR_PAIR(4));
}

void	aff_taunt(t_env *env)
{
	attron(COLOR_PAIR(1));
	printw("%s\n", env->play[0].taunt_2);
	attron(COLOR_PAIR(2));
	printw("%s\n", env->play[1].taunt_2);
	attron(COLOR_PAIR(5));
	printw("%s\n", env->play[2].taunt_2);
	attron(COLOR_PAIR(6));
	printw("%s\n", env->play[3].taunt_2);
	attron(COLOR_PAIR(4));
}

void	ft_curses(t_env *env)
{
	int i;

	i = 0;
	erase();
	while (i < MEM_SIZE)
	{
		ft_get_color(env, i);
		printw("%.2x ", env->map[i]);
		i++;
		if (i % 64 == 0)
			printw("\n");
	}
	attron(COLOR_PAIR(4));
	printw("\n");
	aff_taunt(env);
	printw("Cycle : %11i        ", env->cycle);
	printw("Last alive : %s\n", env->play[env->last_live - 1].name);
	printw("Cycle to Die : %4i        ", env->cycle_die);
	refresh();
}

int		dump(t_env *env)
{
	int i;

	i = 0;
	ft_clean_proc(&env->process);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x ", env->map[i]);
		i++;
		if (i % 64 == 0)
			ft_printf("\n");
	}
	return (1);
}

int		exit_ncurses(t_env *env, int i)
{
	if (i == 1)
		printw("Gagnant : %s\n", env->play[env->last_live - 1].name);
	getch();
	endwin();
	return (0);
}
