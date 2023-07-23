/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:25:57 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/02 12:56:29 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*s_out;

	if (!s)
		return (0);
	s_out = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s_out)
		return (0);
	index = 0;
	while (s[index])
	{
		s_out[index] = f(index, s[index]);
		index++;
	}
	s_out[index] = 0;
	return (s_out);
}
