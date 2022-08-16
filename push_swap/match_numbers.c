/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:45:51 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/05 15:45:52 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	match_numbers(t_data **list, int *mas)
{
	t_data	*count;
	int		i;

	count = *list;
	while (count)
	{
		i = 0;
		while (mas[i] != count->number)
			i++;
		count->order = i + 1;
		count = count->next;
	}
}
