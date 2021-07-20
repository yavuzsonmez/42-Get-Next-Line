/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/20 10:40:26 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	t_struct	data;
	static char *str;
	char *rd;
	size_t		i;
	char *newline;

	i = 0;
	//if (!str)
	//	str = (char *)malloc(sizeof(char));
	//if (str[i] && str[i] == '\n')
	//	i++;
	//else
	//{
	//	free(str);
	//	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//	read(fd, str, BUFFER_SIZE);
	//	str[BUFFER_SIZE] = '\0';
	//}
	rd = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str[i] != '\n')
	if (read(fd, rd, BUFFER_SIZE) == 0)
		return (NULL);
	rd[BUFFER_SIZE] = '\0';
	while(str[i] && str[i] != '\n')
		i++;
	str = ft_substr(rd, 0, BUFFER_SIZE);
	newline = ft_substr(str, 0, i);
	free(rd);
	str = ft_substr(str, 0, i);
	return(newline);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *newline = get_next_line(fd);
	while (newline)
	{
		printf("%s\n", newline);
		newline = get_next_line(fd);
	}
	close (fd);
	fscanf(stdin, "c");
	return (0);
}
