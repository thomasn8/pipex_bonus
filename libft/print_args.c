/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:17:54 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/12 22:27:27 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (print_str("(null)"));
	while (*s)
		count += print_char(*s++);
	return (count);
}

int	print_int(long int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += print_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
		count += print_int(nbr / 10);
	count += print_char(nbr % 10 + '0');
	return (count);
}

int	print_hexa(unsigned long int nbr, int c_case)
{
	int		count;
	char	*set;

	count = 0;
	set = "0123456789abcdef";
	if (c_case == 'X')
		set = "0123456789ABCDEF";
	if (nbr > 15)
		count += print_hexa(nbr / 16, c_case);
	count += print_char(set[nbr % 16]);
	return (count);
}

int	print_ptr(void *ptr)
{
	size_t	nbr;
	int		count;
	char	*set;

	if (!ptr)
		return (print_str("0x0"));
	nbr = (size_t)ptr;
	count = 0;
	count += print_str("0x");
	set = "0123456789abcdef";
	count += print_hexa(nbr, 'x');
	return (count);
}
