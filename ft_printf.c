/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamdan <nhamdan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:28 by nhamdan           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:43 by nhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_arg(const char flag)
{
	return (ft_strchr("cspdiuxX%", flag) != 0);
}

static int	ft_arg(const char s, va_list ap, int len)
{
	if (s == '%')
		len += ft_putchar(s);
	if (s == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
		len += ft_putptr(va_arg(ap, void *));
	else if (s == 'd')
		len += ft_putnbr(va_arg(ap, int));
	else if (s == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		len += ft_putunbr(va_arg(ap, unsigned int));
	else if (s == 'x')
		len += ft_putunbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		len += ft_putunbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (len);
}

static int	ft_argnbr(const char *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%' && ft_is_arg(*(s + 1)))
		{
			s++;
			len = ft_arg(*s, ap, len);
		}
		else
		{
			ft_putchar(*s);
			len ++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, s);
	len = ft_argnbr(s, ap);
	va_end(ap);
	return (len);
}
