/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:48:20 by fgardine          #+#    #+#             */
/*   Updated: 2023/05/25 22:12:34 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *linez)
{
	int		i;
	int		mal;
	char	*ret;

	mal = 1;
	i = 0;
	while (linez[i] && linez[i] != '\n')
		i++;
	if (linez[i] == '\n')
		mal = 2;
	ret = malloc(sizeof(char) * (i + mal));
	if (ret == NULL)
		return (NULL);
	ret[i + mal - 1] = '\0';
	while (i >= 0)
	{
		ret[i] = linez[i];
		i--;
	}
	return (ret);
}

char	*trim_excess(char *linez)
{
	int		i;
	int		b;
	char	*excess;

	i = 0;
	b = 0;
	while (linez[i] && linez[i] != '\n')
		i++;
	if (!linez[i])
	{
		free(linez);
		return (NULL);
	}
	excess = malloc(sizeof(char) * (ft_strlen(linez + i) + 1));
	if (excess == NULL)
	{
		free(linez);
		return (NULL);
	}
	i++;
	while (linez[i])
		excess[b++] = linez[i++];
	excess[b] = '\0';
	free(linez);
	return (excess);
}

char	*read_time(int fd, char *store)
{
	char	*buf;
	int		readbyte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readbyte = 1;
	while (!ft_strchr(store, '\n') && (readbyte != 0))
	{
		readbyte = read(fd, buf, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readbyte] = '\0';
		store = ft_strjoin(store, buf);
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*lineret;
	static char	*store[500];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_time(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	lineret = find_newline(store[fd]);
	store[fd] = trim_excess(store[fd]);
	return (lineret);
}
/*
#include "fcntl.h"
int	main(void)
{
	int	file;

	file = open("coolNL", O_RDONLY);

	printf("GNL OUTPUT:%s", get_next_line(file));
	printf("GNL OUTPUT:%s", get_next_line(file));
	printf("GNL OUTPUT:%s", get_next_line(file));
	printf("GNL OUTPUT:%s", get_next_line(file));
	return(0);
}
*/
/*
 * this is almost exactly the same as my non bonus, the only difference
 * being that im including a [fd] with my static char pointer which 
 * means it can be independant with up to 500 different fd things
 */
