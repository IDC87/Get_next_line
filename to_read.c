/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:34:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/01/14 16:34:22 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/fcntl.h>

// buffer at 29

char *get_next_line(int fd)
{
    char *line;
   static char buf[BUFFER_SIZE];
   int read_size;

    // (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // sem memoria alocada da seg fault no final

   read_size = read(fd, buf, BUFFER_SIZE);


   printf("\n%d\n", read_size);

   return (line);
}

int main()
{
    int fd;

    fd = open("The_Age_demanded.txt", O_RDONLY);

    printf("\n%s\n", get_next_line(fd));

    return (0);
}