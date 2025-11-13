#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_info_cub
{
	char *nort_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	char *floor_color;
	char *ceiling_color;
	char **map;
	int cmp_info;
}	t_info_cub;

int	parsing(char *fichier_cub)
{
	int fd;
	int who_info = 0;
	char *line = NULL;
	char *line_tmp = NULL;
	char *dup = NULL;
	t_info_cub t_info_line;
	t_info_line = (t_info_cub){0};

	fd = open(fichier_cub, O_RDONLY);
	while(line = get_next_line(fd))
	{
		line_tmp = verif_line(line, &who_info); //verif si ligne valable et quelle type info
		if(!line_tmp)
		{
			free(line);
			continue;
		}
		line = line_tmp;
		line = take_info(line, &who_info); // prends que les bonne utile
			if(who_info == 1)
				t_info_line.nort_texture = strdup(line);
			else if(who_info == 2)
				t_info_line.south_texture = strdup(line);
			else if(who_info == 3)
				t_info_line.west_texture = strdup(line);
			else if(who_info == 4)
				t_info_line.east_texture = strdup(line);
			else if(who_info == 5)
				t_info_line.floor_color = strdup(line);
			else if(who_info == 6)
				t_info_line.ceiling_color = strdup(line);
			else if(who_info == 7)
				t_info_line.map = strdup(line);
		t_info_line.cmp_info++;
		free(line);
	}
	close(fd);
	return(0);
}
/*
	TODO :
-si open echoue
-si stdup echoue
-si gnl echoue
! -convertir en valeur numerique le floor et veiling
! -gere doule tableau de la map
*/