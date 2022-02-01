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


/* #ifndef BUFFER_SIZE
# define BUFFER_SIZE 29
#endif  */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



#include <unistd.h>
#include<stdio.h> 
#include <fcntl.h>              //>>>>>>>>>>APAGAR O QUE NAO INTERESSA<<<<<<<<<<<
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

size_t	ft_strlen(const char *s);

#endif