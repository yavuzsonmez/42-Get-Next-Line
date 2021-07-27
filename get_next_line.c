#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char *arr[4096];
	t_data *data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (arr[fd] == NULL)
	{
		data->r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		arr[fd] = ft_strdup(buff);
	}
	i = ft_strchr_pos(arr[fd], '\n');
	if (i >= 0)
	{
		newline = ft_substr(arr[fd], 0, i + 1);
		tmp = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
		free(arr[fd]);
		arr[fd] = tmp;
	}
	else
	{
		r = read(fd, buff, BUFFER_SIZE);
		while (r > 0)
		{
			tmp = ft_strjoin(arr[fd], buff);
			free(arr[fd]);
			arr[fd] = tmp;
			i = ft_strchr_pos(arr[fd], '\n');
			if (i >= 0)
				break ;
			r = read(fd, buff, BUFFER_SIZE);
		}
		if (r == 0)
		newline = ft_substr(arr[fd], 0, i + 1);
		arr[fd] = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
	}
	if (r == 0)
		free(arr[fd]);
	return (newline);
}

//int main(void)
//{
//	char *newline;
//	int fd1 = open("fd1.txt", O_RDONLY);
//	int fd2 = open("fd2.txt", O_RDONLY);
//	int fd3 = open("fd3.txt", O_RDONLY);
//	newline = get_next_line(fd1);
//	printf("%s", newline);
//	newline = get_next_line(fd2);
//	printf("%s", newline);
//	newline = get_next_line(fd3);
//	printf("%s", newline);
//	newline = get_next_line(fd1);
//	printf("%s", newline);
//	newline = get_next_line(fd2);
//	printf("%s", newline);
//	newline = get_next_line(fd3);
//	printf("%s", newline);
//	newline = get_next_line(-1);
//	printf("%s", newline);
//	//while (newline)
//	//{
//	//	printf("%s\n", newline);
//	//	newline = get_next_line(fd);
//	//}
//	close (fd1);
//	close (fd2);
//	close (fd3);
//	//free (newline);
//	//fscanf(stdin, "c");
//	return (0);
//}
