/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/21 15:10:46 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	size_t i;
	size_t k;
	static char *str;
	char *newline;
	char c;
	i = 0;
	k = 0;

	if (!str)
	{
		str = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!str || read(fd, str, BUFFER_SIZE) == 0)
			return (NULL);
	}
	while(str[i] && str[i] != '\n')
	{
		i++;
		if (str[i] == '\n')
			break ;
		else if (str[i] == '\0')
		{
			if (read(fd, &c, 1) == 0)
				return (NULL);
			str = ft_strjoin(str, &c);
		}
	}
	newline = ft_substr(str, 0, i);
	if (i < BUFFER_SIZE)
		str = ft_substr(str, i, BUFFER_SIZE);
	if (i == BUFFER_SIZE)
		free(str);
	return(newline);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *newline = get_next_line(fd);
	printf("%s\n", newline);
	newline = get_next_line(fd);
	printf("%s\n", newline);
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
