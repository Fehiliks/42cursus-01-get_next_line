/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:00:02 by fgardine          #+#    #+#             */
/*   Updated: 2023/05/24 21:05:20 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freethings(char *str)
{
	free(str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*malloc1(void)
{
	char	*s1;

	s1 = malloc(1 * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc1();
		if (s1 == NULL)
			return (NULL);
	}
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (freethings(s1));
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	if (newstr[0] == '\0')
		return (freethings(newstr));
	return (newstr);
}
