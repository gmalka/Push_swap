/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:19:00 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:43:48 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	roll_a_stack(t_data **l1);

void	bring_last(t_data **l1, t_data **l2)
{
	t_data	*count;
	int		i;

	count = *l2;
	i = 0;
	while (count && (count->order + 1) != ((*l1)->order))
	{
		i++;
		count = count->next;
	}
	if (i <= ft_listlen(*l2) / 2)
		while (i-- > 0)
			ft_rotate(l2, "rb\n");
	else
	{
		i = ft_listlen(*l2) - i;
		while (i-- > 0)
			ft_re_rotate(l2, "rrb\n");
	}
	while (*l2)
		ft_push(l2, l1, "pa\n");
	roll_a_stack(l1);
}

static void	roll_a_stack(t_data **l1)
{
	t_data	*count;
	int		i;
	int		t;

	i = 0;
	t = ft_goup(*l1, find_min(*l1));
	count = *l1;
	while (t != count->order)
	{
		i++;
		count = count->next;
	}
	if (i < ft_listlen(*l1) / 2)
		while (i-- > 0)
			ft_rotate(l1, "ra\n");
	else
	{
		i = ft_listlen(*l1) - i;
		while (i-- > 0)
			ft_re_rotate(l1, "rra\n");
	}
}

static void	sort_five(t_data **list, t_data **s_list, int t)
{
	int		c;

	while (t > 3)
	{
		c = find_min(*list);
		if (c <= t / 2)
			while (c--)
				ft_rotate(list, "ra\n");
		else
		{
			c = t - c;
			while (c--)
				ft_re_rotate(list, "rra\n");
		}
		ft_push(list, s_list, "pb\n");
		t--;
	}
	sort_three_list(list, s_list, t);
	while (*s_list)
		ft_push(s_list, list, "pa\n");
}

void	sort_three_list(t_data **list, t_data **list2, int t)
{
	if (t > 3)
		sort_five(list, list2, t);
	else
	{
		if ((*list)->order > (*list)->next->order)
			ft_swap(list, "sa\n");
		if (t == 3)
		{
			if (ft_goup(*list, 1) > ft_goup(*list, 2))
				ft_re_rotate(list, "rra\n");
			if ((*list)->order > (*list)->next->order)
				ft_swap(list, "sa\n");
		}
	}
}
