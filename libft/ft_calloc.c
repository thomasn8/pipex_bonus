/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:51:33 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:04 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	mem;
	char	*ptr;

	i = -1;
	mem = count * size;
	ptr = malloc(mem);
	if (!ptr)
		return (NULL);
	while (++i < mem)
		ptr[i] = 0;
	return ((void *) ptr);
}
