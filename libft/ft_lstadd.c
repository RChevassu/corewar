/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 00:54:17 by jlemahie          #+#    #+#             */
/*   Updated: 2019/03/01 13:32:57 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstappend(t_list *list, t_list *new)
{
	if (list && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		new->next = NULL;
	}
}

void	ft_lstinsert(t_list **alst, t_list *new)
{
	if (*alst && new && new->next == NULL)
	{
		new->next = (*alst)->next;
		(*alst)->next = new;
	}
}
