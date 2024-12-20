/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:51:54 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/16 15:56:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_specifier(t_specifier specifier)
{
	return (specifier == CHAR || specifier == STRING || specifier == POINTER
		|| specifier == DIGIT || specifier == INTEGER || specifier == UNSIGNED
		|| specifier == L_HEXA || specifier == U_HEXA || specifier == PERCENT);
}
