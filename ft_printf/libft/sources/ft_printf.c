/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:23:05 by alex              #+#    #+#             */
/*   Updated: 2016/12/23 22:37:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				gere_args(const char *str, va_list *args)
{
	int		count;

	count = 0;
	(void)str;
	(void)args;
	if (str[count] == '\0')
		return (0);
	return (0);
}

int 			ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = gere_args(format, &args);
	va_end(args);
	return (ret);
}