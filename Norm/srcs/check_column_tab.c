/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_column_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 13:08:49 by alex              #+#    #+#             */
/*   Updated: 2016/03/20 19:29:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/tool.h"

void    check_column(char *tab, char *nb_file)
{
	int count;
	int countline;
	int i;

	count     = 0;
	countline = 1;
	for (i = 0; tab[i] != '\0'; i++)
	{
		if (tab[i] != '\n')
			count++;
		if (tab[i] == '\n')
		{
			count = 0;
			countline++;
		}
		if (count > 80)
		{
			flx_fprintf(1, "Error at line %d in %s : more than 80 columns\n",
			            countline, nb_file);
			while (tab[i] != '\n')
				i++;
			count = 0;
			countline++;
		}
	}
}

void    check_endline(char *tab, char *nb_file)
{
	int countline;

	countline = 1;
	for (size_t i = 1; tab[i] != '\0'; i++)
	{
		if (tab[i] == '\n' && tab[i - 1] == ' ')
			flx_fprintf(1, "Error at line %d in %s : space at end of line\n",
			            countline, nb_file);
		if (tab[i] == '\n')
			countline++;
	}
}

void    check_tab(char *tab, char* nb_file)
{
	char var = 'l';
	tab     = &var;
	nb_file = &var;
	if (tab[0] == 'l' && nb_file[0] == '1') {
		/* code */
	}
	/*int		i;
	   int		tabulation;

	   tabulation = 0;
	   for (i = 0; tab[i] =! '\0' count; i++) {
	    if (tab[i] == 'i' && tab[i + 1] == 'f')
	        tab++;
	   }*/
}
