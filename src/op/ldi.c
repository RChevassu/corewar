/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:14:44 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/08 00:07:42 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int	op_ldi(t_env *p, t_proc *c)
{
	int		adr;
	int		adr2;
	t_args	args;

	args = get_args_types(c->save[1]);
	if (!(args.th == REG_CODE))
		return (1);
	if (args.fi == REG_CODE && ft_is_reg(c->save[2]))
		adr = c->reg[c->save[2] - 1];
	else if (args.fi == DIR_CODE || args.fi == IND_CODE)
		adr = (args.fi == DIR_CODE) ? argint(c->save, 2, 2)
			: get_ind(argint(c->save, 2, 2), p, c->pc, 4);
	else
		return (1);
	args.th = args.fi == REG_CODE ? 1 : 2;
	if (args.se == REG_CODE && ft_is_reg(c->save[2 + args.th]))
		adr2 = c->reg[c->save[2 + args.th] - 1];
	else if (args.se == DIR_CODE)
		adr2 = argint(c->save, 2 + args.th, 2);
	else
		return (1);
	if (ft_is_reg(c->save[2 + (args.th += args.se == REG_CODE ? 1 : 2)]))
		c->reg[c->save[2 + args.th] - 1] = get_ind(adr + adr2, p, c->pc, 4);
	c->carry = (get_ind(adr + adr2, p, c->pc, 4) == 0) ? 1 : 0;
	return (1);
}
