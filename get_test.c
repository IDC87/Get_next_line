
#include "get_next_line.h"

int check(char *buffer)
{
    int i;
    i = 0;
    while (buffer[i] != 0)
    {
        if (buffer[i] == '\n')
            return (0);
        i++;
    }
    return (1);
}
int get_size_line(char *buffer)
{
    int i;
    i = 0;
    while (buffer[i] != 0)
    {
        if (buffer[i] == '\n')
            return (++i);
        i++;
    }
    return (i);
}

char    *next_line(char *line, char *buffer, int size_line)
{
    char    *temp;
    int i;
    int i_buf;
    int i_rest;
    i_buf = 0;
    i = 0;
    i_rest = -1;
    temp = line;
    line = malloc(sizeof(char) * (size_line + 1));
    if (line == 0)
        return (0);
    line[size_line] = '\0';
    while (temp != 0 && temp[i] != '\0')
    {
        line[i] = temp[i];
        i++;
    }
    while (buffer[i_buf] != 0)
    {
        if (i_rest == -1)
        {
            line[i++] = buffer[i_buf];
            if (buffer[i_buf] == '\n')
                i_rest = 0;
        }
        else
            buffer[i_rest++] = buffer[i_buf];
        buffer[i_buf++] = 0;
    }
    if (temp != 0)
        free(temp);
    return (line);
} 


char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char    *line;
    int read_size;
    int size;
    int isline;

    isline = 1;
    read_size = 0;
    size = 0;
    line = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (isline == 1)
    {
        read_size = 1;
        if (buffer[0] == 0)
            read_size = read(fd , buffer, BUFFER_SIZE);
        if (read_size <= 0)
            return (line);
        size += get_size_line(buffer);
        isline = check(buffer) == 1 && read_size > 0;
        line = next_line(line, buffer, size);
    }
    return (line);
}  

 int main()
{
    int fd;   
    int i = 0;
    
    fd = open("notas.txt", O_RDONLY);
    //fd = open("teste.txt", O_RDONLY);
    //fd = open("The_new_text.txt", O_RDONLY);
    while(i < 25)
    {
        //printf("BUFFER_SIZE: %d", BUFFER_SIZE);
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
} 