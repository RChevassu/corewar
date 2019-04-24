/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 00:15:50 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/07 23:47:08 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int	op_lld(t_env *p, t_proc *c)
{
	int		val;
	int		reg;
	t_args	t;

	c->carry = 0;
	t = get_args_types(c->save[1]);
	if ((t.fi == DIR_CODE || t.fi == IND_CODE) && t.se == REG_CODE)
	{
		val = (t.fi == DIR_CODE) ? argint(c->save, 2, 4)
			: get_ind_all(argint(c->save, 2, 2), p, c->pc, 4);
		reg = (t.fi == DIR_CODE) ? c->save[6] : c->save[4];
		if ((reg >= 1) && (reg <= REG_NUMBER))
			c->reg[reg - 1] = val;
		c->carry = (val == 0) ? 1 : 0;
	}
	return (1);
}
