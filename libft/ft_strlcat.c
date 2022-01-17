/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:57 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	src_length;
	size_t	dst_length;
	size_t	src_length_cpy;

	src_length = 0;
	while (src[src_length])
		src_length++;
	dst_length = 0;
	while (dst[dst_length])
		dst_length++;
	src_length_cpy = src_length;
	if (dstsize > dst_length)
	{	
		i = dst_length;
		n = dstsize - dst_length - 1;
		while (n-- && src_length--)
			dst[i++] = *src++;
		dst[i] = 0;
		return (dst_length + src_length_cpy);
	}
	return (dstsize + src_length);
}
