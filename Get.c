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

//off_t lseek(int fd, off_t offset, int whence); !!!changes the positions of the read/write pointer within the file.!!!

/* char *mem_str(str)
{

} */

// A FAZER:
// - encontrar uma maneira de ler a linha do file apenas ate ao \n. (usar o strchr perhapsss)
// - otimizar o buffer para ser variavel consoante a linha
// TENTAR CRIAR A FUNCAO PARA LER CASO O BUFFER NAO CHEGE A QUEBRA DE LINHA

char *get_next_line(int fd)
{
    
     int BUFFER_SIZE;
    static char str[273];
    char *ret;
    int i = 0;

    int rd;

    

    BUFFER_SIZE = 10000;

    rd = read(fd, str, BUFFER_SIZE);

    /* while(rd != 0)
    {
        
        rd = read(fd, str, BUFFER_SIZE);  depois de lido move o ponteiro para o index correspondente do n de bytes lido do buffer      

        ret = strchr(str, 97);

         if (str[i] != '\n')
        {
            
        printf("-------------------------------");
        printf("\n%d ciclo\n", i);
        printf("%d bytes\n", rd);
        printf("\n%s\n", str);        
        printf("-------------------------------\n");
        }
        else
        {
            while (i < strlen(str))
            {
                str[i] = 0;
                i++;
            }            
        }
        printf("\n%d\n", i);
        break;       

         if (rd == 0)
         str[10] = '\0'; 
        
         if (rd <= 0)
            break;             

    }    */
    //str[BUFFER_SIZE] = '\0';

    //printf("\nSTRING FINAL \n%s\n", str);

    //printf("\n RETURN STRING IS: %s ", ret);

    printf("\n%d\n", rd);

    

    

    return (str);
}

int main()
{
    int fd;
    int i = 0;

    fd = 0;

    fd = open("The_Age_demanded.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("ERROR FILE!\n");
        return (0);
    }

    while (i < 1)
    {
        printf ("\n%s\n",get_next_line(fd));
        i++;
    }

    

    return (0);
}