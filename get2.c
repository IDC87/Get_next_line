/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:02:36 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/02/27 00:14:11 by ivda-cru         ###   ########.fr       */
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


char *print_line(char **line, int byte_read)
{
    char *tmp;
    char *result;
    int i;
    int len;   

    i = 0;
    //printf("len: %d", ft_strlen(ft_strchr(*line, '\n')));
    if(!*line)
    return NULL;
    tmp = ft_strdup(*line);
    
    result = (char *)malloc(sizeof(char *) * ft_strlen(tmp));  
    //printf("L: $%s$", *line);    

    if (ft_strchr(tmp, '\n'))
    {
        //printf("TMP: %s", tmp);
        while(tmp[i] != '\n')
        {
            result[i] = tmp[i];
            i++;
        }
        result[i] = tmp[i];
        result[i + 1] = '\0';        
         //return (result);     
    }
    i = 0;
    len = ft_strlen(result);
    while (tmp[len + i]) //AQUI POSSO USAR A STRTRIM
    {
        tmp[i] = tmp[len + i];
        i++;
    }
    tmp[i] = '\0';
    *line = tmp;

    !!!!!!!!!!!FALTA SO ESTA PARTE!!!!!
    // FALTA IMPRIMIR O ULTIMO BYTE, PARA ISSO O TMP TEM DE SER IGUAL AO RESULT E A FUNCAO TEM DE SABER QUE CHEGOU AO FINAL DO READ
    
    
   
    
    return (result);
}

void read_line(char **line, char *buf, int fd, int byte_read, int BUFFER_SIZE) // tirar o BUFFER_SIZE
{
    char *tmp;
    int i;
    

    i = 0;      // condicao para a primeira vez que corre

    if (!*line || !ft_strchr(buf, '\n')) // caso nao encontre o \n
    {
        byte_read = read(fd, buf, BUFFER_SIZE);
        while(byte_read != 0)
        { 
            buf[byte_read] = '\0';
            if (!*line)
                *line = ft_substr(buf, 0, byte_read);
            else                     
            *line = ft_strjoin(*line, buf);          
            if(ft_strchr(buf, '\n'))
                break;
            byte_read = read(fd, buf, BUFFER_SIZE);                    
             
        }
    }
    else     
        *line = ft_strjoin(*line, buf);    // isto esta mal

        
}

char *get_next_line(int fd, int BUFFER_SIZE) //tirar o BUFFER_SIZE
{
    static char *line;
    char *buf;   
    char *result;
    int i;
    int byte_read; 

    i = 0;
    byte_read = 1;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);  
    read_line(&line, buf, fd, byte_read, BUFFER_SIZE);    

    result = print_line(&line, byte_read);
    return(result);  
     
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
    BUFFER_SIZE = 29;
    //fd = open("The_Age_demanded.txt", O_RDONLY);
    fd = open("teste.txt", O_RDONLY);
    //fd = open("The_new_text.txt", O_RDONLY);
    while(i < 30)
    {
        //printf("BUFFER_SIZE: %d", BUFFER_SIZE);
        printf("%s", get_next_line(fd, BUFFER_SIZE));
        i++;
    }

    
    
    return (0);
}
