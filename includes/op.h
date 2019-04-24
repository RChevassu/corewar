/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/03/11 15:57:57 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include "../libft/includes/libft.h"
# define OP_LIVE					1
# define OP_LD						2
# define OP_ST						3
# define OP_ADD						4
# define OP_SUB						5
# define OP_AND						6
# define OP_OR						7
# define OP_XOR						8
# define OP_ZJMP					9
# define OP_LDI						10
# define OP_STI						11
# define OP_FORK					12
# define OP_LLD						13
# define OP_LLDI					14
# define OP_LFORK					15
# define OP_AFF						16
# define IND_SIZE					2
# define REG_SIZE					4
# define DIR_SIZE					REG_SIZE
# define REG_CODE					1
# define DIR_CODE					2
# define IND_CODE					3
# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE					(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE				(MEM_SIZE / 6)
# define COMMENT_CHAR				'#'
# define LABEL_CHAR					':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR				','
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING			".comment"
# define REG_NUMBER					16
# define CYCLE_TO_DIE				1536
# define CYCLE_DELTA				50
# define NBR_LIVE					21
# define MAX_CHECKS					10
# define T_REG						1
# define T_DIR						2
# define T_IND						4
# define T_LAB						8
# define PROG_NAME_LENGTH			(128)
# define COMMENT_LENGTH				(2048)
# define COREWAR_EXEC_MAGIC			0xea83f3

typedef char		t_arg_type;

typedef	struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op_asm
{
	char	name[5];
	int		arg_num;
	int		param_type[3];
	int		hexa;
	int		cycles;
	char	description[50];
	int		octal;
	int		dir_size;
}					t_op_asm;

#endif
