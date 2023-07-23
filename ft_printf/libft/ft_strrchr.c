/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:34:40 by jlozano-          #+#    #+#             */
/*   Updated: 2022/06/15 16:44:30 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_aux;
	size_t	i;

	s_aux = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (s_aux + i);
	while (i != 0)
	{
		i--;
		if (s_aux[i] == (char)c)
			return (s_aux + i);
	}
	return (NULL);
}
