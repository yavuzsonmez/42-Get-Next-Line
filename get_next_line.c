/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/20 14:28:42 by ysonmez          ###   ########.fr       */
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
	char *str;
	char *catstr;
	char *newline;
	char c;
	k = 0;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, str, BUFFER_SIZE) == 0)
		return (NULL);
	str[BUFFER_SIZE] = '\0';
	while(str[i] && str[i] != '\n')
	{
		i++;
		if (str[i] == '\n')
			break;
		else if (str[i] == '\0')
		{
			if (read(fd, &c, 1) == 0)
				return (NULL);
			catstr = ft_strjoin(str, &c);
			free(str);
		}

	}
	newline = ft_substr(str, 0, i);
	free(str);
	return(newline);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *newline = get_next_line(fd);
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
