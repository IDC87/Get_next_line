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

int file_size()


int main()
{
    int fd;
    char *buf;

    fd = open("The Age demanded.txt", O_RDONLY, 0600);

    printf("\n%ld\n\n", sizeof(fd));

    buf = (char *)malloc(sizeof(char *) * sizeof(fd));

    if (fd == -1)
    {
        printf("ERROR READING!\n");
        return (0);
    }
   int LER = read(fd, &buf, 400);

    write(1, &LER, 400);   
    

    return (0);
}