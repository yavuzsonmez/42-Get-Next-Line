#TESTER

echo "BUFFER 0"
echo "________\n"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=0 get_next_line.c get_next_line_utils.c && ./a.out

echo "\n____________________________________________________________________________________\n"

echo "BUFFER 1"
echo "________\n"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out

echo "\n____________________________________________________________________________________\n"

echo "BUFFER 3"
echo "________\n"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c && ./a.out

echo "\n____________________________________________________________________________________\n"

echo "BUFFER 50"
echo "________\n"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=50 get_next_line.c get_next_line_utils.c && ./a.out

echo "\n____________________________________________________________________________________\n"


# int main(void)
# {
#	//printf("OPEN MAX %d\n", OPEN_MAX);
#	int fd1 = open("fd1.txt", O_RDONLY);
#	int fd2 = open("fd2.txt", O_RDONLY);
#	int fd3 = open("fd3.txt", O_RDONLY);
#	char *newline = get_next_line(fd1);
#	printf("%s", newline);
#	newline = get_next_line(fd2);
#	printf("%s", newline);
#	newline = get_next_line(fd3);
#	printf("%s", newline);
#	newline = get_next_line(fd1);
#	printf("%s", newline);
#	newline = get_next_line(fd2);
#	printf("%s", newline);
#	newline = get_next_line(fd3);
#	printf("%s", newline);
#	//while (newline)
#	//{
#	//	printf("%s\n", newline);
#	//	newline = get_next_line(fd);
#	//}
#	close (fd1);
#	close (fd2);
#	close (fd3);
#	free (newline);
#	//fscanf(stdin, "c");
#	return (0);
# }
#



