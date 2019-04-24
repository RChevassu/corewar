/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:47:50 by rchevass          #+#    #+#             */
/*   Updated: 2017/12/04 09:47:44 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *meule_de_foin, char *aiguille)
{
	int		i;
	int		j;

	if ((meule_de_foin[0] == '\0') && (aiguille[0] == '\0'))
		return (meule_de_foin);
	i = 0;
	while (meule_de_foin[i])
	{
		j = 0;
		while ((meule_de_foin[i + j] == aiguille[j]) && aiguille[j])
			j++;
		if (aiguille[j] == '\0')
			return (meule_de_foin + i);
		i++;
	}
	return (0);
}
