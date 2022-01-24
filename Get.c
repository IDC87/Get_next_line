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

char *get_next_line(int fd)
{
    
    static int BUFFER_SIZE;
    char str[273];
    int rd;

    BUFFER_SIZE = 273;

    while(1)
    {
        rd = read(fd, str, sizeof(str));
        if (rd <= 0)
            break;

    }
    str[273] = '\0';

    printf("\n%s\n", str);

    return (str);
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