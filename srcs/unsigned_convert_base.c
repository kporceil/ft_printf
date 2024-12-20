/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:56:42 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/20 18:58:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

static size_t	calc_len(unsigned long nb, size_t len)
{
	size_t	i;

	i = 0;
	if (!nb)
		i = 1;
	while (nb)
	{
		nb /= len;
		++i;
	}
	return (i);
}

char	*unsigned_convert_base(unsigned long nbr, char *base)
{
	const size_t	base_len = ft_strlen(base);
	size_t			result_len;
	char			*result;

	result_len = calc_len(nbr, base_len);
	result = malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	result[result_len] = '\0';
	if (nbr == 0)
		result[0] = base[0];
	while (nbr)
	{
		result[--result_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}
