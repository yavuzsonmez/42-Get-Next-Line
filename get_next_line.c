/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:38 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/30 21:11:01 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

static void	new_line(char **arr, t_data *data, int fd)
{
	if (data->i >= 0)
	{
		data->newline = ft_substr(arr[fd], 0, data->i + 1);
		data->buff = ft_substr(arr[fd], data->i + 1, ft_strlen(arr[fd] + data->i + 1));
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
		if (arr[fd][0] == '\0')
			data->newline = NULL;
		else
			data->newline = ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = NULL;
	}
}

static int	reader(char **arr, t_data *data, int fd)
{
	if (arr[fd] == NULL)
	{
		data->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (data->buff == NULL)
			return (0);
		data->r = read(fd, data->buff, BUFFER_SIZE);
		if (data->r == -1 || data->r == 0)
		{
			free(data->buff);
			return (0);
		}
		data->buff[data->r] = '\0';
		arr[fd] = ft_strdup(data->buff);
		free(data->buff);
	}
	else
	{
		data->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (data->buff == NULL)
			return(0);
		data->r = read(fd, data->buff, BUFFER_SIZE);
		if (data->r == -1 || data->r == 0)
		{
			free(data->buff);
			return (0);
		}
		data->buff[data->r] = '\0';
		data->newline = ft_strjoin(arr[fd], data->buff);
		free(data->buff);
		free(arr[fd]);
		arr[fd] = NULL;
		arr[fd] = ft_strdup(data->newline);
		free(data->newline);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char *arr[4096];
	t_data data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (arr[fd] == NULL)
	{
		if (!reader(arr, &data, fd))
			return (NULL);
	}
	data.i = ft_strchr_pos(arr[fd], '\n');
	if (data.i >= 0 || data.r < BUFFER_SIZE)
	{
		new_line(arr, &data, fd);
		//printf("arr[fd] value : %s\n", arr[fd]);
		//printf("data.newline value : %s", data.newline);
		return (data.newline);
	}
	data.r = 1;
	while (data.r > 0)
	{
		if (!reader(arr, &data, fd) && arr[fd] == NULL)
			return (NULL);
		data.i = ft_strchr_pos(arr[fd], '\n');
		if (data.i >= 0)
		{
			new_line(arr, &data, fd);
			return (data.newline);
		}
		if (data.r == 0)
		{
			data.i = ft_strlen(arr[fd]);
			new_line(arr, &data, fd);
			free(arr[fd]);
			arr[fd] = NULL;
			return (data.newline);
		}
	}
	return (NULL);
}

/*
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
*/

/*
int main(void)
{
	char *newline;
	int fde = open("multiple_line_with_nl.txt", O_RDONLY);
	newline = get_next_line(fde);
	printf("%s", newline);
	newline = get_next_line(fde);
	printf("%s", newline);
	//newline = get_next_line(fde);
	//printf("%s", newline);
	return (0);
}
*/