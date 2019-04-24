/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:57:55 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:01:45 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		(*g_list_function[16])(t_pf*, va_list) =
{
	ft_print_c, \
	ft_print_cm, \
	ft_print_d, \
	ft_print_dm, \
	ft_print_x, \
	ft_print_xm, \
	ft_print_s, \
	ft_print_sm, \
	ft_print_o, \
	ft_print_om, \
	ft_print_u, \
	ft_print_um, \
	ft_print_p, \
	ft_print_i, \
	ft_print_f, \
	ft_print_fm
};

void	parse_precision(const char **format, va_list args, t_pf *env)
{
	if (**format == '.' || **format == '*')
	{
		if (**format == '.')
			(*format)++;
		if (**format == '*' || (**format >= '0' && **format <= '9'))
		{
			if (**format == '*')
			{
				env->precision = va_arg(args, int);
				if (*(*format - 1) != '.')
				{
					env->width = env->precision;
					env->precision = 1;
				}
				env->precision = env->precision == 0 ? -1 : env->precision;
				(*format)++;
				return ;
			}
			env->precision = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
		env->precision = env->precision <= 0 ? -1 : env->precision;
	}
}

void	parse_width(const char **format, va_list args, t_pf *env)
{
	if (**format == '*' || (**format >= '0' && **format <= '9'))
	{
		if (**format == '*')
		{
			env->width = va_arg(args, int);
			if (env->width < 0)
			{
				env->width *= -1;
				env->flags.left = 1;
			}
			(*format)++;
		}
		if (**format >= '0' && **format <= '9')
		{
			env->width = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
	}
}

int		parse_flags(const char **format, t_pf *env)
{
	if (!(**format == '-' || **format == '+' || **format == ' '
		|| **format == '0' || **format == '#'))
		return (0);
	else
	{
		if (**format == '-')
			env->flags.left = 1;
		else if (**format == '+')
			env->flags.sign = 1;
		else if (**format == ' ')
			env->flags.space = 1;
		else if (**format == '0')
			env->flags.zero = 1;
		else if (**format == '#')
			env->flags.hashtag = 1;
		(*format)++;
		return (parse_flags(format, env));
	}
}

void	parse_size(const char **format, t_pf *env)
{
	if (**format == 'h' || **format == 'l' || **format == 'j'
		|| **format == 'z')
	{
		if (**format == 'j')
			env->size = 'j';
		else if (**format == 'z')
			env->size = 'z';
		else if (**format == 'h')
			env->size = 'h';
		else if (**format == 'l')
			env->size = 'l';
		(*format)++;
		if (**format == 'h' && env->size == 'h')
			env->size = 'H';
		else if (**format == 'l' && env->size == 'l')
			env->size = 'L';
		if (env->size == 'H' || env->size == 'L')
			(*format)++;
	}
}

int		parse_type(const char **format, va_list args, t_pf *env, char *s)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (s[i] == **format)
		{
			(*format)++;
			env->type = s[i];
			return (g_list_function[i](env, args));
		}
		else if (**format == '%')
		{
			(*format)++;
			env->type = '%';
			ft_print_c(env, args);
			return (1);
		}
		i++;
	}
	env->type = **format;
	if (**format)
		(*format)++;
	return (ft_print_invalid(env));
}
