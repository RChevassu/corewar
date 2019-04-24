/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <Gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:46 by Gufortel          #+#    #+#             */
/*   Updated: 2019/03/14 18:33:01 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/proto.h"

static int	ft_usage(void)
{
	ft_printf("usage:./corewar [-d nbr_cycle | -l | -n] [-p nbr] champ.cor\n");
	return (0);
}

static int	ft_treat_visu(char **av, t_env *p, int ac)
{
	int i;

	i = 1;
	if (ft_strcmp(av[i], "-dump") == 0 || ft_strcmp(av[i], "-d") == 0)
	{
		if (i + 1 >= ac || ((p->dump = ft_atoi_re(av[i + 1])) < 0))
			return (0);
		return (3);
	}
	if (ft_strcmp(av[i], "-live") == 0 || ft_strcmp(av[i], "-l") == 0)
	{
		p->visu = 1;
		return (2);
	}
	if (ft_strcmp(av[i], "-ncurse") == 0 || ft_strcmp(av[i], "-n") == 0)
	{
		p->visu = 2;
		return (2);
	}
	return (1);
}

static int	treat(char **av, t_env *p, int ac)
{
	int j;
	int i;

	if (!(i = ft_treat_visu(av, p, ac)))
		return (0);
	ft_initplayers(p);
	if (i < ac && ft_strcmp(av[i], "-p") == 0)
	{
		if (i + 2 >= ac || (j = ft_atoi_re(av[i + 1])) <= 0)
			return (0);
		return (createplayers(av, ac, i, p));
	}
	j = 1;
	while (i < ac && j <= MAX_PLAYERS)
	{
		if (!(createplay(&p->play[j - 1], av[i], j)))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int			nbplayers(t_env *p)
{
	int i;

	p->nbplayers = 0;
	i = 0;
	while (i < MAX_PLAYERS && p->play[i].id_player != 0)
		i++;
	p->nbplayers = i;
	if (p->nbplayers > MAX_PLAYERS || p->nbplayers == 0)
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_env	p;

	p.visu = 0;
	if (ac == 1)
		return (ft_usage());
	p.op_tab = buildtab();
	p.process = NULL;
	p.dump = -1;
	if (!(treat(av, &p, ac)) || !(nbplayers(&p)))
		return (ft_usage());
	if (!(init_arena(&p)))
	{
		ft_printf("Failing to create process\n");
		ft_clean_proc(&p.process);
		return (0);
	}
	if (p.visu == 2)
		init_ncurses();
	if (!(loop(&p)))
		return ((p.visu == 2) ? exit_ncurses(&p, 0) : 0);
	return ((p.visu == 2) ? exit_ncurses(&p, 1) : 0);
}
