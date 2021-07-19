/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/19 15:12:20 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	//static char c;
	if (fd < 0)
		return (NULL);
	char *str;
	char *c;

	c = NULL;
	str = (char *)malloc(sizeof(char));
	read(fd, &c, 1);
	ft_strjoin(str, c);
	return(str);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *newline = get_next_line(fd);
	printf("%s\n", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd);
	return (0);
}
