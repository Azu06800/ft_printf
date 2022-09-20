/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamdan <nhamdan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:50:44 by nhamdan           #+#    #+#             */
/*   Updated: 2022/03/02 13:50:53 by nhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	a;

	a = (unsigned long) ptr;
	count = ft_putstr("0x");
	count += ft_putunbr_base(a, "0123456789abcdef");
	return (count);
}
