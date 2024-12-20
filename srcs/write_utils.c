/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:06:45 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/19 15:08:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_fflush(t_control *control)
{
	int	len;

	if (!control->char_write)
		len = 0;
	else if (control->char_write % 1024 == 0)
		len = 1024;
	else
		len = control->char_write % 1024;
	if (len)
		if (write(1, control->buffer, len) == -1)
			return (-1);
	return (0);
}
