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

#include "get_next_line.h"

int main()
{
    int fd;   
    int fd2;
    ssize_t LER;
    int file_len;
    int rd;

    //file_len = 270;
    fd = -1;  
    

    fd = open("The_Age_demanded.txt", O_RDONLY);

    fd2 = open("teste.txt", O_RDONLY);



    if (fd == -1)
    {
        printf("ERROR FILE!\n");
        return (0);
    }
    //else
    //printf("SUCESS! FD is %d\n", fd);

    //file_len = read_size(fd);   

    char str[273];  

    //ssize_t read(int fd, void *buf, size_t count);
    while(1)
    {
        rd = read(fd, str, sizeof(str));
        if (rd <= 0)
            break;

    }
    str[273] = '\0';

    printf("\n%s\n", str);

    printf ("\nFd = %d\nFd2 = %d\n", fd, fd2);

    printf("\nrd = %d\n", rd);

    //printf("\n%d\n", file_len);
   

    return (0);
}