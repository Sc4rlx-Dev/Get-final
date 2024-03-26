#include "get_next_line.h"



int main()
{
	int fd;
	fd = open("note.txt", 0644);
	
	char *s  = get_next_line(fd);
	printf("(%s)", s);
	free(s);
	s  = get_next_line(fd);
	printf("(%s)", s);
	free(s);
	s  = get_next_line(fd);
	printf("(%s)", s);
	free(s);

	close(fd);

}

