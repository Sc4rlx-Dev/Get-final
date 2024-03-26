/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-raou <oer-raou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:43:30 by oer-raou          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:04 by oer-raou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
 ** =========[ Includes ]==========
 */

/* get_next_line */

#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h> 
/*
 ** =========[ Defines ]===========
 */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024 
# endif

/*
 ** =========[ Prototypes ]========
 */

char	*ft_strchr(char const *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t size);

char	*get_next_line(int fd);

#endif