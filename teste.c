/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:36:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/01/06 16:36:37 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdio.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_size(void)
{
    const char *filename;
    struct stat sb;
    int size;

    filename = "teste.txt";

    stat(filename, &sb); // funcao que display file status

    return (sb.st_size);

}


//read a file and printing it to a string
/* int c;
FILE *file;
file = fopen("test.txt", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
} */

int main()
{
    int fd;
    char *buf;
    int size_txt;
     


    size_txt = file_size() + 8;
    
    fd = open("teste.txt", O_RDONLY);
     

    //printf("\n%ld\n\n", sizeof(fd));

    buf = (char *)malloc(sizeof(char) * (file_size() + 8));

    /* if (fd == -1)
    {
        printf("\n\nERROR READING!\n");
        return (0);
    } */
   int LER = read(fd, &buf, size_txt);   
    
   //The read system call takes three arguments: 
   //The file descriptor of the file. the buffer where the read data is to be stored and. the number of bytes to be read from the file.
     
    write(1, &LER, size_txt);  
    //write(1, "\n\n", 2); 

    /* write thus takes three arguments:

    The file code (file descriptor or fd).
    The pointer to a buffer where the data is stored (buf).
    The number of bytes to write from the buffer (nbytes). */

    //printf("%d\n\n", file_size());

    close(fd);     

    return (0);
}