/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/20 11:59:13 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	static size_t i;
	size_t k;
	char *rd;
	char *newline;

	i = 0;
	k = 0;
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

	rd = (char *)malloc(sizeof(char) * (BUFFER_SIZE + i + 1));
	read(fd, rd, BUFFER_SIZE + i);
	rd[BUFFER_SIZE] = '\0';
	//if (str[i] != '\n')
	//if (read(fd, rd, BUFFER_SIZE) == 0)
	//	return (NULL);
	//rd[BUFFER_SIZE] = '\0';
	while(rd[k] && rd[k] != '\n')
		k++;
	newline = ft_substr(rd, i, k);
	free(rd);
	return(newline);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *newline = get_next_line(fd);
	printf("%s\n", newline);
	printf("%s\n", get_next_line(fd));
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd);
	fscanf(stdin, "c");
	return (0);
}
