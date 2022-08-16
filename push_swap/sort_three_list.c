/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:27:33 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/08 15:27:34 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_list(t_data **list)
{
	if ((*list)->order > (*list)->next->order)
		ft_swap(list, "sa\n");
	if (ft_goup(*list, 1) > ft_goup(*list, 2))
		ft_re_rotate(list, "rra\n");
	if ((*list)->order > (*list)->next->order)
		ft_swap(list, "sa\n");
}
