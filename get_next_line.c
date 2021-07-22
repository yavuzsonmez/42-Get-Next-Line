/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/22 17:47:02 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

void	free_data(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while(i <= 4096 - 1)
	{
		if (arr[i])
			free(arr[i++]);
	}
	free(arr);
}

char	*get_next_line(int fd)
{
	size_t i;
	int	rbytes;
	static char **arr;
	char *newline;
	char *c;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free_data(arr);
		return (NULL);
	}
	if (!arr)
	{
		arr = (char **)malloc(sizeof(char *) * (4096 + 1));
		if (!arr)
			return (NULL);
		arr[4096] = NULL;
	}
	if (!arr[fd])
	{
		arr[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!arr[fd])
		{
			free_data(arr);
			return (NULL);
		}
		rbytes = read(fd, arr[fd], BUFFER_SIZE);
		if (rbytes < 0)
		{
			free_data(arr);
			return (NULL);
		}
	}
	while (arr[fd][i] && arr[fd][i] != '\n')
		i++;
	if (arr[fd][i] == '\n')
	{
		newline = ft_substr(arr[fd], 0, i + 1);
		arr[fd] = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
	}
	else
	{
		c = (char *)ft_calloc(sizeof(char), 2);
		newline = ft_substr(arr[fd], 0, i + 1);
		while (*c != '\n')
		{
			rbytes = read(fd, c, 1);
			if (rbytes < 0)
			{
				free_data(arr);
				return (NULL);
			}
			else if (rbytes == 0)
				break ;
			newline = ft_strjoin(newline, c);
		}

		free(c);
		arr[fd] = ft_substr(arr[fd], i, BUFFER_SIZE - i - 1);
	}
	if (rbytes == 0)
		free_data(arr);
	return (newline);
}

int main(void)
{
	//printf("OPEN MAX %d\n", OPEN_MAX);
	//int fd1 = open("fd1.txt", O_RDONLY);
	//int fd2 = open("fd2.txt", O_RDONLY);
	//int fd3 = open("fd3.txt", O_RDONLY);
	char *newline = get_next_line(-54);
	printf("%s", newline);
	//newline = get_next_line(fd2);
	//printf("%s", newline);
	//newline = get_next_line(fd3);
	//printf("%s", newline);
	//newline = get_next_line(fd1);
	//printf("%s", newline);
	//newline = get_next_line(fd2);
	//printf("%s", newline);
	//newline = get_next_line(fd3);
	//printf("%s", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	//close (fd1);
	//close (fd2);
	//close (fd3);
	//free (newline);
	//fscanf(stdin, "c");
	return (0);
}

