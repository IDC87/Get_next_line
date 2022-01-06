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

int main()
{
    int fd;
    char buf[200];

    fd = open("The Age demanded.txt", O_RDONLY, 0600);

    if (fd == -1)
    {
        printf("ERROR READING!\n");
        return (0);
    }
   int LER = read(fd, buf, 200);

    write(1, &LER, 200);

    
    

    return (0);
}