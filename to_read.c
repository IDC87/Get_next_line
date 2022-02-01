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

# define BUFFER_SIZE 23

/* \n is for unix
\r is for mac (before OS X)
\r\n is for windows format */

/* "The age demanded that we sing\r\n
And cut away our tongue.\r\n
The age demanded that we flow\r\n
And hammered in the bung.\r\n
The age demanded that we dance\r\n
And jammed us into iron pants.\r\n
And in the end the age was handed\r\n
The sort of shit that it demanded.\r\n
\r\n 
 by Ernest Hemingway." */

char *line_info(char *line)
{
    int i;
    int j;
    int k;
    int m;

    i = 0;
    j = 0;
    k = 0;
    m = 0;
    
    while (line[i] != '\0')
    {
        if (line[i] == '\n') //numero de linhas
            k++;
        else
        {
            printf("--Tamanho da string: %ld", ft_strlen(line));
            break;
        }

        while(line[j] != '\n') // bytes ate a quebra de linha
            j++;
        
        if((line[i] == '\r') && (line[i + 1] == '\n') && (line[i + 2] == '\r') && (line[i + 3] == '\n'))
            m++;      
        i++; //numero total de bytes
    }

        printf("\n--Numero total de bytes: %d\n", i);
        printf("--bytes ate quebra de linha: %d\n", j - 1);
        printf("--Numero de linhas totais: %d\n", k + 1);
        printf("--Numero de linhas em branco: %d\n", m);
        //printf("\nBUFFER: \n%s\nBUFFER\n", buf);

    
    return(line);
}

/* char *read_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\n')
    {

    }

} */

char *get_next_line(int fd)
{
    char *line;
   static char buf[BUFFER_SIZE];
   int read_size;

    // (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // sem memoria alocada da seg fault no final

   read_size = read(fd, buf, BUFFER_SIZE);

   line = buf;

   printf("Check line less than line: %s\n", line);

   line_info(line);

   return (line);
}

int main()
{
    int fd;

    fd = open("The_Age_demanded.txt", O_RDONLY);

    printf("\n%s\n\n", get_next_line(fd));

    return (0);
}