/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:07:08 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/07 20:21:52 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flag	init_struct(void)
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
}

/*static void	*check_flags(char *format)
{
	va_list	args;

	if (*format == 'c')
		return (flag_c(va_arg(args, int)));
	else if (*format == 's')
		return (flag_s(va_arg(args, char *)));
	else if (*format == 'p')
		return (flag_p(va_arg(args, int)));
	else if (*format == 'd')
		return (flag_d(va_arg(args, int)));
	else if (*format == 'i')
		return (flag_i(va_arg(args, int)));
	else if (*format == 'u')
		return (flag_u(va_arg(args, int)));
	else if (*format == 'x' || *format == 'X')
		return (flag_x(va_arg(args, int)));
	else if (*format == '%')
		return (flag_prct(va_arg(args, int)));
	return (0);
}*/

int	ft_printf(char *format, ...)
{
	t_flag	prec;
	va_list	args;
	int		otp;

	prec = init_struct();
	otp = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			//check_flags(format);
		}
		else
		{
			write(1, &format, 1);
			++format;
			++otp;
		}
	}
	va_end(args);
	return (otp);
}
