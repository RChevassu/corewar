/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 22:05:52 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 14:03:20 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft.h"
# define BUFF_SIZE 500

typedef struct	s_flags{
	int			left;
	int			sign;
	int			zero;
	int			space;
	int			hashtag;
}				t_flags;

typedef struct	s_pf{
	int			precision;
	int			width;
	int			size;
	int			type;
	char		buffer[BUFF_SIZE];
	int			index;
	int			last_index;
	int			pointeur;
	t_flags		flags;
}				t_pf;

int				ft_printf(const char *restrict format, ...);
int				parse_flags(const char **format, t_pf *env);
void			parse_width(const char **format, va_list args, t_pf *env);
void			parse_precision(const char **format, va_list args, t_pf *env);
void			parse_size(const char **format, t_pf *env);
int				parse_type(const char **format,
					va_list args, t_pf *env, char *s);

void			ft_append_char_buffer(t_pf *env, char c);
int				ft_append_str_buffer(t_pf *env, const char *str, int len);
void			ft_fill_buffer(t_pf *env, char c, int len);
void			ft_itobuffer_base(t_pf *env, uintmax_t nb,
					uintmax_t base, int maj);
void			ft_itobuffer(t_pf *env, intmax_t nb);
void			ft_print_until(t_pf *env, char *str, int len);
void			ft_putwchar(t_pf *env, wchar_t c);

uintmax_t		ft_uresize(va_list args, t_pf *env);
intmax_t		ft_resize(va_list args, t_pf *env);
int				ft_numlen_base(uintmax_t num, int base);
int				ft_wcharlen(wchar_t c);

int				ft_print_c(t_pf *env, va_list args);
int				ft_print_cm(t_pf *env, va_list args);
int				ft_print_d(t_pf *env, va_list args);
int				ft_print_x(t_pf *env, va_list args);
int				ft_print_xm(t_pf *env, va_list args);
int				ft_print_s(t_pf *env, va_list args);
int				ft_print_sm(t_pf *env, va_list args);
int				ft_print_o(t_pf *env, va_list args);
int				ft_print_om(t_pf *env, va_list args);
int				ft_print_dm(t_pf *env, va_list args);
int				ft_print_u(t_pf *env, va_list args);
int				ft_print_um(t_pf *env, va_list args);
int				ft_print_p(t_pf *env, va_list args);
int				ft_print_i(t_pf *env, va_list args);
int				ft_print_f(t_pf *env, va_list args);
int				ft_print_fm(t_pf *env, va_list args);
int				ft_print_invalid(t_pf *env);

#endif
