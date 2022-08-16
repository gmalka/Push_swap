/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:42:13 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:48:39 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_data **list, char *name)
{
	t_data	*new;

	if (!*list)
		return ;
	new = *list;
	(*list) = (*list)->next;
	new->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->pre = new;
	new->pre = (*list);
	(*list)->next = new;
	(*list)->pre = NULL;
	if (name)
		write(1, name, 3);
}

void	ft_double_swap(t_data **l1, t_data **l2, char *name)
{
	ft_swap(l1, NULL);
	ft_swap(l2, NULL);
	if (name)
		write(1, name, 3);
}

void	ft_push(t_data **l1, t_data **l2, char *name)
{
	t_data	*new;

	if (!*l1)
		return ;
	new = (*l1)->next;
	if (new)
		new->pre = NULL;
	(*l1)->pre = NULL;
	if (*l2)
	{
		(*l2)->pre = *l1;
		(*l1)->next = *l2;
	}
	(*l1)->next = *l2;
	*l2 = *l1;
	*l1 = new;
	if (name)
		write(1, name, 3);
}

void	ft_re_rotate(t_data **list, char *name)
{
	t_data	*new;

	if (!*list || (!(*list)->pre && !(*list)->next))
		return ;
	new = *list;
	while (new->next)
		new = new->next;
	new->pre->next = NULL;
	new->pre = NULL;
	new->next = *list;
	(*list)->pre = new;
	*list = new;
	if (name)
		write(1, name, 4);
}

void	ft_double_re_rotate(t_data **l1, t_data **l2, char *name)
{
	ft_re_rotate(l1, NULL);
	ft_re_rotate(l2, NULL);
	if (name)
		write(1, name, 4);
}
