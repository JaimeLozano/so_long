/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:27:11 by jlozano-          #+#    #+#             */
/*   Updated: 2022/06/15 16:44:11 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_aux;

	s_aux = (char *)s;
	while (*s_aux != (char)c)
	{
		if (*s_aux == '\0')
			return (NULL);
		s_aux++;
	}
	return (s_aux);
}
