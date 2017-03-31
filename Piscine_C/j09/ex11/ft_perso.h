/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 14:51:36 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 15:37:35 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PERSO_H
# define __FT_PERSO_H
# define SAVE_AUSTIN_POWERS 42
# include <string.h>

typedef struct s_perso	t_perso;

struct	s_perso
{
	char	*name;
	double	life;
	int		age;
	int		profession;
};

#endif
