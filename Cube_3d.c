typedef struct s_info_cub
{
/* 	char **information;
 */	char *nort_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	int *floor_color;
	int *ceiling_color
	int **map
}	t_info_cub

int	parsing(char *fichier_cub)
{
	int fd;
	int i = 0;
	char *info_map= NULL
	t_info_cub t_info_map;
	fd = open(fichier_cub, O_RDONLY);
	while(info_map = get_next_line(fd))
	{
		verif(info_map);
		if(!info_map)
			return(NULL);
		while(i <= 7)
		{
			if(i == 1)
				char *nort_texture;
			char *south_texture;
			char *west_texture;
			char *east_texture;
			int *floor_color;
			int *ceiling_color
			int **map
		}

	}
	t_info_map.information[i] = '\0';
	close(fd);
}