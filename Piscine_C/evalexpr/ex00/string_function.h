/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 18:05:43 by malexand          #+#    #+#             */
/*   Updated: 2015/07/20 18:39:47 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_FUNCTION_H
# define STRING_FUNCTION_H
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
