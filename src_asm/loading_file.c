/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:26:21 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:53:56 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/asm.h"
#include <unistd.h>
#include <fcntl.h>

static	char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel(&s1);
	return (str);
}

static	int		ft_error_loading(t_data *data, char *s2)
{
	if (data->file)
		ft_strdel(&data->file);
	if (s2)
		ft_strdel(&s2);
	ft_printf("Error loading file\n");
	close(data->fds);
	return (0);
}

int				ft_load_file(t_data *data)
{
	int		a;
	char	*buffer;

	if (!(buffer = ft_strnew(50)))
	{
		close(data->fds);
		return (0);
	}
	if (!(data->file = ft_strnew(1)))
		return (ft_error_loading(data, buffer));
	a = 50;
	while (a == 50)
	{
		if ((a = read(data->fds, buffer, 50)) < 0)
			return (ft_error_loading(data, buffer));
		if (!(data->file = ft_strjoinfree(data->file, buffer)))
			return (ft_error_loading(data, buffer));
		ft_bzero(buffer, 50);
	}
	ft_strdel(&buffer);
	close(data->fds);
	return (1);
}
