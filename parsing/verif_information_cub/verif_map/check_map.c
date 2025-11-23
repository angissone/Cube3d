#include "parsing.h"

int check_map(char *line, t_node **list_map)
{
	int i = 0;
	i = cut_space(line, &i);
	if (*list_map == NULL)
	{
		while(line[i] && (line[i] == '1' || line[i] == ' ' || line[i] == '\t'))
			i++;
		if(line[i] != '\0')
			return(-1);
	}
	else if(*list_map != NULL)
	{
		while(line[i] && (line[i] == '1' || line[i] == '0' ||line[i] == 'N' ||line[i] == 'S' ||line[i] == 'E' ||line[i] == 'W' ||line[i] == ' '||line[i] == '\t'))
			i++;
		if(line[i] != '\0')
			return(-1);
	}
	return(0);
}