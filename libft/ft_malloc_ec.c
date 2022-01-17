/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_ec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:00:54 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/11 12:59:26 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_ec(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(DEFAULT, 2);
		ft_putstr_fd("in memory allocation.\n", 2);
	}
	return (ptr);
}
