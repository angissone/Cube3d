#include "parsing.h"
void print_struct(t_info_cub *t_info_line)
{
	printf("NO: %s\n", t_info_line->nort_texture);
	printf("SO: %s\n", t_info_line->south_texture);
	printf("EA: %s\n", t_info_line->east_texture);
	printf("WE: %s\n", t_info_line->west_texture);
	printf("F: %d,", t_info_line->floor_color[0]);
	printf("%d,", t_info_line->floor_color[1]);
	printf("%d\n", t_info_line->floor_color[2]);
	printf("C: %d,", t_info_line->ceiling_color[0]);
	printf("%d,", t_info_line->ceiling_color[1]);
	printf("%d\n", t_info_line->ceiling_color[2]);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i])
		i++;
	tab = malloc((i + 1) * sizeof(char));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	//free(s);
	return (tab);
}

char *remove_backslash_n(char *line)
{
	int len;
	char *result = NULL;

	len = 0;

	while(line[len] &&line[len] != '\n')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if(!result)
	{
		free(result);
		return(NULL);
	}
	len = 0;
	while(line[len] &&line[len] != '\n')
	{
		result[len] = line[len];
		len++;
	}
	result[len] = '\0';
	free(line);
	return(result);
}

int	parsing(char *fichier_cub)
{
	int fd;
	int who_info = 0;
	int	index_start = 0;
	char *line = NULL;
	char *line_tmp = NULL;
	t_info_cub t_info_line;
	t_node *liste_map = NULL;
	init_t_info_line(&t_info_line);

	fd = open(fichier_cub, O_RDONLY);
	if(fd == -1)
	{
		writer_error("impossible ouvrir le fichier");
		return(1);
	}
	while((line = (get_next_linee(fd))))
	{
		index_start = 0;
		who_info = 0;
		line = remove_backslash_n(line);
		if (verif_start(line) == NULL)
		{
			free(line);
			continue;
		}
		line_tmp = verif_line(line, &who_info, &index_start); //verif si ligne valable et quelle type info return line a null si echoue
		if(!line_tmp)
		{
			free(line);
			exit_prog("impossible de trouver une des informations ou information incorrect", &t_info_line);
		}
		line = line_tmp;
		if(who_info <= 4)
		{
			take_info_file(&line, &who_info, &index_start, &t_info_line); // prends que les bonne utile et verifie si vide ou non
					t_info_line.cmp_info++;
		}
		else if(who_info  == 5 || who_info  == 6)
		{
			index_start = cut_space(line, &index_start);
			take_info_color(line, &who_info, &index_start, &t_info_line); // prends que les bonne utile et verifie si vide ou non
					t_info_line.cmp_info++;
		}
		else if(who_info == 7)
		{
				if(t_info_line.cmp_info < 6)
				{
					free(line);
					exit_prog("Nombre  ou ordre d information incorrect", &t_info_line);
				}
				if(check_map(line,&liste_map) == -1)
				{
					free(line);
					exit_prog("Map non conforme", &t_info_line);
				}
				new_value(line, &liste_map);
				t_info_line.cmp_info++;
		}
		free(line);
	}
	close(fd);

	last_verif(&t_info_line);
	print_struct(&t_info_line);
	exit_prog("fin propre du prog donc c carre le S", &t_info_line);
	return(0);
}

int main(int argc, char **argv)
{
	(void)argc;
	if (argc != 2)
		return(0);
	parsing(argv[1]);
	return(0);
}


/*
	TODO :
si open echoue
si stdup echoue
si gnl echoue
! -gere doule tableau de la map
! -gerer le tableau en liste chaine puis le mettre en double tableau
!+ rendre le code propre
!= changer le nom des struct et fonction
__si pas .xpm dois erreur
__ne pas accepter si il aune lettre dans le nom
__ne pas accepter les espaces dans un nombre
__gerer mieux les erreurs sur mauvais cles
__gerer les doublons
__leak sur l'erreur "-impossible d ouvrir une des textures."
__couleur max 255
__free quqnd erreur
__3 chiffres max
__, a la fin des chiffres
__, au debut mets tout a 0
__si pas de chiffres pas d'erreurs
__verifier si map et bien apres les autres cles
__verif couleur negatif
*/