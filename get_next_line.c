/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:08:06 by salfaraw          #+#    #+#             */
/*   Updated: 2026/01/03 15:54:31 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_and_store(int fd, char *store)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	if (!store)
		store = ft_strjoin("", "");
	bytes = 1;
	while (!ft_strchr(store, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(store);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = store;
		store = ft_strjoin(store, buffer);
		free(tmp);
	}
	return (store);
}

static char	*extract_line(char *store)
{
	int	i;

	i = 0;
	if (!store || !store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	return (ft_substr(store, 0, i));
}

static char	*clean_store(char *store)
{
	int		i;
	char	*new_store;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	new_store = ft_substr(store, i + 1, ft_strlen(store) - i - 1);
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_and_store(fd, store);
	if (!store)
		return (NULL);
	line = extract_line(store);
	store = clean_store(store);
	return (line);
}
