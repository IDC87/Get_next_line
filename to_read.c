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

/* int read_size(fd)
{
    char aux[1000];
    int file_size;

    file_size = read(fd, aux + 1, sizeof(aux) + 1);

    return (file_size);

}
 */

int to_read()
{
   fd = open("The_Age_demanded", O_RDONLY);

   return (fd);
}