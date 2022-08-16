/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:36:23 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:12:46 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_data *s_list)
{
	t_data	*counter;
	int		current;
	int		curi;
	int		cur1;
	int		i;

	current = s_list->order;
	curi = 0;
	cur1 = 1;
	i = 0;
	counter = s_list;
	while (counter)
	{
		cur1 = counter->order;
		if (cur1 > current)
		{
			curi = i;
			current = cur1;
		}
		counter = counter->next;
		i++;
	}
	return (curi);
}

int	find_min(t_data *s_list)
{
	t_data	*counter;
	int		current;
	int		curi;
	int		cur1;
	int		i;

	current = s_list->order;
	curi = 0;
	cur1 = 1;
	i = 0;
	counter = s_list;
	while (counter)
	{
		cur1 = counter->order;
		if (cur1 < current)
		{
			curi = i;
			current = cur1;
		}
		counter = counter->next;
		i++;
	}
	return (curi);
}

int	ft_get_up(int order, t_data *s_list)
{
	int		cur1;
	int		cur2;
	int		n;

	n = 0;
	if (order > ft_goup(s_list, find_max(s_list)))
		return (find_max(s_list));
	if (order < ft_goup(s_list, find_min(s_list)))
		return (find_min(s_list) + 1);
	while (1)
	{
		cur1 = ft_goup(s_list, n);
		cur2 = ft_goup(s_list, n - 1);
		if (order > cur1 && order < cur2)
			return (n);
		n++;
	}
	return (n);
}

void	ft_roll_list(t_sum list, t_data **l1, t_data **l2)
{
	while (list.roll_a > 0 && list.roll_b > 0)
	{
		ft_double_rotate(l1, l2, "rr\n");
		list.roll_a--;
		list.roll_b--;
	}
	while (list.roll_re_b > 0 && list.roll_re_a > 0)
	{
		ft_double_re_rotate(l1, l2, "rrr\n");
		list.roll_re_a--;
		list.roll_re_b--;
	}
	while (list.roll_re_a-- > 0)
		ft_re_rotate(l1, "rra\n");
	while (list.roll_re_b-- > 0)
		ft_re_rotate(l2, "rrb\n");
	while (list.roll_a-- > 0)
		ft_rotate(l1, "ra\n");
	while (list.roll_b-- > 0)
		ft_rotate(l2, "rb\n");
	ft_push(l1, l2, "pb\n");
}

int	ft_make_summ(t_sum list)
{
	int		i1;
	int		i2;

	if (list.roll_re_a >= list.roll_re_b)
		i1 = list.roll_re_a;
	else
		i1 = list.roll_re_b;
	if (list.roll_a >= list.roll_b)
		i2 = list.roll_a;
	else
		i2 = list.roll_b;
	return (i1 + i2);
}
