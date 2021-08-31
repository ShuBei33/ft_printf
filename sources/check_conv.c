/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:38:14 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/31 20:26:34 by estoffel         ###   ########.fr       */
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
		return (conv_id(args));
	else if (c == 'p')
		return (conv_p(args));
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		return (write(1, str, ft_strlen(str)));
	}
	else if (c == 'u')
		return (conv_u(args));
	else if (c == 'x' || c == 'X')
		return (conv_x(args));
	return (0);
}
