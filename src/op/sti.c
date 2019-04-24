/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 00:28:33 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/06 01:35:10 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int	op_sti(t_env *p, t_proc *c)
{
	int		adr;
	int		adr2;
	t_args	args;

	args = get_args_types(c->save[1]);
	if (!(args.fi == REG_CODE && ft_is_reg(c->save[2])
		&& args.se && (args.th == REG_CODE || args.th == DIR_CODE)))
		return (1);
	if (args.se == REG_CODE && ft_is_reg(c->save[3]))
		adr = c->reg[c->save[3] - 1];
	else if (args.se == DIR_CODE)
		adr = argint(c->save, 3, 2);
	else if (args.se == IND_CODE)
		adr = get_ind(argint(c->save, 3, 2), p, c->pc, 4);
	else
		return (1);
	args.fi = args.se == REG_CODE ? 1 : 2;
	if (args.th == REG_CODE && ft_is_reg(c->save[3 + args.fi]))
		adr2 = c->reg[c->save[3 + args.fi] - 1];
	else if (args.th == DIR_CODE)
		adr2 = argint(c->save, 3 + args.fi, 2);
	else
		return (1);
	print_reg(p, c, (adr + adr2) % IDX_MOD, c->reg[c->save[2] - 1]);
	return (1);
}
