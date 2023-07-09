/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:44:49 by jlozano-          #+#    #+#             */
/*   Updated: 2022/06/15 16:16:05 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_d;
	size_t	l_s;
	size_t	i;

	l_s = ft_strlen(src);
	l_d = ft_strlen(dst);
	if (!dstsize)
		return (l_s);
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	l_d = i;
	while (src[i - l_d] && i < dstsize - 1)
	{
		dst[i] = src[i - l_d];
		i++;
	}
	if (l_d < dstsize)
		dst[i] = '\0';
	return (l_s + l_d);
}
