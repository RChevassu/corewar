/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 01:15:57 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:04:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_print_i(t_pf *env, va_list args)
{
	return (ft_print_d(env, args));
}

int		ft_print_dm(t_pf *env, va_list args)
{
	env->size = 'l';
	return (ft_print_d(env, args));
}

int		ft_print_um(t_pf *env, va_list args)
{
	env->size = 'l';
	return (ft_print_u(env, args));
}

char	d_subfunction(t_pf *env, intmax_t n, int *size, int *size_preci)
{
	char sign;

	sign = 0;
	if (n < 0)
		sign = '-';
	else if (env->flags.space && env->flags.sign == 0)
		sign = ' ';
	else if (env->flags.sign)
		sign = '+';
	*size = ft_numlen(n);
	*size_preci = *size > env->precision ? *size : env->precision;
	*size_preci = env->precision == -1 && n == 0 ? 0 : *size_preci;
	*size_preci = sign ? *size_preci + 1 : *size_preci;
	*size = sign ? ft_numlen(n) + 1 : ft_numlen(n);
	return (sign);
}

int		ft_print_d(t_pf *env, va_list args)
{
	int			size;
	int			size_preci;
	char		fill;
	char		sign;
	intmax_t	n;

	n = ft_resize(args, env);
	sign = d_subfunction(env, n, &size, &size_preci);
	fill = env->flags.zero && env->flags.left == 0
		&& (env->precision <= 0 || env->precision > env->width) ? '0' : ' ';
	fill = env->precision == -1 ? ' ' : fill;
	if (sign && fill == '0')
		ft_append_char_buffer(env, sign);
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	if (sign && fill == ' ')
		ft_append_char_buffer(env, sign);
	ft_fill_buffer(env, '0', size_preci - size);
	if (!(env->precision == -1 && n == 0))
		ft_itobuffer(env, n);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}
