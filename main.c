#include "get_next_line.h"
#include <stdio.h>
#include <string.h>













// int main()
// {
// 	char long_line[2042];
// 	memset(long_line,'A',sizeof (long_line) -1);
// 	long_line[sizeof (long_line)-1] = '\0';
// 	printf("long line : %s\n", long_line);
// 	return 0;
// }



// int main()
// {
// 	int fd;
// 	char *s = get_next_line(STDIN_FILENO);

// 	fd = open("file.txt", O_RDONLY);
// 	while(1)
// 	{
// 		s = get_next_line(STDIN_FILENO);
// 		if (s == NULL)
// 			break;
// 		printf("%s\n", s);
// 		free(s);
// 	}
// }




// int main()
// {
// 	int fd = 42;
// 	char *line = get_next_line(fd);

// 	if(line == NULL)
// 	{
// 		printf("done");
// 		}
// 		else{
// 			printf("err");
// 			free(line);
// 		}
// 		return 0;
// }