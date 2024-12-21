/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:56:19 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/20 21:57:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <limits.h>

int	add_str_to_buffer(t_control *control, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && control->char_write < INT_MAX)
	{
		if (control->char_write && control->char_write % 1024 == 0)
			if (ft_fflush(control) == -1)
				return (-1);
		control->buffer[control->char_write++ % 1024] = str[i++];
	}
	if (str[i] && control->char_write >= INT_MAX)
		return (-1);
	return (0);
}
