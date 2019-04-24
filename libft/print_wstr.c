/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 00:57:02 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:28:43 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_append_wstr_buffer(t_pf *env, wchar_t *wstr, int len)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (total < len && wstr[i])
	{
		total += ft_wcharlen(wstr[i]);
		if (total <= len)
			ft_putwchar(env, wstr[i]);
		i++;
	}
	if (total > len)
		total -= ft_wcharlen(wstr[i - 1]);
	return (total);
}

int		ft_test_wstr(wchar_t *wstr, int len)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (total < len && wstr[i])
	{
		total += ft_wcharlen(wstr[i]);
		i++;
	}
	if (total > len)
		total -= ft_wcharlen(wstr[i - 1]);
	return (total);
}

int		ft_wstrlen(wchar_t *wstr, int precision)
{
	int	i;
	int	len;
	int	ret;

	i = 0;
	len = 0;
	while (wstr[i] != 0)
	{
		ret = ft_wcharlen(wstr[i]);
		if (ret == -1 && (wstr[i] > 255 || wstr[i] < 0))
			return (-1);
		len += ret;
		if (len >= precision && precision > 0)
			return (precision);
		i++;
	}
	return (len);
}

int		ft_print_sm(t_pf *env, va_list args)
{
	wchar_t	*wstr;
	char	fill;
	int		size;
	int		ret;

	wstr = va_arg(args, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	size = ft_wstrlen(wstr, env->precision);
	if (size < 0)
		return (size);
	size = env->precision == -1 ? 0 : size;
	fill = env->flags.zero && env->flags.left == 0 ? '0' : ' ';
	ret = ft_test_wstr(wstr, size);
	if (env->width > ret && env->flags.left == 0)
		ft_fill_buffer(env, fill, env->width - ret);
	ret = ft_append_wstr_buffer(env, wstr, size);
	if (env->width > ret && env->flags.left == 1)
		ft_fill_buffer(env, fill, env->width - ret);
	return (0);
}
