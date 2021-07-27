#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char *arr[4096];
	t_data data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (arr[fd] == NULL)
	{
		data.r = read(fd, data.buff, BUFFER_SIZE);
		data.buff[data.r] = '\0';
		arr[fd] = ft_strdup(data.buff);
	}
	data.i = ft_strchr_pos(arr[fd], '\n');
	if (data.i >= 0)
	{
		data.newline = ft_substr(arr[fd], 0, data.i + 1);
		data.tmp = ft_substr(arr[fd], data.i + 1, BUFFER_SIZE - data.i - 1);
		free(arr[fd]);
		arr[fd] = data.tmp;
	}
	else
	{
		data.r = read(fd, data.buff, BUFFER_SIZE);
		while (data.r > 0)
		{
			data.tmp = ft_strjoin(arr[fd], data.buff);
			free(arr[fd]);
			arr[fd] = data.tmp;
			data.i = ft_strchr_pos(arr[fd], '\n');
			if (data.i >= 0)
				break ;
			data.r = read(fd, data.buff, BUFFER_SIZE);
		}
		data.newline = ft_substr(arr[fd], 0, data.i + 1);
		arr[fd] = ft_substr(arr[fd], data.i + 1, BUFFER_SIZE - data.i - 1);
	}
	if (data.r == 0)
		free(arr[fd]);
	return (data.newline);
}

int main(void)
{
	char *newline;
	int fd1 = open("fd1.txt", O_RDONLY);
	int fd2 = open("fd2.txt", O_RDONLY);
	int fd3 = open("fd3.txt", O_RDONLY);
	newline = get_next_line(fd1);
	printf("%s", newline);
	newline = get_next_line(fd2);
	printf("%s", newline);
	newline = get_next_line(fd3);
	printf("%s", newline);
	newline = get_next_line(fd1);
	printf("%s", newline);
	newline = get_next_line(fd2);
	printf("%s", newline);
	newline = get_next_line(fd3);
	printf("%s", newline);
	newline = get_next_line(-1);
	printf("%s", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd1);
	close (fd2);
	close (fd3);
	//free (newline);
	//fscanf(stdin, "c");
	return (0);
}
