/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:38 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/29 18:11:18 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

static void	new_line(char **arr, t_data *data, int fd)
{
	data->newline = ft_substr(arr[fd], 0, data->i + 1);
	data->buff = ft_substr(arr[fd], data->i + 1, ft_strlen(arr[fd]) - data->i);
	free(arr[fd]);
	arr[fd] = ft_strdup(data->buff);
	free(data->buff);
}

static int	reader(char **arr, t_data *data, int fd)
{
	if (arr[fd] == NULL)
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
	data.r = 1;
	if (arr[fd] == NULL)
		reader(arr, &data, fd);
	data.i = ft_strchr_pos(arr[fd], '\n');
	new_line(arr, &data, fd);
	return (data.newline);
	while (data.r > 0)
	{
		printf("%s\n", arr[fd]);
		reader(arr, &data, fd);
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
			return (data.newline);
		}
	}
	//return (NULL);
}

int main(void)
{
	char *newline;
	int fdi = open("fdi.txt", O_RDONLY);
	int fd1 = open("fd1.txt", O_RDONLY);
	int fd2 = open("fd2.txt", O_RDONLY);
	int fd3 = open("fd3.txt", O_RDONLY);
	newline = get_next_line(fdi);
	printf("%s", newline);
	newline = get_next_line(fd1);
	printf("%s", newline);
	newline = get_next_line(fd2);
	printf("%s", newline);
	newline = get_next_line(fd3);
	printf("%s", newline);
	newline = get_next_line(fd1);
	printf("%s", newline);
	newline = get_next_line(fd2);
	printf("%s", newline);
	newline = get_next_line(fd3);
	printf("%s", newline);
	newline = get_next_line(-1);
	printf("%s", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close(fdi);
	close (fd1);
	close (fd2);
	close (fd3);
	////free (newline);
	//fscanf(stdin, "c");
	return (0);
}
