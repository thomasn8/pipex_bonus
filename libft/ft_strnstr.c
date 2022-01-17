/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:26:20 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/11 20:34:37 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_in_str(const char *haystack, const char *needle, size_t len)
{
	size_t	prev_match;
	size_t	i;
	size_t	j;

	prev_match = 0;
	i = 0;
	j = 0;
	while (haystack[i] && i <= len)
	{
		if (haystack[i] == needle[j])
		{
			prev_match = i;
			while (haystack[i] == needle[j] && i <= len)
			{
				i++;
				j++;
				if (needle[j] == 0 && i <= len)
					return ((char *) &haystack[prev_match]);
			}
			i = prev_match;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str_search;

	if (*needle == 0)
		return ((char *) haystack);
	if (!len)
		return (NULL);
	str_search = str_in_str(haystack, needle, len);
	return (str_search);
}
