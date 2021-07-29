/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:38 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/29 14:45:13 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

static char *new_line(char *strfd, t_data *data)
{
	data->newline = ft_substr(strfd, 0, data->i + 1);
	data->buff = ft_substr(strfd, data->i + 1, ft_strlen(strfd - data->i));
	free(strfd);
	strfd = data->buff;
	return (data->newline);
}

char	*get_next_line(int fd)
{
	static char *arr[4096];
	t_data data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data.r = 1;
	if (arr[fd] == NULL)
	{
		data.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		data.r = read(fd, data.buff, BUFFER_SIZE);
		if (data.r == -1 || data.r == 0)
			return (NULL);
		data.buff[data.r] = '\0';
		arr[fd] = ft_strdup(data.buff);
		free(data.buff);
	}
	data.i = ft_strchr_pos(arr[fd], '\n');
	if (data.i >= 0)
		return(new_line(arr[fd], &data));
	//while (data.r > 0)
	//{
	//	else if (data.i == -1)
	//	{
	//		data.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//		data.r = read(fd, data.buff, BUFFER_SIZE);
	//	}
	//}
	return (NULL);
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
	//newline = get_next_line(fd1);
	//printf("%s", newline);
	//newline = get_next_line(fd2);
	//printf("%s", newline);
	//newline = get_next_line(fd3);
	//printf("%s", newline);
	//newline = get_next_line(-1);
	//printf("%s", newline);
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
