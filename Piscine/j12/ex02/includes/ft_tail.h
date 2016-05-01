/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 22:33:33 by malexand          #+#    #+#             */
/*   Updated: 2015/07/24 23:13:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define BUFFER_SIZE 4096
# include <unistd.h>
# include <fcntl.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *src);

#endif
