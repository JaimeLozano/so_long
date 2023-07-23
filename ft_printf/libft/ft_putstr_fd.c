/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:11:58 by jlozano-          #+#    #+#             */
/*   Updated: 2023/05/09 21:37:59 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	lenght;

	if (s != NULL)
	{
		lenght = ft_strlen(s);
		write(fd, s, lenght);
		return (lenght);
	}
	return (write(1, "(null)", 6));
}
