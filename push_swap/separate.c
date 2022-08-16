/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:37:27 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/05 15:37:28 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*ft_add_list(t_data **list)
{
	t_data	*new;

	new = *list;
	*list = (*list)->next;
	if (new->pre)
		new->pre->next = *list;
	new->pre = NULL;
	new->next = NULL;
	return (new);
}

void	separate_list(t_data **s_list, t_data **list, int t)
{
	t_data	*l1;
	t_data	*l2;
	int		i;

	i = 0;
	l1 = *list;
	while (l1 && l1->order >= (t / 2))
		l1 = l1->next;
	*s_list = ft_add_list(&l1);
	l2 = *s_list;
	while (l1)
	{
		if (l1->order < (t / 2))
		{
			l2->next = ft_add_list(&l1);
			l2->next->pre = l2;
			l2 = l2->next;
		}
		else
			l1 = l1->next;
	}
}
