/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-raou <oer-raou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:20:48 by oer-raou          #+#    #+#             */
/*   Updated: 2024/03/27 00:10:51 by oer-raou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	*p3 = 0;
	free(s1);
	return (s3);
}

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc(sizeof(*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}

char	*ft_strchr(char const *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

size_t	ft_strlen(char const *string)
{
	char const	*ptr;

	ptr = string;
	while (*ptr)
		++ptr;
	return ((size_t)(ptr - string));
}

char	*ft_strdup(char const *string)
{
	char	*dup;
	char	*ptr;

	dup = malloc(sizeof(*dup) * (ft_strlen(string) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*string)
		*ptr++ = *string++;
	*ptr = 0;
	return (dup);
}
