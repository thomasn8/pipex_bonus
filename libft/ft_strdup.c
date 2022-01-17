/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:50:28 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:49 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dup = malloc(len * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	dup[len] = 0;
	while (len--)
		dup[len] = s1[len];
	return (dup);
}
