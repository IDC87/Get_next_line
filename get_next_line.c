/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/03/09 23:13:16 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* char *print_line_aux(char *result, char *tmp) 
{
    // funcao que retorna o * ate a quebra de linha
    int i;

    i = 0;
    if (!result || !tmp)
        return NULL;   
    while(tmp[i] != '\n')
    {
        result[i] = tmp[i];
        i++;
    }
    result[i] = tmp[i];
    result[i + 1] = '\0';
    return (result);
}

char *print_line_carrier(char *result, char *tmp)
{
    // funcao que retorna o * a carregar para a proxima linha
    int i;
    int len;

    i = 0;
    if (!result || !tmp)
        return NULL;   
    len = ft_strlen(result);
    while (tmp[len + i]) 
    {
        tmp[i] = tmp[len + i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *print_line(char *rest)
{
    char *tmp;
    char *result;
    
    int line_len;
    
    if(!rest)
        return NULL;
        
    if (!ft_strchr(rest, '\n')) // a ultima linha
    {
        result = ft_substr(rest, 0, line_len);
        free(rest); 
        rest = NULL;   
        return (result);
    }
    result = ft_substr(rest, 0, line_len);    
    tmp = ft_substr(rest, 0, line_len); 
    result = print_line_aux(result, tmp);
    rest = print_line_carrier(result, tmp);
    
    return (rest);
} */

char *read_line(char *line, int fd, char *buf) 
{
    int byte_read;
    char *tmp;
 
    if (!line || !ft_strchr(line, '\n')) // caso nao encontre o \n
    {
        byte_read = read(fd, buf, BUFFER_SIZE);        
        while(byte_read > 0)
        { 
            buf[byte_read] = '\0';
            if (!line)
                line = ft_substr(buf, 0, byte_read);              
            else 
            {
                tmp = line;
                line = ft_strjoin(line, buf); 
                free(tmp);
            }             
            if(ft_strchr(line, '\n'))
                    break;
            byte_read = read(fd, buf, BUFFER_SIZE);
        }
    }    
    free(buf);   
    return(line);
}
char *free_line(char *line)
{
    free(line);
    line = 0;
    return line;
}

char *get_next_line(int fd) 
{
    static char *line;
    char    *buf;  
    char    *result;
    int     line_size;
    int     carrier;
    char    *tmp;       
       
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return 0;
    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, line, 0) == -1)
    {
        free(buf);
        return (0);
    }
    line = read_line(line, fd, buf);
     if (!line)            
           return (NULL);       
    line_size = ft_strlen(line);
    if (line_size == 0)      
       return (free_line(line));       
     if (!ft_strchr(line, '\n'))
     {
        result = ft_substr(line, 0, line_size);            
        line = free_line(line);      
        return (result);         
     }     
    carrier = ft_strlen(ft_strchr(line, '\n')); 
    result = ft_substr(line, 0, line_size - carrier + 1);    
    tmp = line;
    line = ft_substr(ft_strchr(line, '\n'), 1, carrier - 1); // retorna o * a carregar para a proxima linha
    free(tmp);   
    return (result);   
}



/* int main()
{
    int fd;   
    int i = 0;
    
    fd = open("notas.txt", O_RDONLY);
    //printf("%d", fd);
    //fd = open("teste.txt", O_RDONLY);
    //fd = open("The_new_text.txt", O_RDONLY);
    while(i < 3)
    {
        //printf("BUFFER_SIZE: %d", BUFFER_SIZE);
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
} */

/* int	main()
{
	int	fd;
	fd = open("notas.txt", O_RDONLY);
    fd = open("teste.txt", O_RDONLY);
    fd = open("The_new_text.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("FD: %d\n", fd);
	printf("1:%s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	 printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd)); 
	return (0);
}
 */