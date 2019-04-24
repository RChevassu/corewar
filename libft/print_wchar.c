/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 00:47:10 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:28:38 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_wcharlen(wchar_t c)
{
	if (c < 0 || (c <= 0xDFFF && c >= 0xD800))
		return (-1);
	else if (c <= 255 && MB_CUR_MAX >= 1)
		return (1);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

void	ft_putwchar(t_pf *env, wchar_t c)
{
	if (c <= 255)
		ft_append_char_buffer(env, c);
	else if (c <= 0x7FF)
	{
		ft_append_char_buffer(env, (c >> 6) + 0b11000000);
		ft_append_char_buffer(env, (c & 0b111111) + 0b10000000);
	}
	else if (c <= 0xFFFF)
	{
		ft_append_char_buffer(env, (c >> 12) + 0b11100000);
		ft_append_char_buffer(env, ((c >> 6) & 0b111111) + 0b10000000);
		ft_append_char_buffer(env, (c & 0b111111) + 0b10000000);
	}
	else if (c <= 0x10FFFF)
	{
		ft_append_char_buffer(env, (c >> 18) + 0b11110000);
		ft_append_char_buffer(env, ((c >> 12) & 0b111111) + 0b10000000);
		ft_append_char_buffer(env, ((c >> 6) & 0b111111) + 0b10000000);
		ft_append_char_buffer(env, (c & 0b111111) + 0b10000000);
	}
}

int		ft_print_cm(t_pf *env, va_list args)
{
	wchar_t	c;
	char	fill;
	int		size;

	c = (wchar_t)va_arg(args, wchar_t);
	size = ft_wcharlen(c);
	if (size < 0)
		return (size);
	fill = (env->flags.zero && env->flags.left == 0) ? '0' : ' ';
	if (env->flags.left == 1)
		ft_putwchar(env, c);
	if (env->width > size)
		ft_fill_buffer(env, fill, env->width - size);
	if (env->flags.left == 0)
		ft_putwchar(env, c);
	return (1);
}
