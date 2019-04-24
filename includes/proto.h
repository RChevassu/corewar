/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <Gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:19:16 by Gufortel          #+#    #+#             */
/*   Updated: 2019/03/14 18:26:19 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H
# include "./struc.h"

t_op	*buildtab(void);
int		ft_atoi_re(char *str);
void	ft_initplayers(t_env *p);
int		createplayers(char **av, int ac, int i, t_env *p);
int		createplay(t_play *player, char *name, int j);
int		init_arena(t_env *p);
int		add_new_proc(t_env *env);
void	kill_procs(t_env *env);
int		clone_proc(t_env *env, t_proc *proc, int pos);
int		op_live(t_env *p, t_proc *process);
int		op_ld(t_env *p, t_proc *c);
int		op_st(t_env *p, t_proc *c);
int		op_add(t_env *p, t_proc *c);
int		op_sub(t_env *p, t_proc *c);
int		op_and(t_env *p, t_proc *c);
int		op_or(t_env *p, t_proc *c);
int		op_xor(t_env *p, t_proc *c);
int		op_zjmp(t_env *p, t_proc *c);
int		op_fork(t_env *p, t_proc *c);
int		op_lfork(t_env *p, t_proc *c);
int		op_lld(t_env *p, t_proc *c);
int		op_ldi(t_env *p, t_proc *c);
int		op_lldi(t_env *p, t_proc *c);
int		op_sti(t_env *p, t_proc *c);
int		op_aff(t_env *p, t_proc *c);
int		loop(t_env *p);
int		move_pc(t_proc *proc, int nb);
void	print_reg(t_env *p, t_proc *c, int adr, int val);
t_args	get_args_types(int x);
int		argint(unsigned char *str, int offset, int size);
int		ft_is_reg(unsigned char c);
int		get_ind(int val, t_env *p, int pc, int size);
int		get_ind_all(int val, t_env *p, int pc, int size);
void	ft_save_op(t_env *env, t_proc *proc);
int		ft_exec_op(t_env *env, t_proc *proc);
void	init_ncurses();
void	init_taunt(t_env *p);
int		exit_ncurses(t_env *env, int i);
void	ft_curses(t_env *env);
int		dump(t_env *env);
int		get_arg_len(int argtype);
void	ft_clean_proc(t_proc **begin);
int		ft_supp_axo(t_env *p, t_proc *c, int fi);

#endif
