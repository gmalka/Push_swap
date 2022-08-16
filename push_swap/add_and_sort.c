/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:50:22 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/05 15:50:24 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_it(int **mas, int i)
{
	int		interm;
	int		c;
	int		v;

	interm = 0;
	c = -1;
	while (++c < i)
	{
		v = -1;
		while (++v < i)
		{
			if ((*mas)[v] > (*mas)[v + 1])
			{
				interm = (*mas)[v];
				(*mas)[v] = (*mas)[v + 1];
				(*mas)[v + 1] = interm;
			}
		}
	}
}

int	add_and_sort(int **mas, t_data *list, int count)
{
	t_data	*counter;
	int		i;

	i = 0;
	counter = list;
	*mas = malloc(sizeof(int) * (count));
	if (!*mas)
		return (0);
	while (counter)
	{
		(*mas)[i++] = counter->number;
		counter = counter->next;
	}
	sort_it(mas, i - 1);
	return (1);
}
