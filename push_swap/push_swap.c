/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:06:34 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 15:44:35 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_double(t_data *list)
{
	t_data	*count;
	t_data	*count2;

	count = list;
	while (count->next)
	{
		count2 = count->next;
		while (count2)
		{
			if (count2->number == count->number)
				return (write(1,
						"Error: There are 2 or more duplicate numbers\n", 45));
			count2 = count2->next;
		}
		count = count->next;
	}
	return (0);
}

static int	ft_is_sorted(t_data *list)
{
	t_data	*count;

	count = list;
	while (count)
	{
		if (count->next && count->number > count->next->number)
			return (0);
		count = count->next;
	}
	return (write(1, "Error: It is Sorted!\n", 21));
}

static int	write_error(void)
{
	write(1, "Error: ENTER NUMBERs M@#F%%CKER!!\n", 34);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		*list;
	t_data		*s_list;
	int			t;
	int			*int_mas;

	list = NULL;
	s_list = NULL;
	if (argc <= 1)
	{
		write(1, "Error: Please enter arguments\n", 30);
		return (0);
	}
	t = fill_fract(&list, argc, argv);
	if (t == 0)
		return (del_list(&list) + write_error());
	if (ft_is_double(list) > 0 || ft_is_sorted(list) > 0
		|| !add_and_sort(&int_mas, list, t) || t <= 0)
		return (del_list(&list));
	match_numbers(&list, int_mas);
	if (t <= 5)
		sort_three_list(&list, &s_list, t);
	else
		swap(&list, &s_list);
	free(int_mas);
	return (del_list(&list) + del_list(&s_list));
}
