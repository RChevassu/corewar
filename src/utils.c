/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:56:42 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/14 18:04:55 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struc.h"

int		ft_atoi_re(char *str)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (str[i])
	{
		total *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			total += str[i] - '0';
		else
			return (-1);
		i++;
	}
	return (total);
}

void	print_reg(t_env *p, t_proc *c, int adr, int val)
{
	int	i;

	i = 4;
	adr += 3;
	while (i--)
	{
		p->map[((unsigned int)(c->pc + adr)) & (MEM_SIZE - 1)] = val & 0xFF;
		p->map_3[((unsigned int)(c->pc + adr)) & (MEM_SIZE - 1)] = c->nbplayer;
		val >>= 8;
		adr--;
	}
}

t_args	get_args_types(int x)
{
	t_args	args;

	args.fi = (unsigned char)((x & 0b11000000) >> 6);
	args.se = (unsigned char)((x & 0b110000) >> 4);
	args.th = (unsigned char)((x & 0b1100) >> 2);
	return (args);
}

int		argint(unsigned char *str, int offset, int size)
{
	int	total;

	total = 0;
	if (size == 2)
	{
		total += str[offset] * 256;
		total += str[offset + 1];
		return ((short)total);
	}
	else
	{
		total += str[offset] * 256 * 256 * 256;
		total += str[offset + 1] * 256 * 256;
		total += str[offset + 2] * 256;
		total += str[offset + 3];
		return ((int)total);
	}
	return (total);
}

int		move_pc(t_proc *proc, int nb)
{
	proc->pc = (proc->pc + nb) & (MEM_SIZE - 1);
	proc->mv = 1;
	return (1);
}
