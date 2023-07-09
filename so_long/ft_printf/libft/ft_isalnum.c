/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:28:03 by jlozano-          #+#    #+#             */
/*   Updated: 2022/09/14 13:18:59 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= '0') && (c <= '9'))
		|| ((c >= 'a') && (c <= 'z'))
		|| ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}
