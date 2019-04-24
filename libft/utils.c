/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 23:34:07 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:14:49 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <unistd.h>

void		ft_print_until(t_pf *env, char *str, int len)
{
	env->last_index = env->index;
	write(1, str, len);
}

int			ft_numlen_base(uintmax_t num, int base)
{
	int i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

uintmax_t	ft_uresize(va_list args, t_pf *env)
{
	uintmax_t i;

	i = va_arg(args, uintmax_t);
	if (env->size == 'H')
		return ((unsigned char)i);
	else if (env->size == 'h')
		return ((short unsigned int)i);
	else if (env->size == 'L')
		return ((long double)i);
	else if (env->size == 'l')
		return ((long unsigned int)i);
	else if (env->size == 'j')
		return ((uintmax_t)i);
	else if (env->size == 'z')
		return ((size_t)i);
	return ((unsigned int)i);
}

intmax_t	ft_resize(va_list args, t_pf *env)
{
	intmax_t i;

	i = va_arg(args, intmax_t);
	if (env->size == 'H')
		return ((char)i);
	else if (env->size == 'h')
		return ((short int)i);
	else if (env->size == 'L')
		return ((long long)i);
	else if (env->size == 'l')
		return ((long int)i);
	else if (env->size == 'j')
		return ((intmax_t)i);
	else if (env->size == 'z')
		return ((size_t)i);
	return ((int)i);
}
