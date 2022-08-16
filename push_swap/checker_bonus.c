/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:49:58 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 15:40:33 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "gnl/get_next_line.h"

static int	write_error(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	else if (i == 0)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	return (0);
}

static int	ft_is_it(char *str, char const *ch)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != ch[i])
			return (0);
		i++;
	}
	if (str[i] == '\0' && ch[i] == '\0')
		return (1);
	else
		return (0);
}

static void	make_action(char *str, t_data **l1, t_data **l2)
{
	if (ft_is_it(str, "ra\n"))
		ft_rotate(l1, NULL);
	else if (ft_is_it(str, "rb\n"))
		ft_rotate(l2, NULL);
	else if (ft_is_it(str, "rr\n"))
		ft_double_rotate(l1, l2, NULL);
	else if (ft_is_it(str, "rra\n"))
		ft_re_rotate(l1, NULL);
	else if (ft_is_it(str, "rrb\n"))
		ft_re_rotate(l2, NULL);
	else if (ft_is_it(str, "rrr\n"))
		ft_double_re_rotate(l1, l2, NULL);
	else if (ft_is_it(str, "pa\n"))
		ft_push(l2, l1, NULL);
	else if (ft_is_it(str, "pb\n"))
		ft_push(l1, l2, NULL);
	else if (ft_is_it(str, "sa\n"))
		ft_swap(l1, NULL);
	else if (ft_is_it(str, "sb\n"))
		ft_swap(l2, NULL);
	else if (ft_is_it(str, "ss\n"))
		ft_double_swap(l1, l2, NULL);
	else if (str)
		exit(write_error(1));
}

static void	check_it(t_data *list, t_data *s_list)
{
	t_data	*count;

	count = list;
	while (count->next)
	{
		if (count->number > count->next->number)
			exit(write_error(0));
		count = count->next;
	}
	if (!s_list)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	t_data		*list;
	t_data		*s_list;
	char		*str;

	str = "test";
	list = NULL;
	s_list = NULL;
	if (argc <= 1)
		return (write_error(1));
	if (fill_fract(&list, argc, argv) == 0)
		return (write_error(1));
	if (list->next == NULL)
		return (write_error(2));
	while (str)
	{
		str = get_next_line(0);
		make_action(str, &list, &s_list);
		free(str);
	}
	check_it(list, s_list);
	return (del_list(&list) + del_list(&s_list));
}
