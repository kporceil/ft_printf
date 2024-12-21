/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:05:19 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/21 20:32:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

#ifndef L_HEXBASE
# define L_HEXBASE "0123456789abcdef"
#endif

#ifndef U_HEXBASE
# define U_HEXBASE "0123456789ABCDEF"
#endif

#ifndef DECIBASE
# define DECIBASE "0123456789"
#endif

int	add_char(t_control *control)
{
	char	data;

	if (control->char_write >= INT_MAX)
		return (-1);
	data = va_arg(control->args, int);
	control->buffer[control->char_write++ % 1024] = data;
	return (0);
}

int	add_percent(t_control *control)
{
	if (control->char_write >= INT_MAX)
		return (-1);
	control->buffer[control->char_write++ % 1024] = '%';
	return (0);
}

int	add_string(t_control *control)
{
	char	*data;

	data = va_arg(control->args, char *);
	if (!data)
		data = "(null)";
	if (add_str_to_buffer(control, data) == -1)
		return (-1);
	return (0);
}

int	add_pointer(t_control *control)
{
	void			*data;
	unsigned long	pointer;
	char			*result;

	data = va_arg(control->args, void *);
	if (!data)
	{
		if (add_str_to_buffer(control, "(nil)") == -1)
			return (-1);
		return (0);
	}
	pointer = (unsigned long)data;
	result = unsigned_convert_base(pointer, L_HEXBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, "0x") == -1)
		return (free_return(result));
	if (add_str_to_buffer(control, result) == -1)
		return (free_return(result));
	free(result);
	return (0);
}

int	add_digit(t_control *control)
{
	int				value;
	char			*result;

	value = va_arg(control->args, int);
	result = convert_base(value, DECIBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free_return(result));
	free(result);
	return (0);
}
