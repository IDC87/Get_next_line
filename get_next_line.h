/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:20:26 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/01/16 13:20:26 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 
#endif 


#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

//get_next_line_utils.c
size_t	ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif