/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:19:11 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:46:27 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/includes/ft_printf.h"
#include <fcntl.h>

static int	ft_freeasm(t_data *data)
{
	ft_strdel(&data->file);
	ft_lstdel(&data->labels, ft_free_labs);
	ft_strdel(&data->values);
	return (0);
}

static int	ft_parse(t_data *data)
{
	int i;

	if (!(i = ft_parsename(data)))
		return (0);
	if (!(i = ft_parsecomment(data, i)))
		return (0);
	if (!(ft_parse_labels(data, i)))
		return (0);
	if (!(data->values = ft_strnew(data->index)))
	{
		ft_printf("Allocation error\n");
		return (ft_freeasm(data));
	}
	if (!(ft_parse_code(data, i)))
		return (0);
	return (1);
}

static int	ft_format(int argc, char **argv)
{
	int	len;
	int	fd;

	if (argc != 2)
		return (-1);
	len = ft_strlen(argv[1]);
	if (len < 3)
		return (-1);
	if (argv[1][len - 1] != 's' && argv[1][len - 2] != '.')
		return (-1);
	if ((fd = open(argv[1], O_RDONLY | O_NOFOLLOW)) != -1)
		return (fd);
	return (-2);
}

int			main(int argc, char **argv)
{
	t_data	data;

	if ((data.fds = ft_format(argc, argv)) < 0)
	{
		if (data.fds == -1)
			ft_printf("usage: asm [file].s\n");
		else
			ft_printf("No such file or directory\n");
		return (0);
	}
	if (!(ft_load_file(&data)))
		return (0);
	data.labels = NULL;
	if (!(ft_parse(&data)))
		return (0);
	if (ft_creatcor(&data, argv[1]))
		ft_printf("Compilation success !\n");
	else
		ft_printf("Error creating file\n");
	ft_freeasm(&data);
	return (0);
}
