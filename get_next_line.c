/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/01/03 20:23:53 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{

}

//Syntax in C language 
size_t read (int fd, void* buf, size_t cnt);  

Parameters:

    fd: file descriptor
    buf: buffer to read data from
    cnt: length of buffer

Returns: How many bytes were actually read

    return Number of bytes read on success
    return 0 on reaching end of file
    return -1 on error
    return -1 on signal interrupt

Important points

    buf needs to point to a valid memory location with length not smaller than the specified size because of overflow.
    fd should be a valid file descriptor returned from open() to perform read operation because if fd is NULL then read should generate error.
    cnt is the requested number of bytes read, while the return value is the actual number of bytes read. Also, some times read system call should read less bytes than cnt.

    // C program to illustrate 
// read system Call 
#include<stdio.h> 
#include <fcntl.h> 

int main() 
{ 
int fd, sz; 
char *c = (char *) calloc(100, sizeof(char)); 
  
fd = open("foo.txt", O_RDONLY); 
if (fd < 0) { perror("r1"); exit(1); } 
  
sz = read(fd, c, 10); 
printf("called read(% d, c, 10). returned that"
        " %d bytes were read.\n", fd, sz); 
c[sz] = '\0'; 
printf("Those bytes are as follows: % s\n", c); 
} 