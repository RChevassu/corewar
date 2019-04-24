/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:27:19 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/06 00:29:42 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int	op_st(t_env *p, t_proc *c)
{
	int		adr;
	t_args	args;

	args = get_args_types(c->save[1]);
	if (args.fi == REG_CODE && (args.se == REG_CODE || args.se == IND_CODE)
		&& c->save[2] >= 1 && c->save[2] <= REG_NUMBER)
	{
		if (args.se == REG_CODE && c->save[3] >= 1 && c->save[3 <= REG_NUMBER])
			c->reg[c->save[3] - 1] = c->reg[c->save[2] - 1];
		else if (args.se == IND_CODE)
		{
			adr = argint(c->save, 3, 2);
			print_reg(p, c, (adr % IDX_MOD), c->reg[c->save[2] - 1]);
		}
	}
	return (1);
}
