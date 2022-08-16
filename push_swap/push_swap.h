/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:53:35 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 14:43:56 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct d_data {
	struct d_data	*pre;
	struct d_data	*next;
	int				number;
	int				order;
}				t_data;

typedef struct d_sum {
	int		roll_a;
	int		roll_b;
	int		roll_re_a;
	int		roll_re_b;
	int		sum;
	int		position;
	int		i;
}				t_sum;

void			swap(t_data **l1, t_data **l2);

int				ft_get_up(int order, t_data *s_list);

void			ft_roll_list(t_sum list, t_data **l1, t_data **l2);

int				ft_listlen(t_data *list);

int				ft_goup(t_data *list, int n);

int				ft_get_last_list(t_data *list);

int				ft_is_digit(char *str);

void			ft_swap(t_data **list, char *name);

void			ft_double_swap(t_data **l1, t_data **l2, char *name);

void			ft_push(t_data **l1, t_data **l2, char *name);

void			ft_re_rotate(t_data **list, char *name);

void			ft_double_re_rotate(t_data **l1, t_data **l2, char *name);

void			ft_rotate(t_data **list, char *name);

void			ft_double_rotate(t_data **l1, t_data **l2, char *name);

void			match_numbers(t_data **list, int *mas);

char			*ft_substr(char const *s, unsigned int start, size_t len);

size_t			ft_strlen( const char *string);

char			**ft_split(char const *s, char c);

int				del_list(t_data **list);

int				fill_fract(t_data **list, int argc, char **argv);

void			back_to_future(t_data **list, t_data **s_list);

int				add_and_sort(int **mas, t_data *list, int count);

int				find_min(t_data *s_list);

void			sort_three_list(t_data **list, t_data **list2, int t);

void			bring_last(t_data **l1, t_data **l2);

int				ft_make_summ(t_sum list);

t_sum			ft_find_less(int *mas, int len, int lenb);

#endif
