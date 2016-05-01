/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 11:22:25 by malexand          #+#    #+#             */
/*   Updated: 2015/07/23 11:22:26 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# define BUFFER_SIZE 29999
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif
