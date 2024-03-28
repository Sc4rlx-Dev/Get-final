#include "get_next_line_bonus.h"


// int main()
// {
//     int fd1, fd2;
//     char *line;

//     fd1 = open("file1.txt", O_RDONLY);
//     fd2 = open("file2.txt", O_RDONLY);

//     while (1)
//     {
//         line = get_next_line(fd1);
//         if (line == NULL)
//             break;
//         printf("line 1 >>(%s)\n", line);
//         free(line);
//         line = get_next_line(fd2);
//         if (line == NULL)
//             break;
//         printf("line 2 >>(%s)\n", line);
//         free(line);
//     }

//     close(fd1);
//     close(fd2);

//     return 0;
// }


int main()
{
    int fds[num_files];
    char *line;
    const char * file_names[num_files] = {"file1.txt" , "file2.txt"};

    for(int i = 0 ; i < num_files ; i++){
        fds[i] = open(file_names[i] , O_RDONLY);
        if(fds[i] == -1){
            printf("error");
            return(1);
        }
    }
    
    while(1)
    {
        for(int i = 0; i < num_files; ++i){
            line = get_next_line(fds[i]);
            if (line == NULL)
                break;
            printf("FILE %d : %s\n", i + 1 , line);
            free(line);
        }        
    if(!line)
    break;
    }
    for(int i = 0 ; i < num_files ; ++i){
    close(fds[i]);
    }
    return 0;
}