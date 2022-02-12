/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/02/12 22:33:15 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



# define BUFFER_SIZE 3

/* Duvidas:
- porque o static variable passa para a outra funcao como double pointer */

 /* OBJECTIVOS:
1- Se chega ao fim do \n 
2- se e EOF, neste caso se o read retornar 0

 - Se line = NULL (vazia), entao envia o que esta no buf 
 - Se line ocupada, entao strjoin */


 

void read_line(char **line, char *buf, int fd, int byte_read)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    j = 0;

    //tmp = "something";
    //*line = tmp;

    if(!*line)
    {         
        byte_read = read(fd, buf, BUFFER_SIZE);
        if(!ft_strchr(buf, '\n'))
        {            
            *line = ft_substr(buf, 0, byte_read);
            while (1) // corrigir 
            {
                byte_read = read(fd, buf, BUFFER_SIZE);
                if(!ft_strchr(buf, '\n'))                                 
                    *line = ft_strjoin(*line, buf);
                else             
                {
                    tmp = (char *)malloc(sizeof(char) * (byte_read + 1)); // corrigir
                    while (j < byte_read) // corrigir
                    {  
                         tmp[j] = buf[j];                 
                        if (tmp[j] == '\n')                       
                            tmp[j - 1] = '\0';          
                        j++;
                    }
                    *line = ft_strjoin(*line, tmp); 
                    break;               
                }
            }
        }        
    }
    free(tmp);
}

char *get_next_line(int fd)
{
    static char *line;
    char *buf;   
    int byte_read; 

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);   

    

     read_line(&line, buf, fd, byte_read);

     

     printf("\n%ld\n", ft_strlen(line));

    
    

    return line;

}

int	main()
{
	int	fd;

	fd = open("The_Age_demanded.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	//printf("FD: %d\n", fd);
	printf("\n1: %s\n", get_next_line(fd));
	//printf("2: %s", get_next_line(fd));
	/* printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd)); */
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