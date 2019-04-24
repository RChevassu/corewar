/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatcor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 00:48:05 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:54:42 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/asm.h"
#include <unistd.h>
#include <fcntl.h>

static void	swap(unsigned int *src)
{
	unsigned char	*pt;
	char			tmp;

	pt = (unsigned char*)src;
	tmp = pt[3];
	pt[3] = pt[0];
	pt[0] = tmp;
	tmp = pt[2];
	pt[2] = pt[1];
	pt[1] = tmp;
}

int			ft_creatcor(t_data *data, char *filename)
{
	char	*name;
	int		i;

	if (!(name = ft_strjoin(filename, "or")))
		return (0);
	name[ft_strlen(filename) - 1] = 'c';
	data->fdcor = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR
		| S_IRUSR | S_IRGRP | S_IROTH);
	ft_strdel(&name);
	if (data->fdcor < 0)
		return (0);
	data->header.magic = COREWAR_EXEC_MAGIC;
	swap(&data->header.magic);
	data->header.prog_size = data->index;
	swap(&data->header.prog_size);
	write(data->fdcor, &data->header, sizeof(data->header));
	i = 0;
	while (i != data->index)
	{
		ft_putchar_fd(data->values[i], data->fdcor);
		i++;
	}
	close(data->fdcor);
	return (1);
}
