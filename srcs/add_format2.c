/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:37:54 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/20 22:39:05 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	add_integer(t_control *control)
{
	int				value;
	char			*result;

	value = va_arg(control->args, int);
	result = convert_base(value, DECIBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free(result), -1);
	return (free(result), 0);
}

int	add_unsigned(t_control *control)
{
	unsigned int	value;
	char			*result;

	value = va_arg(control->args, unsigned int);
	result = unsigned_convert_base(value, DECIBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free(result), -1);
	return (free(result), 0);
}

int	add_l_hexa(t_control *control)
{
	unsigned int	value;
	char			*result;

	value = va_arg(control->args, unsigned int);
	result = unsigned_convert_base(value, L_HEXBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free(result), -1);
	return (free(result), 0);
}

int	add_u_hexa(t_control *control)
{
	unsigned int	value;
	char			*result;

	value = va_arg(control->args, unsigned int);
	result = unsigned_convert_base(value, U_HEXBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free(result), -1);
	return (free(result), 0);
}
