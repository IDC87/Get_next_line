if(!*line)
    {         
        byte_read = read(fd, buf, BUFFER_SIZE);
        //printf("\n%d\n", byte_read);
        if((!ft_strchr(buf, '\n')) || (!ft_strchr(buf, '\r')))
        {            
            *line = ft_substr(buf, 0, byte_read);
            while (1) // corrigir 
            {
                byte_read = read(fd, buf, BUFFER_SIZE);
                if((!ft_strchr(buf, '\n')) || (!ft_strchr(buf, '\r')))                                 
                    *line = ft_strjoin(*line, buf);
                else             
                {
                    tmp = (char *)malloc(sizeof(char) * (byte_read + 1)); // corrigir
                    while (j < byte_read) // corrigir
                    {  
                         tmp[j] = buf[j];                 
                        if (tmp[j] == '\n')                       
                           tmp[j] = '\0';          
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




if(!*line)
    {
        buf = malloc(100 + 1);
        byte_read = read(fd, buf, 100);
        if (ft_strchr(buf, '\n'))
        {
            while(buf[i] != '\n')
            {
                tmp[i] = buf[i];
                    
                printf("%c",tmp[i]); 
                i++;           
                
            }
            tmp[i] = '\0';
        }
        
    }
    printf("\nlen da tmp: %ld\n", ft_strlen(tmp));

    *line = ft_substr(tmp, 0, 27);
    