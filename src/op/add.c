/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:49:11 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/07 23:09:12 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int		op_add(t_env *p, t_proc *c)
{
	int		val;
	t_args	t;

	(void)p;
	t = get_args_types(c->save[1]);
	if (t.fi != 1 || t.se != 1 || t.th != 1)
		return (1);
	if (c->save[2] < 1 || c->save[2] > 16)
		return (1);
	if (c->save[3] < 1 || c->save[3] > 16)
		return (1);
	if (c->save[4] < 1 || c->save[4] > 16)
		return (1);
	val = c->reg[c->save[2] - 1] + c->reg[c->save[3] - 1];
	c->carry = (val == 0) ? 1 : 0;
	c->reg[c->save[4] - 1] = val;
	return (1);
}
