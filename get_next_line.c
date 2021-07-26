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
	int	r;
	static char *arr[4096];
	char *newline;
	char *tmp;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 4096)
		return (NULL);
	arr[4096] = NULL;
	while(!ft_strchr(arr[fd], '\n'))
	{
		tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		r = read(fd, tmp, BUFFER_SIZE);
		if ()
		free(tmp);
	}
	return (newline);
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
