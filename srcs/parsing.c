/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:10:59 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/20 19:21:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <limits.h>

static int	parse_specifiers(const char *specifier, t_control *control)
{
	control->type = *specifier;
	if (is_specifier(control->type) == false)
		return (-1);
	else if (control->type == CHAR)
		return (add_char(control));
	else if (control->type == STRING)
		return (add_string(control));
	else if (control->type == POINTER)
		return (add_pointer(control));
	else if (control->type == DIGIT)
		return (add_digit(control));
	else if (control->type == INTEGER)
		return (add_integer(control));
	else if (control->type == UNSIGNED)
		return (add_unsigned(control));
	else if (control->type == L_HEXA)
		return (add_l_hexa(control));
	else if (control->type == U_HEXA)
		return (add_u_hexa(control));
	else if (control->type == PERCENT)
		return (add_percent(control));
	return (0);
}

int	parse_input(const char *format, t_control *control)
{
	size_t	i;

	i = 0;
	while (format[i] && control->char_write < INT_MAX)
	{
		if (control->char_write && control->char_write % 1024 == 0)
			if (ft_fflush(control) == -1)
				return (-1);
		if (format[i] == '%')
		{
			if (parse_specifiers(format + i + 1, control) == -1)
				return (-1);
			++i;
		}
		else
			control->buffer[control->char_write++ % 1024] = format[i];
		++i;
	}
	if (format[i] && control->char_write >= INT_MAX)
		return (-1);
	return (0);
}
