/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:54:41 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/14 13:40:00 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_min_malloc(char const *s, size_t len)
{
	char			*dst;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s_len > len)
		dst = (char *)malloc(sizeof(char) * (len + 1));
	else
		dst = (char *)malloc(sizeof(char) * (s_len + 1));
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	char			*dst_aux;

	if (!s)
		return (NULL);
	dst = ft_min_malloc(s, len);
	if (!dst)
		return (NULL);
	dst_aux = dst;
	while (*s && len)
	{
		if (start)
			start--;
		else if (len)
		{
			*dst = *s;
			dst++;
			len--;
		}
		s++;
	}
	*dst = '\0';
	return (dst_aux);
}
