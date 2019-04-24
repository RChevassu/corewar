/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:16:55 by rchevass          #+#    #+#             */
/*   Updated: 2019/03/01 13:26:25 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_get_length(int n, int positive)
{
	int l;

	l = 1;
	while (n /= 10)
		l++;
	if (positive < 0)
		l++;
	l++;
	return (l);
}

static void	ft_sign(int *n, int *positive)
{
	if (*n < 0)
	{
		*positive = -1;
		*n *= -1;
	}
	else
		*positive = 1;
}

char		*ft_itoa(int n)
{
	int		length;
	char	*str;
	int		i;
	int		positive;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_sign(&n, &positive);
	length = ft_get_length(n, positive);
	str = (char *)malloc(sizeof(char) * length);
	if (!str)
		return (NULL);
	if (positive < 0)
		str[0] = '-';
	i = length - 2;
	while (i >= 0 && !(i == 0 && positive < 0))
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[length - 1] = '\0';
	return (str);
}
