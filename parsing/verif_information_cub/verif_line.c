#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}
int verif_start(char *str)
{
	int i = 0;
	int len;
	len = ft_strlen(str);
	while(str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if(i == len)
		return(-1);
	return(i);
}

int what_info(char *str, int *who_info, int i)
{
	if(str[i] && str[i + 1])
	{
		if(str[i] == 'N' && str[i + 1] == 'O')
			*who_info = 1;
		else if (str[i] == 'S' && str[i + 1] == 'O')
			*who_info = 2;
		else if (str[i] == 'W' && str[i + 1] == 'E')
			*who_info = 3;
		else if (str[i] == 'E' && str[i + 1] == 'A')
			*who_info = 4;
		if(*who_info != 0)
			return(0);
	}
	if(str[i])
	{
		if (str[i] == 'F')
			*who_info = 5;
		else if (str[i] == 'C')
			*who_info = 6;
		else if (str[i] == '1' || str[i] == '0' ||str[i] == 'N' ||str[i] == 'S' ||str[i] == 'E' ||str[i] == 'W')
			*who_info = 7;
		if(*who_info != 0)
			return(0);
	}
	return(-1);
}
char *verif_line(char *line, int *who_info)
{
	int i = 0;
	*who_info = 0;
	if(!line)
		return(NULL);
	if ((i = verif_start(line)) == -1 )
		return(NULL);
	if(what_info(line, who_info, i) == -1)
		return(NULL);
	return(line);
}