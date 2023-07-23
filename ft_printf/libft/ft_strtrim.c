/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:29:07 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/14 12:54:24 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_ispresent(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] != c)
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_ispresent(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_ispresent(s1[end - 1], set))
		end--;
	s2 = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (end > start)
	{
		s2[i++] = s1[start++];
	}
	s2[i] = '\0';
	return (s2);
}
