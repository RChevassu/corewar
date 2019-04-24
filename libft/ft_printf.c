/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:29:34 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:03:20 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	reset_pf(t_pf *env)
{
	env->precision = 0;
	env->pointeur = 0;
	env->width = 0;
	env->size = 0;
	env->type = 0;
	env->flags.left = 0;
	env->flags.sign = 0;
	env->flags.zero = 0;
	env->flags.space = 0;
	env->flags.hashtag = 0;
}

int		parse(const char **format, va_list args, t_pf *env)
{
	reset_pf(env);
	parse_flags(format, env);
	parse_width(format, args, env);
	parse_precision(format, args, env);
	parse_size(format, env);
	return (parse_type(format, args, env, "cCdDxXsSoOuUpifF"));
}

int		inner_printf(const char *format, va_list args, t_pf *env)
{
	char *next_arg;

	if (*format == 0)
	{
		ft_print_until(env, env->buffer, env->index % BUFF_SIZE);
		return (env->index);
	}
	next_arg = ft_strchr(format, '%');
	if (next_arg == NULL)
	{
		ft_append_str_buffer(env, format, ft_strlen(format));
		ft_print_until(env, env->buffer, env->index % BUFF_SIZE);
		return (env->index);
	}
	else
	{
		ft_append_str_buffer(env, format, next_arg - format);
		format += next_arg - format + 1;
		if (parse(&format, args, env) < 0)
			return (-1);
		else
			env->last_index = env->index;
	}
	return (inner_printf(format, args, env));
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_pf	env;
	int		ret;

	va_start(args, format);
	env.index = 0;
	env.last_index = 0;
	ret = inner_printf(format, args, &env);
	if (ret < 0)
		ft_print_until(&env, env.buffer, env.last_index % BUFF_SIZE);
	return (ret);
}
