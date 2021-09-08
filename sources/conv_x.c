/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:46:03 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/08 20:22:40 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_x(va_list *args, char conv)
{
	char				*str;
	unsigned int		c;
	int					len;

	c = va_arg(*args, unsigned int);
	if (conv == 'x')
		str = ft_uitoa_base(c, "0123456789abcdef");
	else
		str = ft_uitoa_base(c, "0123456789ABCDEF");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
