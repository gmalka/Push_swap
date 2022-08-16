/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:09:55 by gmalka            #+#    #+#             */
/*   Updated: 2021/12/09 13:32:31 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *str, char *ch)
{
	char	*buf;
	int		i;
	int		j;

	buf = malloc(ft_tf_strlen(str) + ft_tf_strlen(ch) + 1);
	i = 0;
	j = 0;
	while (buf && str && str[i])
	{
		buf[i] = str[i];
		i++;
	}
	free(str);
	if (!buf)
		return (0);
	while (ch[j])
		buf[i++] = ch[j++];
	buf[i] = '\0';
	if (i == 0)
	{
		free(buf);
		return (0);
	}
	return (buf);
}

static char	*delimeter_l(char *str)
{
	char	*hc;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		hc = malloc(i + 2);
	else
		hc = malloc(i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		hc[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		hc[i] = str[i];
		i++;
	}
	hc[i] = '\0';
	return (hc);
}

static char	*delimeter_r(char *str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (ft_tf_strlen(str) - i < 1)
	{
		free(str);
		return (0);
	}
	buf = malloc(ft_tf_strlen(str) - i + 1);
	while (buf && str[i] != '\0')
		buf[j++] = str[i++];
	free(str);
	if (!buf)
		return (0);
	buf[j] = '\0';
	return (buf);
}

static char	*do_next_line(int fd, char *str)
{
	char	*ch;
	int		i;

	i = 1;
	ch = malloc(BUFFER_SIZE + 1);
	if (!ch)
		return (0);
	while (!ft_findch(str, '\n') && i > 0)
	{
		i = read(fd, ch, BUFFER_SIZE);
		if (i == -1)
		{
			free(ch);
			return (0);
		}
		ch[i] = '\0';
		str = ft_strjoin(str, ch);
	}
	free(ch);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*ch;

	if (fd < 0)
		return (0);
	str = do_next_line(fd, str);
	ch = delimeter_l(str);
	str = delimeter_r(str);
	return (ch);
}
