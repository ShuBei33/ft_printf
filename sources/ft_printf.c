/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:07:08 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/30 20:38:00 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*t_flag	init_struct(void)
{
	t_flag	prec;

	prec.otp = 0;
	prec.star = 0;
	prec.htg = 0;
	prec.minus = 0;
	prec.plus = 0;
	prec.space = 0;
	prec.zero = 0;
	prec.widmin = 0;
	prec.widmax = 0;
	prec.dot = 0;
	return (prec);
}*/

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i])
				len = len + check_conv(format[i], &args);
		}
		else
		{
			len = len + write(1, &format[i], 1);
			++i;
		}
	}
	va_end(args);
	return (len);
}
