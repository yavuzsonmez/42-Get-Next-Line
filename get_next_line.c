#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ss)
		return (NULL);
	while (s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = 0;
	return (ss);
}

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
	char str[BUFFER_SIZE + 1];
	char *tmp;
	int r;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (arr[fd] == NULL)
	{
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
		arr[fd] = ft_strdup(str);
	}
	while (arr[fd][i] && arr[fd][i] != '\n')
		i++;
	if (ft_strchr(arr[fd], '\n'))
	{
		newline = ft_substr(arr[fd], 0, i + 1);
		tmp = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
		arr[fd] = tmp;
	}
	else
	{
		while (!ft_strchr(arr[fd], '\n'))
		{
			if (read(fd, str, BUFFER_SIZE) > 0)
				arr[fd] = ft_strjoin(arr[fd], str);
		}
		while (arr[fd][i] && arr[fd][i] != '\n')
			i++;
		newline = ft_substr(arr[fd], 0, i + 1);
		arr[fd] = ft_substr(arr[fd], i + 1, BUFFER_SIZE - i - 1);
	}
	if (r == 0)
	{
		free(arr[fd]);
	}
	return (newline);
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
	//newline = get_next_line(fd2);
	//printf("%s", newline);
	//newline = get_next_line(fd3);
	//printf("%s", newline);
	//newline = get_next_line(-1);
	//printf("%s", newline);
	//while (newline)
	//{
	//	printf("%s\n", newline);
	//	newline = get_next_line(fd);
	//}
	close (fd1);
	//close (fd2);
	//close (fd3);
	//free (newline);
	//fscanf(stdin, "c");
	return (0);
}
