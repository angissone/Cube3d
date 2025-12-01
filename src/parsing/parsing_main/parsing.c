/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:00:57 by zmata             #+#    #+#             */
/*   Updated: 2025/12/01 13:20:22 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	parsing(char *fichier_cub)
{
	int			fd;
	t_info_cub	t_info_line;

	init_t_info_line(&t_info_line);
	fd = open(fichier_cub, O_RDONLY);
	if (fd == -1)
	{
		writer_error("impossible ouvrir le fichier");
		return (1);
	}
	parsing_loop(fd, &t_info_line);
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

	-enlever parsing premiere ligne et derniere
	-si \n dans et apres la map verif error

	leak sur rgb +250
*/
