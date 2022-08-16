/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:04:46 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 14:50:15 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen( const char *string)
{
	int		i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	ft_is_digit(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0' && i > 0)
		return (1);
	return (0);
}
