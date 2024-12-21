/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:02:52 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/21 20:31:05 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_specifier
{
	CHAR = 'c',
	STRING = 's',
	POINTER = 'p',
	DIGIT = 'd',
	INTEGER = 'i',
	UNSIGNED = 'u',
	L_HEXA = 'x',
	U_HEXA = 'X',
	PERCENT = '%',
}				t_specifier;

typedef struct s_control
{
	char		buffer[1024];
	t_specifier	type;
	long		char_write;
	va_list		args;
}				t_control;

bool		is_specifier(t_specifier specifier);
t_control	*control_init(void);
int			ft_fflush(t_control *control);
void		flush_buffer(t_control *control);
int			parse_specifiers(const char *format, t_control *control);
int			parse_input(const char *format, t_control *control);
int			ft_printf(const char *format, ...)__attribute__((format(printf, 1,
						2)));
int			add_char(t_control *control);
int			add_string(t_control *control);
int			add_pointer(t_control *control);
int			add_digit(t_control *control);
int			add_integer(t_control *control);
int			add_unsigned(t_control *control);
int			add_l_hexa(t_control *control);
int			add_u_hexa(t_control *control);
int			add_percent(t_control *control);
char		*unsigned_convert_base(unsigned long nbr, char *base);
char		*convert_base(long nbr, char *base);
int			add_str_to_buffer(t_control *control, char *str);
int			free_return(void *ptr);

#endif
