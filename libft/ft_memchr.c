/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:05:16 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:17 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		u_c;
	const unsigned char	*str;

	u_c = c;
	str = s;
	while (n--)
	{
		if (*str == u_c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
