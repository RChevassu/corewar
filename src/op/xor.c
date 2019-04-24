/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:21:05 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/07 23:46:25 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

static int	ft_supp_xor(t_env *p, t_proc *c, t_args args, int tmp)
{
	int offset;

	offset = get_arg_len(args.fi);
	if (args.se == REG_CODE && ft_is_reg(c->save[2 + offset]))
		tmp = tmp ^ (c->reg[c->save[2 + offset] - 1]);
	else if (args.se == DIR_CODE)
		tmp = tmp ^ (argint(c->save, 2, 4));
	else if (args.se == IND_CODE)
		tmp = tmp ^ (get_ind(argint(c->save, 2, 2), p, c->pc, 4));
	return (tmp);
}

int			op_xor(t_env *p, t_proc *c)
{
	int		tmp;
	int		offset;
	t_args	args;

	args = get_args_types(c->save[1]);
	if (args.fi && args.se && args.th == REG_CODE)
	{
		if ((args.fi == REG_CODE && ft_is_reg(c->save[2]))
			|| args.fi == DIR_CODE || args.fi == IND_CODE)
			tmp = ft_supp_axo(p, c, args.fi);
		else
			return (1);
		offset = get_arg_len(args.fi);
		if ((args.se == REG_CODE && ft_is_reg(c->save[2 + offset]))
			|| args.se == DIR_CODE || args.se == IND_CODE)
			tmp = ft_supp_xor(p, c, args, tmp);
		else
			return (1);
		offset += get_arg_len(args.se);
		if (!(ft_is_reg(c->save[2 + offset])))
			return (1);
		c->reg[c->save[2 + offset] - 1] = tmp;
		c->carry = (tmp == 0) ? 0 : 1;
	}
	return (1);
}
