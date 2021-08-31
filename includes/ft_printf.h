/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:24:26 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/31 21:02:47 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	check_conv(char c, va_list *args);
int	conv_id(va_list *args);
int	conv_p(va_list *args);
int	conv_u(va_list *args);
int	conv_x(va_list *args);
int	ft_printf(char *format, ...);

#endif
