/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:12:57 by jlozano-          #+#    #+#             */
/*   Updated: 2023/05/02 13:01:05 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strchr_gnl(const char *s, const char c)
{
	char	*s_aux;

	s_aux = (char *)s;
	while (*s_aux != c && *s_aux != '\0')
		s_aux++;
	if (*s_aux == c && c != 0)
		s_aux++;
	return ((int)(s_aux - s));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_realloc(char *str, size_t size)
{
	char	*astr;

	astr = (char *)malloc(size * sizeof(char));
	if (str && astr)
	{
		ft_strncpy(astr, str, size);
		free(str);
		str = NULL;
	}
	return (astr);
}

int	ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	while (src[count] != 0 && dstsize > count + 1)
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize != 0)
		dst[count] = 0;
	return (count);
}
