/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:00:57 by zmata             #+#    #+#             */
/*   Updated: 2025/11/28 17:47:13 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	parsing(char *fichier_cub)
{
	int			fd;
	int			who_info;
	int			index_start;
	char		*line;
	char		*line_tmp;
	t_info_cub	t_info_line;

	init_t_info_line(&t_info_line);
	fd = open(fichier_cub, O_RDONLY);
	if (fd == -1)
	{
		writer_error("impossible ouvrir le fichier");
		return (1);
	}

	line = NULL;
	line_tmp = NULL;
	while ((line = get_next_line(fd)))
	{
cub_print_var_d("sssssssssssssssssssssss",1);

		index_start = 0;
		who_info = 0;
		line = remove_backslash_n(line);
		if (verif_start(line) == NULL)
		{
			free(line);
			continue ;
		}
		line_tmp = verif_line(line, &who_info, &index_start);
		if (!line_tmp)
		{
			free(line);
			exit_prog("impossible de trouver une des informations ou "
				"information incorrect", &t_info_line);
		}
		line = line_tmp;
		if (who_info <= 4)
		{
			take_info_file(&line, &who_info, &index_start, &t_info_line);
			t_info_line.cmp_info++;
		}
		else if (who_info == 5 || who_info == 6)
		{
			index_start = cut_space(line, &index_start);
			take_info_color(line, &who_info, &index_start, &t_info_line);
			t_info_line.cmp_info++;
		}
		else if (who_info == 7)
		{
			if (t_info_line.cmp_info < 6)
			{
				free(line);
				exit_prog("Nombre  ou ordre d information incorrect",
					&t_info_line);
			}
			if (check_map(line, &t_info_line.liste_map) == -1)
			{
				free(line);
				exit_prog("Map non conforme", &t_info_line);
			}
			new_value(line, &t_info_line.liste_map);
			t_info_line.cmp_info++;
			t_info_line.nbr_line_tab++;
		}
		free(line);
	}
	close(fd);
	take_in_table(&t_info_line.liste_map, &t_info_line);
	last_verif(&t_info_line);
	check_map_closed(&t_info_line);
	print_struct(&t_info_line);
	exit_prog("Fin du programme tous va bien !", &t_info_line);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	parsing(argv[1]);
// 	return (0);
// }

/*
	TODO :
	si open echoue
	si stdup echoue
	si gnl echoue
	- gerer double tableau de la map
	- gerer le tableau en liste chaine puis le mettre en double tableau
	- rendre le code propre
	- changer le nom des struct et fonction
	- si pas .xpm dois erreur
	- ne pas accepter si il a une lettre dans le nom
	- ne pas accepter les espaces dans un nombre
	- gerer mieux les erreurs sur mauvais cles
	- gerer les doublons
	- leak sur l'erreur "impossible d ouvrir une des textures."
	- couleur max 255
	- free quand erreur
	- 3 chiffres max
	- , a la fin des chiffres
	- , au debut mets tout a 0
	- si pas de chiffres pas d'erreurs
	- verifier si map est bien apres les autres cles
	- verif couleur negatif

	enlever parsing premiere ligne et derniere
	si \n dans et apres la map verif error
*/
