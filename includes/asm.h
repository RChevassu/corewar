/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:40:40 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:52:25 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/includes/libft.h"
# include "op.h"
# define BUFF_SIZE_GNL 100
# define ERRNAME	-1
# define ERRPARSE	-2
# define ERRCOMM 	-3
# define ERRCREA 	-4

typedef struct	s_label
{
	int				index;
	char			*label;
	struct s_label	*next_label;
}				t_label;

typedef struct	s_data
{
	int			fds;
	int			fdcor;
	char		*values;
	int			index;
	int			op_index;
	t_header	header;
	char		*file;
	t_list		*labels;
	t_op_asm	line;
}				t_data;

void			ft_set_octal(t_data *data, int type, int index);
int				ft_parsename(t_data *data);
int				ft_parsecomment(t_data *data, int i);
int				ft_load_file(t_data *data);
int				ft_findend(char *str, int i);
int				next_line(char *str, int line_end);
int				ft_checkline(char *str, int start, int end);
int				ft_parse_labels(t_data *data, int start);
int				ft_getlabel(t_data *data, int start, int l);
int				ft_get_label_index(t_data *data, t_list *lst, int start, int i);
void			ft_free_labs(void *content, size_t size_content);
int				ft_gettype(t_data *data, int start, int end, int i);
int				ft_isind(t_data *data, int start, int end);
int				ft_isdir(t_data *data, int start, int end);
int				ft_isreg(t_data *data, int start, int end);
int				ft_creatcor(t_data *data, char *filename);
int				ft_parse_code(t_data *data, int start);
int				ft_parse_arguments(t_data *data, int start, int type);
int				ft_getop(t_data *data, int start);
int				ft_isspace(char c);
int				ft_jump(char *str, int i);
int				ft_blank(char *str, int i);

#endif
