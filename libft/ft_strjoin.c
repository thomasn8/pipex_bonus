/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:15:31 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/09 18:54:35 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	char	*end;

	if (!s1 || !s2)
		return (NULL);
	start = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!start)
		return (NULL);
	end = start;
	while (*s1)
		*end++ = *s1++;
	while (*s2)
		*end++ = *s2++;
	*end = 0;
	return (start);
}
