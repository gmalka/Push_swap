/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:37:12 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 14:05:30 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_to_null(t_sum *list)
{
	list->roll_a = 0;
	list->roll_b = 0;
	list->roll_re_a = 0;
	list->roll_re_b = 0;
	list->sum = 2147483647;
}

static t_sum	more_len(int i, int mas, int lenb, int len)
{
	t_sum	new;

	ft_to_null(&new);
	if (mas > lenb / 2)
	{
		new.roll_re_a = len - i;
		new.roll_re_b = lenb - mas;
	}
	else
	{
		new.roll_re_a = len - i;
		new.roll_b = mas;
	}
	return (new);
}

static t_sum	less_len(int i, int mas, int lenb)
{
	t_sum	new;

	ft_to_null(&new);
	if (mas > lenb / 2)
	{
		new.roll_a = i;
		new.roll_re_b = lenb - mas;
	}
	else
	{
		new.roll_a = i;
		new.roll_b = mas;
	}
	return (new);
}

t_sum	ft_find_less(int *mas, int len, int lenb)
{
	t_sum		list;
	t_sum		min;
	int			i;

	i = 0;
	ft_to_null(&min);
	while (i < len)
	{
		ft_to_null(&list);
		if (i > len / 2)
			list = more_len(i, mas[i], lenb, len);
		else
			list = less_len(i, mas[i], lenb);
		list.sum = ft_make_summ(list);
		if (list.sum < min.sum)
			min = list;
		i++;
	}
	return (min);
}

void	swap(t_data **l1, t_data **l2)
{
	t_data	*count;
	int		*mas;
	t_sum	v;
	int		i;

	mas = malloc(sizeof(int) * ft_listlen(*l1));
	if (!mas)
		return ;
	ft_push(l1, l2, "pb\n");
	ft_push(l1, l2, "pb\n");
	while ((*l1)->next)
	{
		count = *l1;
		i = 0;
		while (count)
		{
			mas[i++] = ft_get_up(count->order, *l2);
			count = count->next;
		}
		v = ft_find_less(mas, ft_listlen(*l1), ft_listlen(*l2));
		ft_roll_list(v, l1, l2);
	}
	bring_last(l1, l2);
	free(mas);
}
