/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:40:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/23 09:20:13 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*exceptions(int n, int i)
{
	char	*nbr;
	long	n_long;

	n_long = 2147483648;
	if (n == 0)
	{
		nbr = malloc(1 * sizeof(char) + 1);
		if (!nbr)
			return (NULL);
		*nbr = '0';
		*(nbr + 1) = 0;
		return (nbr);
	}
	nbr = malloc(11 * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	nbr[0] = '-';
	nbr[11] = 0;
	while (n_long > 0)
	{
		nbr[i--] = n_long % 10 + '0';
		n_long /= 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	if (n != 0 && n != -2147483648)
	{
		len = n_len(n);
		nbr = malloc(len * sizeof(char) + 1);
		if (!nbr)
			return (NULL);
		if (n < 0)
		{	
			n *= -1;
			nbr[0] = '-';
		}
		nbr[len] = 0;
		while (len-- && n > 0)
		{
			nbr[len] = n % 10 + '0';
			n /= 10;
		}
		return (nbr);
	}
	nbr = exceptions(n, 10);
	return (nbr);
}
