/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:37:54 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/21 20:35:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#ifndef L_HEXBASE
# define L_HEXBASE "0123456789abcdef"
#endif

#ifndef U_HEXBASE
# define U_HEXBASE "0123456789ABCDEF"
#endif

#ifndef DECIBASE
# define DECIBASE "0123456789"
#endif

int	add_integer(t_control *control)
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

int	add_unsigned(t_control *control)
{
	unsigned int	value;
	char			*result;

	value = va_arg(control->args, unsigned int);
	result = unsigned_convert_base(value, DECIBASE);
	if (!result)
		return (-1);
	if (add_str_to_buffer(control, result) == -1)
		return (free_return(result));
	free(result);
	return (0);
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
		return (free_return(result));
	free(result);
	return (0);
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
		return (free_return(result));
	free(result);
	return (0);
}
