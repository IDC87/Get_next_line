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
#include "get_next_line_utils.c"
#include <sys/fcntl.h>

# define BUFFER_SIZE 75

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



char *read_line(char *line)
{
    int i;
    char *tmp;

    i = 0;

    
    if(strchr(line, '\n'))
    {
        tmp = malloc(sizeof(char) * (29 + 1));
        while(line[i] != '\n')
        {
          tmp[i] = line[i];
          i++;   
        }
        tmp[i] = '\0';
    }
    

    return tmp;

}

char *get_next_line(int fd)
{
    char *line;
   static char buf[BUFFER_SIZE];
   int read_size;

    // (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // sem memoria alocada da seg fault no final 

    read_size = read(fd, buf, BUFFER_SIZE);

    line = buf;
    
    read_line(line);  

    //line_info(line);
    
    return (read_line(line));
}

int	main()
{
	int	fd;

	fd = open("The_Age_demanded.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("FD: %d\n", fd);
	printf("1: %s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd));
	return (0);
}

/* int main()
{
    int fd;
    int i = 0;

    fd = open("The_Age_demanded.txt", O_RDONLY);

    while(i++ < 1)
    printf("\n%s\n\n", get_next_line(fd));

    return (0);
} */