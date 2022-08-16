/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:00:52 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:11:23 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char			**ft_get_str_lines(char const *s,
						char c, int nb_strs, char **tab);

static void			ft_get_next_str(char **next_str,
						unsigned int *next_str_len, char c);

static unsigned int	ft_get_nb_strs(char const *s, char c);

static char			**ft_free(char **tab, int i);

static char	**ft_free(char **tab, int i)
{
	int	t;

	t = 0;
	while (t <= i)
	{
		free(tab[t]);
		t++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int	i;

	*next_str = *next_str + *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

static char	**ft_get_str_lines(char const *s, char c, int nb_strs, char **tab)
{
	char			*str;
	unsigned int	len;
	int				i;

	str = (char *)s;
	len = 0;
	i = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&str, &len, c);
		tab[i] = ft_substr(str, 0, len);
		if (!tab[i])
			return (ft_free(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	int				i;
	int				nb_strs;

	i = -1;
	if (!s || s[0] == '\0')
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	tab = (char **)malloc((nb_strs + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = ft_get_str_lines(s, c, nb_strs, tab);
	while (tab[++i])
		if (!ft_is_digit(tab[i]))
			return (0);
	return (tab);
}
