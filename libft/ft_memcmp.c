/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:58:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:21 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	cmp;

	if (!n)
		return (0);
	while (*(char *)s1 == *(char *)s2 && --n)
	{
		s1++;
		s2++;
	}
	cmp = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (cmp);
}
