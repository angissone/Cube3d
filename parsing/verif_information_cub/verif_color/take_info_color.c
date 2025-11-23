#include "parsing.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
char *is_empty(char *str)
{
	int i = 0;
	while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if(str[i] == '\0')
		return(NULL);
	return(str);
}
int	is_valid(char *str, int *i)
{
	int z = *i;
	while((str[z] >= '0' && str[z] <= '9') || (str[z] == ' ' || str[z] == '\t' || str[z] == '\n' || str[z] == ','))
		(z)++;
	if(str[z] == '\0')
		return(1);
	return(0);
}
void	verif_empty_color(char *line, int *index_start, int *who_info, t_info_cub *t_info_line)
{
	int		i;
	int		z = 0;
	int		start;
	char	*tmp;

	// se placer après les espaces après F ou C
	*index_start = cut_space(line, index_start);
	if (*index_start == -1)
		return;
	//printf(" la == %d\n", is_valid(line, index_start));
	if(is_valid(line, index_start) == 0)
	{
		 free(line);
		exit_prog("probleme de couleur", t_info_line);
		return;
	}

	i = 0;
	while (i < 3)
	{
		*index_start = cut_space(line, index_start);
		if (*index_start == -1)
			return;
		start = *index_start;
		while (line[*index_start] && is_digit(line[*index_start]))
			(*index_start)++;
		z = cut_space(line, index_start);
		if(i < 2 && line[z] && (line[z] != ','))
		{
			free(line);
			exit_prog("ligne de couleur incorrect", t_info_line);
		}
		if (i == 2 && line[z] && line[z] != '\0')
		{
			free(line);
			exit_prog("ligne de couleur incorrect", t_info_line);
		}
		tmp = ft_strdup_n(line, start, *index_start);
		if (is_empty(tmp) == NULL)
		{
			free(tmp);
			return;
		}
		if (*who_info == 5)
		{
			if(t_info_line->floor_color[i] != -1 || atoi(tmp) > 255 || atoi(tmp) < 0)//evite les doublons et geres les restriction de chiffre
			{
			free(tmp);
			free(line);
			exit_prog("Un doublon de couleur ou nbr des couleurs faux", t_info_line);
			}
			t_info_line->floor_color[i] = atoi(tmp);
		}
		else
		{
			if(t_info_line->ceiling_color[i] != -1 || atoi(tmp) > 255 || atoi(tmp) < 0)
			{
			free(tmp);
			free(line);
			exit_prog("Un doublon de couleur ou nbr de couleur faux", t_info_line);
			}
			t_info_line->ceiling_color[i] = atoi(tmp);
		}
		free(tmp);
		*index_start = cut_space(line, index_start);
		/* if (*index_start == -1)
			break; */
		if (line[*index_start] == ',' && i < 2)
		{
			(*index_start)++;
		}
		i++;
	}
}

void	take_info_color(char *line, int *who_info, int *index_start,
						t_info_cub *t_info_line)
{
	*index_start = *index_start + 1;// on est sur 'F' ou 'C', on avance de 1
	verif_empty_color(line, index_start, who_info, t_info_line);
}
