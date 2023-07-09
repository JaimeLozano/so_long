/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:04:53 by jlozano-          #+#    #+#             */
/*   Updated: 2022/06/16 18:16:06 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_aux;
	size_t			i;

	s_aux = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (s_aux[i] == (unsigned char)c)
			return (&s_aux[i]);
		i++;
	}
	return (NULL);
}
