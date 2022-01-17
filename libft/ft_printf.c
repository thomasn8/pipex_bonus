/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:58:22 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/12 22:26:40 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arg(va_list args, const char *placeholder)
{
	int	count;

	count = 0;
	if (*placeholder == 'c')
		count += print_char(va_arg(args, int));
	else if (*placeholder == 's')
		count += print_str(va_arg(args, char *));
	else if (*placeholder == 'p')
		count += print_ptr(va_arg(args, void *));
	else if (*placeholder == 'd' || *placeholder == 'i')
		count += print_int(va_arg(args, int));
	else if (*placeholder == 'u')
		count += print_int(va_arg(args, unsigned int));
	else if (*placeholder == 'x' || *placeholder == 'X')
		count += print_hexa(va_arg(args, unsigned int), *placeholder);
	else if (*placeholder == '%')
		count += print_char('%');
	else if (*placeholder == ' ')
		count = 0;
	else
		count += print_char(*(placeholder + 1));
	return (count);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, placeholder);
	i = -1;
	count = 0;
	while (placeholder[++i])
	{
		if (placeholder[i] == '%' && placeholder[i + 1] != 0)
			count += print_arg(args, &placeholder[++i]);
		else if (placeholder[i] == '%' && placeholder[i + 1] == 0)
			count += 0;
		else
			count += print_char(placeholder[i]);
	}
	va_end(args);
	return (count);
}
