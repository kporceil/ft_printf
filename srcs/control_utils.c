/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:38:06 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/20 22:15:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_control	*control_init(void)
{
	t_control	*control;

	control = malloc(sizeof(t_control));
	if (!control)
		return (NULL);
	control->char_write = 0;
	return (control);
}
