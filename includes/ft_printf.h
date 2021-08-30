/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:24:26 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/30 20:42:58 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	int	otp;
	int	star;
	int	htg;
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	widmin;
	int	widmax;
	int	dot;
}				t_flag;

int		ft_printf(char *format, ...);
int		check_conv(char c, va_list *args);

char	*flag_x(int n, char *base);

void	flag_prct(char c);
void	flag_c(char c);
void	flag_d(int n);
void	flag_i(int n);
void	flag_prct(char c);
void	flag_s(char *s);
void	flag_u(unsigned int n);

#endif
