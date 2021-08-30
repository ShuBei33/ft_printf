/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:38:14 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/30 22:24:43 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_conv(char c, va_list *args)
{
	char	c1;
	char	*str;
	int		i;

	if (c == 'c' || c == '%')
	{
		c1 = va_arg(*args, int);
		ft_putchar_fd(c1, 1);
		return (1);
	}
	else if (c == 'i' || c == 'd')
	{
		i = va_arg(*args, int);
		str = ft_itoa_base(i, "0123456789");
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		return (write(1, str, ft_strlen(str)));
	}
	else if (c == 'u')
		return (conv_u(args));
	else if (c == 'x')
	{
		i = va_arg(*args, int);
		str = ft_itoa_base(i, "0123456789abcdef");
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (c == 'X')
	{
		i = va_arg(*args, int);
		str = ft_itoa_base(i, "0123456789ABCDEF");
		ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}
