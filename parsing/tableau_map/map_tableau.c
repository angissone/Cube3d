#include "parsing.h"
#define MAP (t_info_line->map)
#define NBR_LINE (t_info_line->nbr_line_tab)

void take_in_table(t_node **liste_map, t_info_cub *t_info_line)
{
	int which_line = 0;
	MAP = malloc((NBR_LINE + 1) * sizeof(char*));
	if(!MAP)
	{
		free(MAP);
		exit_prog("Probleme de malloc du double tabelau", t_info_line);
	}
	MAP[NBR_LINE] = NULL;
	while(which_line < NBR_LINE)
	{
		MAP[which_line] = ft_strdup(return_line_i_to_liste(liste_map, which_line));
		if(!MAP[which_line])
		{
		free_tab(MAP);
		exit_prog("Probleme de malloc de map d une ligne du  double tableau", t_info_line);
		}
		which_line++;
	}
}
