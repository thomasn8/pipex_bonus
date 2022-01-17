/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:06:11 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/09 11:07:13 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base16(unsigned long int nbr)
{
	unsigned long int	nbr_cpy;
	char				*buf;
	int					size;

	if (nbr <= 0)
		return (NULL);
	nbr_cpy = nbr;
	size = 1;
	nbr_cpy /= 16;
	while (nbr_cpy)
	{
		nbr_cpy /= 16;
		size++;
	}
	buf = malloc(size * sizeof(char));
	if (!buf)
		return (NULL);
	buf[size--] = 0;
	while (nbr)
	{
		buf[size--] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	return (buf);
}
