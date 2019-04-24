/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:07:41 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/08 00:10:09 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"
#include "../../libft/includes/ft_printf.h"

static int	live_value(t_proc *process)
{
	unsigned char arg[4];

	arg[0] = process->save[4];
	arg[1] = process->save[3];
	arg[2] = process->save[2];
	arg[3] = process->save[1];
	return (*(int*)&arg[0]);
}

int			op_live(t_env *p, t_proc *process)
{
	int		live;
	int		j;

	j = 0;
	live = live_value(process);
	p->nblives++;
	while (j < p->nbplayers && p->play[j].id_live != live)
		j++;
	if (j < p->nbplayers)
	{
		if (p->visu == 1)
			ft_printf("Player %d is alive !\n", p->play[j].id_player);
		p->last_live = p->play[j].id_player;
	}
	else if (p->visu == 1)
		ft_printf("Unknown player is alive !\n");
	process->live = 1;
	return (1);
}
