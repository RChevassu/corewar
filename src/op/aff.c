/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:35:03 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/08 00:39:44 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"
#include "../../libft/includes/ft_printf.h"

void	duplicate_taunt(t_play *p)
{
	int i;

	i = 0;
	while (i < 80)
	{
		p->taunt_2[i] = p->taunt[i];
		i++;
	}
}

int		op_aff(t_env *p, t_proc *c)
{
	t_args	t;
	int		aff;

	t = get_args_types(c->save[1]);
	if (t.fi == REG_CODE)
	{
		if (c->save[2] >= 1 && c->save[2] <= REG_NUMBER)
			aff = (c->reg[c->save[2] - 1] % 256);
		else
			return (1);
		aff = aff > 31 ? aff : 0;
		p->play[c->nbplayer - 1].taunt[p->play[c->nbplayer - 1].tnt] = aff;
		p->play[c->nbplayer - 1].tnt++;
		if (aff == 0 || p->play[c->nbplayer - 1].tnt == 79)
		{
			if (p->visu != 2)
				ft_printf("%s\n", p->play[c->nbplayer - 1].taunt);
			else
				duplicate_taunt(&p->play[c->nbplayer - 1]);
			p->play[c->nbplayer - 1].tnt = 0;
			ft_bzero(p->play[c->nbplayer - 1].taunt, 80);
		}
	}
	return (1);
}
