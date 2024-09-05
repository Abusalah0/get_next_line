/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:36:12 by abdsalah          #+#    #+#             */
/*   Updated: 2024/09/05 09:00:29 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr)
		dest_ptr++;
	while (*src)
		*dest_ptr++ = *src++;
	*dest_ptr = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = 0;
	while (s1[i++])
		total_len++;
	i = 0;
	while (s2[i++])
		total_len++;
	str = malloc(total_len + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (dest);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
