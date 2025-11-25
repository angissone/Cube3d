/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:16:33 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:20:09 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_struct(t_info_cub *t_info_line)
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
	print_tab(t_info_line->map);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*tab;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	tab = malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*remove_backslash_n(char *line)
{
	int		len;
	char	*result;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
	{
		result[len] = line[len];
		len++;
	}
	result[len] = '\0';
	free(line);
	return (result);
}
