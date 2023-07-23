/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:19:08 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/14 17:12:58 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	s = malloc(size * count);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}
