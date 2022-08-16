/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:45:11 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:14:15 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_rotate(t_data **l1, t_data **l2, char *name)
{
	ft_rotate(l1, NULL);
	ft_rotate(l2, NULL);
	if (name)
		write(1, name, 3);
}

void	ft_rotate(t_data **list, char *name)
{
	t_data	*new;
	t_data	*ferst;

	if (!*list || (!(*list)->pre && !(*list)->next))
		return ;
	ferst = *list;
	new = *list;
	(*list) = (*list)->next;
	while (new->next)
		new = new->next;
	new->next = ferst;
	ferst->pre = new;
	ferst->next = NULL;
	(*list)->pre = NULL;
	if (name)
		write(1, name, 3);
}
