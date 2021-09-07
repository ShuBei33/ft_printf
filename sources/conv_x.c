/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:46:03 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/07 19:04:45 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_x(va_list *args)
{
	char	*str;
	char	c;
	int		len;

	c = va_arg(*args, unsigned int);
	if (c == 'x')
		str = ft_itoa_base(c, "0123456789abcdef");
	else
		str = ft_itoa_base(c, "0123456789ABCDEF");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
