/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:19:02 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:21:19 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_occur;

	i = -1;
	last_occur = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			last_occur = i;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	if (last_occur > -1)
		return ((char *)&s[last_occur]);
	return (NULL);
}
