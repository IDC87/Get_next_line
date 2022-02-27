/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/02/26 15:28:30 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/* Duvidas:
- DONE!!!porque o static variable passa para a outra funcao como double pointer */

 /* OBJECTIVOS:
1- Se chega ao fim do \n 
2- se e EOF, neste caso se o read retornar 0
3 - modelo com linha vazia nao funciona, arranjar

 - Se line = NULL (vazia), entao envia o que esta no buf 
 - Se line ocupada, entao strjoin */


 /* \n is for unix
\r is for mac (before OS X)
\r\n is for windows format */


/* ^M Char explanation:
Unix uses 0xA for a newline character. 
Windows uses a combination of two characters: 0xD 0xA. 0xD is the carriage return character. 
^M happens to be the way vim displays 0xD (0x0D = 13, M is the 13th letter in the English alphabet).

You can remove all the ^M characters by running the following:

:%s/^M//g

Where ^M is entered by holding down Ctrl and typing v followed by m, and then releasing Ctrl. 
This is sometimes abbreviated as ^V^M, but note that you must enter it as described in the previous sentence, 
rather than typing it out literally.
This expression will replace all occurrences of ^M with the empty string (i.e. nothing). 
I use this to get rid of ^M in files copied from Windows to Unix (Solaris, Linux, OSX). */

//# define BUFFER_SIZE 2 >>>>>>IMPORTANTE!!!!


char *line_carrier(char **line, char *carrier)
{
    
    *line = ft_substr(carrier, 0, ft_strlen(carrier));
    
    
    //printf("\nCARRIER: %s\n", *line);
    

}

char *read_line(char **line, char *buf, int fd, int byte_read, int BUFFER_SIZE) // tirar o BUFFER_SIZE
{
    int j;
    int i;
    int line_stopper;
    char *tmp;
    char *carrier;
    char *eof_tester;

    j = 0;
    i = 0;
    line_stopper = 1;
    //byte_read = 1;

      //if(!*line) ultima edicao
        if(!*line)
            *line = (char *)malloc(sizeof(char) *(byte_read + 1)); //antes estava a usar a substr
        
        
        while (byte_read != 0) // corrigir 
            {                
                byte_read = read(fd, buf, BUFFER_SIZE);
                
                /* if(byte_read == 0)
                continue; */
                //printf("\n-----\nBUF:\"%s\"\n-----\n", buf);                
                if(!ft_strchr(buf, '\n'))                                 
                    *line = ft_strjoin(*line, buf);
                else             
                {
                    tmp = (char *)malloc(sizeof(char) * (byte_read + 1));
                    carrier = (char *)malloc(sizeof(char) * (byte_read + 1));
                    while (j < byte_read) // corrigir
                    {  
                        if ((buf[j] != '\n') && (line_stopper == 1))
                        tmp[j] = buf[j];
                        else
                        {
                            while(buf[j] == '\n') // isto se calhar puxar para o inicio " enquanto for \n continua a andar"
                                j++;
                            line_stopper = 0;                    
                            carrier[i] = buf[j];
                            i++;
                        }
                         j++;                         
                    }
                    *line = ft_strjoin(*line, tmp); 

                    free(tmp);                    
                    //free(carrier);                  
                    break;   
                               
                }
            }     
        
            //printf("EOF IS:\"%s\"\n", eof_tester);
 
    return (carrier);
    
}

char *get_next_line(int fd, int BUFFER_SIZE) //tirar o BUFFER_SIZE
{
    static char *line;
    char *buf;   
    char *result;
    int i;
    int byte_read; 
    char *attach;

    i = 0;
    byte_read = 1;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);  
    
     attach = read_line(&line, buf, fd, byte_read, BUFFER_SIZE);   // tirar o BUFFER_SIZE 
     result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));      
     result = line; 
     
     
      line_carrier(&line, attach);
   
    return result;
}

/* BUGS A CORRIGIR:

- chegar a EOF
- linhas vazias nao as salta como deve ser
- ciclo maior que o texto cria garbage value
- buffer maior que linhas  */

int main()
{
    int fd;
    int BUFFER_SIZE;
    int i = 0;
    BUFFER_SIZE = 3;
    //fd = open("The_Age_demanded.txt", O_RDONLY);
    //fd = open("teste.txt", O_RDONLY);
    fd = open("The_new_text.txt", O_RDONLY);
    while(i < 2)
    {
        //printf("BUFFER_SIZE: %d", BUFFER_SIZE);
        printf("%s", get_next_line(fd, BUFFER_SIZE));
        i++;
    }
    
    return (0);
}

/* int	main()
{
	int	fd;
	fd = open("The_Age_demanded.txt", O_RDONLY);
    fd = open("teste.txt", O_RDONLY);
    fd = open("The_new_text.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("FD: %d\n", fd);
	printf("1:%s\n", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	 printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd)); 
	return (0);
} */

