/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 01:08:21 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:13:42 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_print_xm(t_pf *env, va_list args)
{
	int			size;
	int			size_preci;
	char		fill;
	uintmax_t	n;

	n = ft_uresize(args, env);
	size = env->precision == -1 && n == 0 ? 0 : ft_numlen_base(n, 16);
	size_preci = env->precision > size ? env->precision : size;
	size += env->flags.hashtag && (n > 0 || env->pointeur) ? 2 : 0;
	size_preci += env->flags.hashtag && (n > 0 || env->pointeur) ? 2 : 0;
	fill = (env->flags.zero && env->flags.left == 0
		&& (env->precision == 0 || env->precision > env->width)) ? '0' : ' ';
	if (env->flags.hashtag && n > 0 && fill == '0')
		ft_append_str_buffer(env, "0X", 2);
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	if (env->flags.hashtag && (n > 0 || env->pointeur) && fill == ' ')
		ft_append_str_buffer(env, "0X", 2);
	if (size_preci > size)
		ft_fill_buffer(env, '0', size_preci - size);
	if (!(env->precision == -1 && n == 0))
		ft_itobuffer_base(env, n, 16, 1);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}

int		ft_print_x(t_pf *env, va_list args)
{
	int			size;
	int			size_preci;
	char		fill;
	uintmax_t	n;

	n = ft_uresize(args, env);
	size = env->precision == -1 && n == 0 ? 0 : ft_numlen_base(n, 16);
	size_preci = env->precision > size ? env->precision : size;
	size += env->flags.hashtag && (n > 0 || env->pointeur) ? 2 : 0;
	size_preci += env->flags.hashtag && (n > 0 || env->pointeur) ? 2 : 0;
	fill = (env->flags.zero && env->flags.left == 0
		&& (env->precision == 0 || env->precision > env->width)) ? '0' : ' ';
	if (env->flags.hashtag && (n > 0 || env->pointeur) && fill == '0')
		ft_append_str_buffer(env, "0x", 2);
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	if (env->flags.hashtag && (n > 0 || env->pointeur) && fill == ' ')
		ft_append_str_buffer(env, "0x", 2);
	if (size_preci > size)
		ft_fill_buffer(env, '0', size_preci - size);
	if (!(env->precision == -1 && n == 0))
		ft_itobuffer_base(env, n, 16, 0);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}

int		ft_print_o(t_pf *env, va_list args)
{
	char		fill;
	int			size;
	int			size_preci;
	uintmax_t	n;

	n = ft_uresize(args, env);
	size = env->precision == -1 && n == 0 ? 0 : ft_numlen_base(n, 8);
	if (env->flags.hashtag && (n > 0 || (n == 0 && env->precision == -1)))
		size++;
	fill = (env->flags.zero && env->flags.left == 0) ? '0' : ' ';
	size_preci = env->precision > size ? env->precision : size;
	if (env->width > size_preci && env->precision)
		fill = ' ';
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	if (env->precision > size)
		ft_fill_buffer(env, '0', env->precision - size);
	if (env->flags.hashtag && n > 0)
		ft_append_char_buffer(env, '0');
	if (!(env->precision == -1 && n == 0 && env->flags.hashtag == 0))
		ft_itobuffer_base(env, n, 8, 0);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}

int		ft_print_om(t_pf *env, va_list args)
{
	env->size = 'l';
	return (ft_print_o(env, args));
}

int		ft_print_u(t_pf *env, va_list args)
{
	int			size;
	int			size_preci;
	char		fill;
	uintmax_t	n;

	n = ft_uresize(args, env);
	size = ft_numlen_base(n, 10);
	size_preci = size > env->precision ? size : env->precision;
	size_preci = env->precision == -1 && n == 0 ? 0 : size_preci;
	fill = env->flags.zero && env->flags.left == 0
		&& (env->precision == 0 || env->precision > env->width) ? '0' : ' ';
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	ft_fill_buffer(env, '0', size_preci - size);
	if (!(env->precision == -1 && n == 0))
		ft_itobuffer_base(env, n, 10, 0);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}
