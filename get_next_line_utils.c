/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:23:25 by smazouz           #+#    #+#             */
/*   Updated: 2021/11/23 15:30:17 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strdup(char *s1)
{
	unsigned int	s;
	unsigned int	i;
	char			*dst;

	i = 0;
	s = 0;
	while (s1[s] != '\0')
		s++;
	dst = (char *)malloc((s + 1) * sizeof(*dst));
	if (dst == 0)
		return (NULL);
	while (i < s)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		j;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	j = -1;
	i = (ft_strlen(s1)) + (ft_strlen(s2));
	dst = (char *)malloc((i + 1) * sizeof(*dst));
	if (dst == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		dst[i] = s2[j];
		i++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

int	check(char *s)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0' && s[x] != '\n' )
		x++;
	if (s[x] == '\n')
		return (x);
	else
		return (-1);
}
