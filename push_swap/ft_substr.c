/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:07:06 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/05 15:19:40 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if (j < len)
		len = j;
	str = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	if (start < ft_strlen(s))
		while (i < len && s[start])
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
