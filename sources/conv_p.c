/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:46:21 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/07 19:04:18 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_p(va_list *args)
{
	long	p;
	char	*str;
	int		len;

	p = (long)va_arg(*args, void *);
	ft_putstr_fd("0x", 1);
	if (p == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	str = ft_itoa_base(p, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
