/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <Gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:32:03 by Gufortel          #+#    #+#             */
/*   Updated: 2019/03/08 00:37:14 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/proto.h"
#include "../libft/includes/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

void		ft_initplayers(t_env *p)
{
	int	j;

	j = 0;
	while (j < MAX_PLAYERS)
	{
		ft_bzero(p->play[j].name, PROG_NAME_LENGTH + 1);
		ft_bzero(p->play[j].comment, COMMENT_LENGTH + 1);
		ft_bzero(p->play[j].champ, CHAMP_MAX_SIZE);
		ft_bzero(p->play[j].taunt, 80);
		ft_bzero(p->play[j].taunt_2, 80);
		p->play[j].tnt = 0;
		p->play[j].size_champ = 0;
		p->play[j].id_player = 0;
		p->play[j].id_live = 0;
		j++;
	}
}

static	int	format_cor(char *str)
{
	int				len;
	int				fd;
	unsigned char	buf[4];
	int				i;

	len = ft_strlen(str);
	if (len < 5)
		return (-1);
	if (str[len - 1] != 'r' && str[len - 2] != 'o'
		&& str[len - 3] != 'c' && str[len - 4] != '.')
		return (-1);
	if ((fd = open(str, O_RDONLY | O_NOFOLLOW)) < 0)
		return (-1);
	if (read(fd, buf, 4) < 4)
		return (-1);
	i = COREWAR_EXEC_MAGIC;
	if (buf[0] == (i >> 24) && buf[1] == ((i >> 16) & 0xff)
			&& buf[2] == ((i >> 8) & 0xff) && buf[3] == (i & 0xff))
		return (fd);
	return (-1);
}

static	int	read_head(int fd, t_play *player)
{
	int		i;
	char	buf[4];

	i = read(fd, player->name, PROG_NAME_LENGTH);
	if (i < PROG_NAME_LENGTH)
		return (0);
	if ((i = read(fd, buf, 4)) < 4)
		return (0);
	if ((i = read(fd, buf, 4)) < 4)
		return (0);
	player->size_champ += (unsigned char)buf[3];
	player->size_champ += (unsigned char)buf[2] * 256;
	player->size_champ += (unsigned char)buf[1] * 65536;
	player->size_champ += (unsigned char)buf[0] * 16777216;
	i = read(fd, player->comment, COMMENT_LENGTH);
	if (i < COMMENT_LENGTH)
		return (0);
	if ((i = read(fd, buf, 4)) < 4)
		return (0);
	if (player->size_champ > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}

int			createplay(t_play *player, char *name, int j)
{
	int	fd;
	int	i;
	int	ret;

	if ((fd = format_cor(name)) == -1)
		return (((ret = close(fd)) == -1) ? 0 : ret);
	if (!(read_head(fd, player)))
		return (((ret = close(fd)) == -1) ? 0 : ret);
	i = read(fd, player->champ, player->size_champ);
	if (i < player->size_champ)
		return (((ret = close(fd)) == -1) ? 0 : ret);
	player->id_player = j;
	player->id_live = -j;
	close(fd);
	return (1);
}

int			createplayers(char **av, int ac, int i, t_env *p)
{
	int	j;

	while (i < ac)
	{
		if (ft_strcmp(av[i], "-p") == 0)
		{
			if (i + 2 >= ac || (j = ft_atoi_re(av[i + 1])) <= 0)
				return (0);
			if (j > MAX_PLAYERS || p->play[j - 1].id_player != 0)
				return (0);
			if (!(createplay(&p->play[j - 1], av[i + 2], j)))
				return (0);
		}
		i += 3;
	}
	return (1);
}
