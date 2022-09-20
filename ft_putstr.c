/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamdan <nhamdan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:51:21 by nhamdan           #+#    #+#             */
/*   Updated: 2022/03/02 13:51:31 by nhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i])
			write(1, &s[i++], 1);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (i);
}
