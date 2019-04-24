/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 01:21:58 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:02:03 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_print_c(t_pf *env, va_list args)
{
	char	c;
	char	fill;
	int		size;

	if (env->size == 'l' && env->type != '%')
		return (ft_print_cm(env, args));
	c = (env->type == '%') ? '%' : va_arg(args, int);
	fill = (env->flags.zero && env->flags.left == 0) ? '0' : ' ';
	size = env->width > 1 ? env->width : 1;
	if (env->flags.left == 1)
		ft_append_char_buffer(env, c);
	ft_fill_buffer(env, fill, size - 1);
	if (env->flags.left == 0)
		ft_append_char_buffer(env, c);
	return (0);
}

int		ft_print_s(t_pf *env, va_list args)
{
	char	*str;
	char	fill;
	int		size;

	if (env->size == 'l')
		return (ft_print_sm(env, args));
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	size = env->precision > 0 && env->precision < size ? env->precision : size;
	size = env->precision == -1 ? 0 : size;
	fill = env->flags.zero && env->flags.left == 0 ? '0' : ' ';
	if (env->width > size && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size);
	ft_append_str_buffer(env, str, size);
	if (env->width > size && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size);
	return (0);
}

int		ft_print_invalid(t_pf *env)
{
	char fill;

	fill = env->flags.zero && env->flags.left == 0 ? '0' : ' ';
	if (env->width > 1 && env->flags.left == 0 && env->type)
		ft_fill_buffer(env, fill, env->width - 1);
	if (env->type)
		ft_append_char_buffer(env, env->type);
	if (env->width > 1 && env->flags.left == 1 && env->type)
		ft_fill_buffer(env, fill, env->width - 1);
	return (0);
}

int		ft_print_p(t_pf *env, va_list args)
{
	env->size = 'z';
	env->flags.hashtag = 1;
	env->pointeur = 1;
	return (ft_print_x(env, args));
}
