/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 00:04:37 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:03:20 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_append_char_buffer(t_pf *env, char c)
{
	if (env->index % BUFF_SIZE == 0 && env->index > 0)
		ft_print_until(env, env->buffer, BUFF_SIZE);
	env->buffer[env->index % BUFF_SIZE] = c;
	env->index++;
}

void	ft_itobuffer(t_pf *env, intmax_t nb)
{
	char c;

	if (nb >= 10 || nb <= -10)
	{
		ft_itobuffer(env, nb / 10);
		ft_itobuffer(env, nb % 10);
	}
	else
	{
		c = nb > 0 ? '0' + nb : '0' - nb;
		ft_append_char_buffer(env, c);
	}
}

void	ft_itobuffer_base(t_pf *env, uintmax_t nb, uintmax_t base, int maj)
{
	char c;

	if (nb >= base)
	{
		ft_itobuffer_base(env, nb / base, base, maj);
		ft_itobuffer_base(env, nb % base, base, maj);
	}
	else
	{
		c = nb > 9 ? 'a' + nb - 10 : '0' + nb;
		c -= maj && c >= 'a' && c <= 'f' ? 32 : 0;
		ft_append_char_buffer(env, c);
	}
}

void	ft_fill_buffer(t_pf *env, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_append_char_buffer(env, c);
		i++;
	}
}

int		ft_append_str_buffer(t_pf *env, const char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_append_char_buffer(env, str[i]);
		i++;
	}
	return (i);
}
