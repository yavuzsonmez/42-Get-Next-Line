/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/21 17:20:41 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	size_t i;
	static char *str;
	char *newline;
	char c;

	i = 0;
	if (fd == - 1)
		return (NULL);
	if (!str)
	{
		str = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!str || !read(fd, str, BUFFER_SIZE))
			return (NULL);
	}
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		newline = ft_substr(str, 0, i);
		str = ft_substr(str, i, BUFFER_SIZE - i - 1);
	}
	else
	{
		while (c != '\n')
		{
			if (!read(fd, &c, 1))
				return (NULL);
			newline = ft_strjoin(str, &c);
		}
	}
	if (str[i] == '\0')
		free(str);
	return(newline);
}

int main(void)
{

	int fd1 = open("fd1.txt", O_RDONLY);
	int fd2 = open("fd2.txt", O_RDONLY);
	int fd3 = open("fd3.txt", O_RDONLY);
	char *newline = get_next_line(fd1);
	printf("%s\n", newline);
	newline = get_next_line(fd2);
	printf("%s\n", newline);
	newline = get_next_line(fd3);
	printf("%s\n", newline);
	newline = get_next_line(fd1);
	printf("%s\n", newline);
	//newline = get_next_line(fd);
	//printf("%s\n", newline);
	//newline = get_next_line(fd);
	//printf("%s\n", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd);
	fscanf(stdin, "c");
	return (0);
}
