/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 18:22:16 by alex              #+#    #+#             */
/*   Updated: 2016/04/03 22:05:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/tool.h"

void     count_tab(char *tab, char *nb_file)
{
	size_t countTab;
	size_t tmp;
	int    countline;

	countTab  = 0;
	countline = 1;
	for (size_t i = 0; tab[i] != '\0'; i++)
	{
		tmp = countTab;
		if (tab[i] == '\n')
		{
			countline += 1;
			for (size_t j = 1; tab[i + j] == ' '; j++)
			{
				countTab = j / 4;
			}
			if (countTab%4 != 0)
				flx_fprintf(1, "Error at line %d in %s : bad indentation!\n",
				            countline, nb_file);
		}
		if(countTab != tmp && countTab != tmp - 1 && countTab != tmp + 1)
		{
			flx_fprintf(1, "Error at line %d in %s : bad indentation!\n",
			            countline, nb_file);
		}
	}


}

void    check_array(char *tab, char *nb_file)
{
	check_column(tab, nb_file);
	check_endline(tab, nb_file);
	count_tab(tab, nb_file);
}
