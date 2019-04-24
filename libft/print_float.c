/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:00:35 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:02:28 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_decimaltobuffer(t_pf *env, intmax_t nb, int precision)
{
	if (nb >= 10 || nb <= -10 || precision > 0)
	{
		ft_decimaltobuffer(env, nb / 10, precision - 1);
		ft_itobuffer(env, nb % 10);
	}
}

void	ft_ftobuffer(t_pf *env, double nb)
{
	int			precision;
	intmax_t	i;

	i = (intmax_t)nb;
	ft_itobuffer(env, i);
	if (env->precision == -1)
		return ;
	ft_append_char_buffer(env, '.');
	nb -= (double)i;
	i = 1;
	precision = env->precision ? env->precision : 6;
	while (precision-- >= 0)
		i *= 10;
	precision = env->precision ? env->precision : 6;
	i = nb * i;
	i += i % 10 < 5 ? 0 : 10 - i % 10;
	i /= 10;
	ft_decimaltobuffer(env, i, precision);
}

char	f_subfunction(t_pf *env, double n, int *size, int *size_preci)
{
	char sign;

	sign = 0;
	if (n < 0)
		sign = '-';
	else if (env->flags.space && env->flags.sign == 0)
		sign = ' ';
	else if (env->flags.sign)
		sign = '+';
	*size = ft_numlen((int)n);
	*size_preci = env->precision ? *size + env->precision + 1 : *size + 7;
	*size_preci = env->precision == -1 ? *size : *size_preci;
	*size_preci = sign ? *size_preci + 1 : *size_preci;
	*size += sign ? 1 : 0;
	return (sign);
}

int		ft_print_fm(t_pf *env, va_list args)
{
	return (ft_print_f(env, args));
}

int		ft_print_f(t_pf *env, va_list args)
{
	int			size;
	int			size_preci;
	char		fill;
	char		sign;
	double		n;

	n = va_arg(args, double);
	sign = f_subfunction(env, n, &size, &size_preci);
	if (n < 0)
		n *= -1;
	fill = env->flags.zero && env->flags.left == 0
		&& (env->precision <= 0 || env->precision > env->width) ? '0' : ' ';
	if (sign && fill == '0')
		ft_append_char_buffer(env, sign);
	if (env->width > size_preci && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - size_preci);
	if (sign && fill == ' ')
		ft_append_char_buffer(env, sign);
	if (!(env->precision == -1 && n == 0))
		ft_ftobuffer(env, n);
	if (env->width > size_preci && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - size_preci);
	return (0);
}
