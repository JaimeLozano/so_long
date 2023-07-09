/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:41:50 by jlozano-          #+#    #+#             */
/*   Updated: 2022/08/31 12:18:12 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	len;
	size_t	dstlimit;

	src_len = ft_strlen (src);
	if (dstsize == 0)
		return (src_len);
	dstlimit = dstsize - 1;
	len = src_len;
	if (dstlimit < len)
		len = dstlimit;
	ft_memcpy (dst, src, len);
	dst [len] = 0;
	return (src_len);
}
