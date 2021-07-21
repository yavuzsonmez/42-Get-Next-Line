/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/21 19:31:49 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd)
{
	size_t i;
	static char **arr;
	char *newline;
	char c;

	i = 0;
	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!arr)
	{
		arr = (char **)malloc(sizeof(char *) * (10240 + 1));
		if (!arr)
			return (NULL);
		arr[10240] = NULL;
	}
	if (!arr[fd])
	{
		arr[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!read(fd, arr[fd], BUFFER_SIZE))
			return (NULL);
	}
	while(arr[fd][i] && arr[fd][i] != '\n')
		i++;
	if (arr[fd][i] == '\n')
	{
		newline = ft_substr(arr[fd], 0, ++i);
		arr[fd] = ft_substr(arr[fd], i, BUFFER_SIZE - i - 1);
	}
	else
	{
		c = 'q';
		while (c != '\n')
		{
			if (!read(fd, &c, 1))
				return (NULL);
			newline = ft_strjoin(arr[fd], &c);
		}
	}
	if (arr[fd][i] == '\0')
		free(arr[fd]);
	return(newline);
}

int main(void)
{

	//printf("OPEN MAX %d\n", OPEN_MAX);
	int fd1 = open("fd1.txt", O_RDONLY);
	int fd2 = open("fd2.txt", O_RDONLY);
	int fd3 = open("fd3.txt", O_RDONLY);
	char *newline = get_next_line(fd1);
	printf("%s", newline);
	newline = get_next_line(fd2);
	printf("%s", newline);
	//newline = get_next_line(fd3);
	//printf("%s\n", newline);
	//newline = get_next_line(fd1);
	//printf("%s\n", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd1);
	close (fd2);
	close (fd3);
	free (newline);
	//fscanf(stdin, "c");
	return (0);
}
