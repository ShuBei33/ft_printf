/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:39:05 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/06 15:21:39 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_s(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}
