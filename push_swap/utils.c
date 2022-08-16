/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:36:35 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 14:45:31 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_last_list(t_data *list)
{
	t_data	*counter;

	counter = list;
	while (counter->next)
		counter = counter->next;
	return (counter->order);
}

int	ft_goup(t_data *list, int n)
{
	int		i;
	t_data	*coun;

	coun = list;
	i = 0;
	if (!coun)
		return (0);
	if (n == -1)
		return (ft_get_last_list(list));
	while (coun->next && i < n)
	{
		coun = coun->next;
		i++;
	}
	if (i != n)
		return (list->order);
	return (coun->order);
}

int	ft_listlen(t_data *list)
{
	int		i;
	t_data	*count;

	i = 0;
	count = list;
	while (count)
	{
		count = count->next;
		i++;
	}
	return (i);
}
