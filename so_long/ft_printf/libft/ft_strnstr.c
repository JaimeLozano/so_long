/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:15:21 by jlozano-          #+#    #+#             */
/*   Updated: 2022/06/15 19:51:38 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		src_len;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	src_len = ft_strlen(needle);
	while (haystack[i] != '\0' && (i + src_len) <= len)
	{
		if (ft_strncmp(haystack + i, needle, src_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
