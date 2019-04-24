/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <Gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:25:57 by Gufortel          #+#    #+#             */
/*   Updated: 2019/03/08 00:54:12 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H
# include "./op.h"
# include "../libft/includes/libft.h"

typedef struct		s_op
{
	char			*name;
	int				nbarg;
	int				arg[4];
	int				op_code;
	int				cycles;
	char			*def;
	int				octal;
	int				dir_size;
}					t_op;

typedef struct		s_proc
{
	int				carry;
	unsigned int	pc;
	int				reg[REG_NUMBER + 1];
	int				live;
	int				cycle;
	int				nbplayer;
	int				jp;
	int				op;
	unsigned char	save[15];
	int				mv;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_args
{
	unsigned char fi;
	unsigned char se;
	unsigned char th;
}					t_args;

typedef struct		s_play
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	champ[CHAMP_MAX_SIZE];
	int				size_champ;
	int				id_live;
	int				id_player;
	char			taunt[80];
	char			taunt_2[80];
	int				tnt;
}					t_play;

typedef struct		s_env
{
	t_play			play[MAX_PLAYERS];
	unsigned char	map[MEM_SIZE];
	unsigned char	map_2[MEM_SIZE];
	unsigned char	map_3[MEM_SIZE];
	t_op			*op_tab;
	t_proc			*process;
	int				cycle;
	int				last_live;
	int				nblives;
	int				cycle_die;
	int				cycle_act;
	int				check;
	int				visu;
	int				dump;
	int				nbplayers;
}					t_env;
#endif
