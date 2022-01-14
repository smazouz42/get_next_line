/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:19:28 by smazouz           #+#    #+#             */
/*   Updated: 2022/01/14 16:28:25 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*last(char **s)
{
	char	*str;

	str = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (str);
}

char	*line(char *line)
{
	int		x;
	char	*s;
	int		y;

	y = 0;
	if (!line)
		return (NULL);
	s = NULL;
	x = check(line);
	if (x != -1)
	{
		s = malloc((x + 2) * sizeof(char));
		if (!s)
			return (NULL);
		while (x > y)
		{
			s[y] = line[y];
			y++;
		}
		s[y++] = '\n';
		s[y] = '\0';
	}
	return (s);
}

char	*rest(char *str)
{
	char	*s;
	int		y;
	int		x;
	int		l;

	l = ft_strlen(str);
	y = 0;
	s = ft_strdup("");
	if (!str)
		return (NULL);
	x = check(str);
	if (str[x + 1] == 0)
		return (free(str), free(s), NULL);
	if (check(str) != -1)
	{
		free(s);
		s = malloc(((l - x) + 1) * sizeof(char));
		if (!s)
			return (NULL);
		while (x < l)
			s[y++] = str[x++ + 1];
		s[y] = '\0';
	}
	return (free(str), s);
}

static char	*the_last(char **str, char **stock)
{
	char	*s;

	if (*str)
		free(*str);
	if (*stock)
	{
		if (check(*stock) != -1)
		{
			s = line(*stock);
			*stock = rest(*stock);
			return (s);
		}
		else
			return (last(stock));
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stock[65535];
	char		*str;
	int			x;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 65535)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	x = read(fd, str, BUFFER_SIZE);
	while (x > 0 && str)
	{
		str[x] = 0;
		if (!stock[fd])
			stock[fd] = ft_strdup(str);
		else
			stock[fd] = ft_strjoin(stock[fd], str);
		if (check(stock[fd]) != -1)
			break ;
		x = read(fd, str, BUFFER_SIZE);
	}
	if ((x <= 0 || str == NULL))
		return (the_last(&str, &stock[fd]));
	free(str);
	s = line(stock[fd]);
	return (stock[fd] = rest(stock[fd]), s);
}
