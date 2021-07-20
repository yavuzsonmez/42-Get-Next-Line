/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:31:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/20 15:27:46 by ysonmez          ###   ########.fr       */
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
	char *catstr;
	char *newline;
	char c;
	k = 0;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, str, BUFFER_SIZE) == 0)
		return (NULL);
	str[BUFFER_SIZE] = '\0';
	catstr = str;
	while(str[i] && str[i] != '\n')
	{
		i++;
		if (str[i] == '\n')
			break ;
		else if (str[i] == '\0')
		{
			if (read(fd, &c, 1) == 0)
				return (NULL);
			catstr = ft_strjoin(str, &c);
		}
	}
	newline = ft_substr(catstr, 0, i);
	str = ft_substr(str, i, BUFFER_SIZE);
	free(str);
	if (catstr)
		free(catstr);
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
