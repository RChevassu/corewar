/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 00:17:33 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/07 23:01:40 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

int		op_fork(t_env *p, t_proc *c)
{
	int		pc;

	pc = argint(c->save, 1, 2) % IDX_MOD;
	if (!clone_proc(p, c, c->pc + pc))
	{
		ft_clean_proc(&p->process);
		return (0);
	}
	return (1);
}
