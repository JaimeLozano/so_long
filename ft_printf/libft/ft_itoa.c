/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:04:24 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/14 13:48:43 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_modulus(char *buff, unsigned int number, int len)
{
	if (number == 0)
		*buff = '0';
	if (!buff)
		return (0);
	while (number > 0)
	{
		buff[len--] = number % 10 + '0';
		number /= 10;
	}
	return (buff);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*buff;
	unsigned int	number;
	int				len;

	len = ft_len(n);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (0);
	buff[len--] = '\0';
	if (n < 0)
	{
		number = n * -1;
		buff[0] = '-';
	}
	else
		number = n;
	buff = ft_modulus(buff, number, len);
	return (buff);
}
