/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:18:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/03/05 17:51:09 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *print_line_aux(char *result, char *tmp) 
{
    // funcao que retorna o * ate a quebra de linha
    int i;

    i = 0;
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
    len = ft_strlen(result);
    while (tmp[len + i]) 
    {
        tmp[i] = tmp[len + i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *print_line(char **line)
{
    char *tmp;
    char *result;
    
    if(!*line)
        return NULL;
    tmp = ft_strdup(*line);
    result = (char *)malloc(sizeof(char *) * ft_strlen(tmp)); 
    if (!ft_strchr(tmp, '\n')) // a ultima linha
    {
        result = ft_substr(*line, 0, ft_strlen(*line));
        free(*line); 
        *line = NULL;   
        return (result);
    }
    result = print_line_aux(result, tmp);
    tmp = print_line_carrier(result, tmp);
    *line = tmp;
    //free(tmp); //dar free aqui causa erros na apresentacao das linhas
    return (result);
}

void read_line(char **line, char *buf, int fd) 
{
    int byte_read;

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
    free(buf); //dar free aqui faz o numero de linhas nao ser apresentado corretamente
}

char *get_next_line(int fd) 
{
    static char *line;
    char *buf;   
    char *result;
    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
    {
        free(buf);
        return (NULL);
    }    
    read_line(&line, buf, fd);
    result = print_line(&line);
    return(result);
}

/* int main()
{
    int fd;   
    int i = 0;
    
    fd = open("notas.txt", O_RDONLY);
    //fd = open("teste.txt", O_RDONLY);
    //fd = open("The_new_text.txt", O_RDONLY);
    while(i < 30)
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
