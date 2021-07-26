#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (((char *)s) + i);
	return (NULL);
}

char	*get_next_line(int fd)
{
	size_t i;
	static char *arr[4096];
	char *newline;
	char tmp[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (arr[fd] == NULL)
	{
		tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read(fd, tmp, BUFFER_SIZE);
		arr[fd] = tmp;
	}
	while (arr[fd][i] && arr[fd][i] != '\n')
		i++;
	if (ft_strchr(arr[fd], '\n'))
	{
		newline = ft_substr(arr[fd], 0, i + 1);
		tmp = ft_substr(arr[fd], 0, BUFFER_SIZE + 1);
		arr[fd] = tmp;
		free(tmp);
	}
	else
	{
		while (!ft_strchr(arr[fd], '\n'))
		{
			if (read(fd, tmp, BUFFER_SIZE) > 0)
				arr[fd] = ft_strjoin(arr[fd], tmp);
			free(tmp);
		}
		i = 0;
		while (arr[fd][i] && arr[fd][i] != '\n')
			i++;
		newline = ft_substr(arr[fd], 0, i + 1);
		arr[fd] = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
	}
	return (newline);
	return (arr[fd]);
}

int main(void)
{
	char *newline;
	int fd1 = open("fd1.txt", O_RDONLY);
	//int fd2 = open("fd2.txt", O_RDONLY);
	//int fd3 = open("fd3.txt", O_RDONLY);
	newline = get_next_line(fd1);
	printf("%s", newline);
	close (fd1);
	return (0);
}
