/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:33:06 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/19 18:28:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_control	*control;
	long		char_write;

	if (!format)
		return (-1);
	char_write = -1;
	control = control_init();
	if (!control)
		return (-1);
	va_start(control->args, format);
	if (parse_input(format, control) == -1)
	{
		ft_fflush(control);
		free(control);
		return (-1);
	}
	if (ft_fflush(control) != -1)
		char_write = control->char_write;
	free(control);
	return ((int)char_write);
}
