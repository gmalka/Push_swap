/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_delete_fract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:50:04 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 15:44:33 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	to_int(char *str)
{
	int				i;
	long int		t;
	int				minus;

	i = 0;
	t = 0;
	minus = 0;
	if (str[0] == '-')
		minus = ++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (t == 0)
			t = str[i] - '0';
		else
			t = t * 10 + (str[i] - '0');
		if (t > 2147483648 || (t > 2147483647 && minus == 0))
		{
			write(1, "Error: Enter Integer Value please\n", 34);
			exit(0);
		}
		i++;
	}
	if (minus == 1)
		t = t * -1;
	return (t);
}

static t_data	*new_list(t_data *pre, int t)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->pre = pre;
	new->next = NULL;
	new->number = t;
	new->order = 0;
	return (new);
}

int	del_list(t_data **list)
{
	t_data	*next;

	next = (*list);
	while (next)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	return (0);
}

static void	fill_list(char *str, t_data **list)
{
	t_data	*count;

	if (!*list)
	{
		*list = new_list(NULL, to_int(str));
		free(str);
		return ;
	}
	count = *list;
	while (count->next)
		count = count->next;
	count->next = new_list(count, to_int(str));
	free(str);
}

int	fill_fract(t_data **list, int argc, char **argv)
{
	int		i;
	int		c;
	int		g;
	char	**str;

	i = 0;
	g = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str || str[0] == NULL)
		{
			while (str && *str)
				free((*str)++);
			free(str);
			return (0);
		}
		c = 0;
		while (str[c])
			fill_list(str[c++], list);
		g = g + c;
		free(str);
	}
	return (g);
}
