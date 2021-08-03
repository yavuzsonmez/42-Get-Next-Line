/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:38 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/03 09:25:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

static char	*new_line(char **arr, t_data *data, int fd)
{
	if (data->i >= 0)
	{
		data->newline = ft_substr(arr[fd], 0, data->i + 1);
		data->buff = ft_strdup(arr[fd] + data->i + 1);
		free(arr[fd]);
		arr[fd] = NULL;
		arr[fd] = ft_strdup(data->buff);
		free(data->buff);
		if (arr[fd][0] == '\0')
		{
			free(arr[fd]);
			arr[fd] = NULL;
		}
	}
	else
	{
		data->newline = ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = NULL;
	}
	return (data->newline);
}

static int	fd_firstcall(char **arr, t_data *data, int fd)
{
	data->r = read(fd, data->buff, BUFFER_SIZE);
	if (data->r == -1 || data->r == 0)
	{
		free(data->buff);
		return (0);
	}
	data->buff[data->r] = '\0';
	arr[fd] = ft_strdup(data->buff);
	return (1);
}

static int	fd_nextcall(char **arr, t_data *data, int fd)
{
	data->r = read(fd, data->buff, BUFFER_SIZE);
	if (data->r == -1 || data->r == 0)
	{
		free(data->buff);
		return (0);
	}
	data->buff[data->r] = '\0';
	data->newline = ft_strjoin(arr[fd], data->buff);
	free(arr[fd]);
	arr[fd] = NULL;
	arr[fd] = ft_strdup(data->newline);
	free(data->newline);
	return (1);
}

static int	reader(char **arr, t_data *data, int fd)
{
	data->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (data->buff == NULL)
		return (0);
	if (arr[fd] == NULL)
	{
		if (!fd_firstcall(arr, data, fd))
			return (0);
	}
	else
	{
		if (!fd_nextcall(arr, data, fd))
			return (0);
	}
	free(data->buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*arr[4096];
	t_data		data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data.r = BUFFER_SIZE;
	if (arr[fd] == NULL)
	{
		if (!reader(arr, &data, fd))
			return (NULL);
	}
	data.i = ft_strchr_pos(arr[fd], '\n');
	if (data.i >= 0 || data.r < BUFFER_SIZE)
		return (new_line(arr, &data, fd));
	while (data.r > 0)
	{
		if (!reader(arr, &data, fd) && arr[fd] == NULL)
			return (NULL);
		data.i = ft_strchr_pos(arr[fd], '\n');
		if (data.i >= 0 || data.r == 0)
			return (new_line(arr, &data, fd));
	}
	return (NULL);
}


int main(void)
{
	char *newline;
	int fd = open("multiple_line_with_nl.txt", O_RDONLY);


	newline = get_next_line(fd);
	printf("%s", newline);

	newline = get_next_line(fd);
	printf("%s", newline);

	newline = get_next_line(fd);
	printf("%s", newline);


	close(fd);
	return (0);
}

