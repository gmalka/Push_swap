/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:50:29 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 14:50:58 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct d_data {
	struct d_data	*pre;
	struct d_data	*next;
	int				number;
	int				order;
}					t_data;

int		fill_fract(t_data **list, int argc, char **argv);

int		del_list(t_data **list);

int		del_list(t_data **list);

char	**ft_split(char const *s, char c);

size_t	ft_strlen( const char *string);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_swap(t_data **list, char *name);

void	ft_double_swap(t_data **l1, t_data **l2, char *name);

void	ft_push(t_data **l1, t_data **l2, char *name);

void	ft_re_rotate(t_data **list, char *name);

void	ft_double_re_rotate(t_data **l1, t_data **l2, char *name);

void	ft_double_rotate(t_data **l1, t_data **l2, char *name);

void	ft_rotate(t_data **list, char *name);

#endif
