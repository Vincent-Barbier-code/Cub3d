/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:29:05 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 18:52:16 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *str)
{
	char	*strcp;
	int		i;

	i = 0;
	strcp = (char *) malloc(ft_strlen(str) * sizeof(char) + sizeof(char));
	if (!strcp)
		return (NULL);
	while (str[i])
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	char		*scpy;
	size_t		i;
	size_t		j;

	scpy = (char *)s;
	i = 0;
	j = 0;
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		s2 = malloc(sizeof(char));
	else
		s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
			s2[j++] = scpy[i];
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*sconc;
	int		i;
	int		y;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	sconc = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!sconc)
		return (NULL);
	while (s1[i])
	{
		sconc[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
		sconc[i++] = s2[y++];
	sconc[i] = '\0';
	free((char *) s1);
	return (sconc);
}

char	*ft_strchr_gnl(const char *str, int i)
{
	char	*strcp;

	if (!str)
		return (NULL);
	strcp = (char *) str;
	while (*strcp)
	{
		if (*strcp == (char) i)
			return (strcp);
		strcp++;
	}
	if (i == 0)
		return ((char *) strcp);
	return (NULL);
}
