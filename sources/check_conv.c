/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:38:14 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/06 15:22:22 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_conv(char c, va_list *args)
{
	if (c == 'c')
		return (conv_c(args));
	else if (c == 'i' || c == 'd')
		return (conv_id(args));
	else if (c == 'p')
		return (conv_p(args));
	else if (c == 's')
		return (conv_s(args));
	else if (c == 'u')
		return (conv_u(args));
	else if (c == 'x' || c == 'X')
		return (conv_x(args));
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}
