/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/19 18:31:15 by ysonmez          ###   ########.fr       */
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
	static char c;
	char *str;
	size_t		i;
	char *newline;
	//char *c;

	//c = (char *)malloc(1);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	while(str[i] && str[i] != '\n')
		i++;
	c = str[i];
	newline = ft_substr(str, 0, i);
	//ft_strjoin(str, c);
	if (c == '\n')
	return(newline);
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
