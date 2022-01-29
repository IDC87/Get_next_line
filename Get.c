/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:59:31 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/01/14 13:59:31 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ssize_t read(int fd, void *buf, size_t count);

char *get_next_line(int fd)
{
    
    static int BUFFER_SIZE;
    char str[279];
    int rd;

    BUFFER_SIZE = 273;    

    while(1)
    {
        
        rd = read(fd, str, BUFFER_SIZE);
        if (rd <= 0)
            break;

    }
    str[273] = '\0'; //essencial para evitar criar caracteres adicionais no final

    printf("\n%s\n", str);

    return (rd);
}

int main()
{
    int fd;

    fd = 0;

    fd = open("The_Age_demanded.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("ERROR FILE!\n");
        return (0);
    }
    get_next_line(fd);   

    return (0);
}