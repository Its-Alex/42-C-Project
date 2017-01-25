/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:01:17 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 23:17:16 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	error(int error, int send_perror, char *str)
{
	if (send_perror == 1)
	{
		ft_putstr_color("Error \x1B[0m: ", RED);
		perror("");
	}
	else
	{
		ft_putstr_color("Error", RED);
		ft_putstr(" : ");
		ft_putendl(str);
	}
	exit(error);
}
