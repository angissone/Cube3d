/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:27:34 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_valid(char *str, int *i)
{
	int	z;

	z = *i;
	while ((str[z] >= '0' && str[z] <= '9')
		|| str[z] == ' ' || str[z] == '\t'
		|| str[z] == '\n' || str[z] == ',')
		z++;
	if (str[z] == '\0')
		return (1);
	return (0);
}

static int	has_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (str[i] == '\0');
}

static void	color_error(char *line, char *tmp, t_info_cub *info)
{
	free(tmp);
	free(line);
	exit_prog("Un doublon de couleur ou valeur incorrecte", info);
}

static void	set_color(char *tmp, t_info_cub *info, int i, int who)
{
	int	val;

	val = atoi(tmp);
	if (val < 0 || val > 255)
		exit_prog("Valeur RGB hors limites", info);
	if (who == 5 && info->floor_color[i] != -1)
		exit_prog("Doublon couleur F", info);
	if (who == 6 && info->ceiling_color[i] != -1)
		exit_prog("Doublon couleur C", info);
	if (who == 5)
		info->floor_color[i] = val;
	else
		info->ceiling_color[i] = val;
}

void	verif_empty_color(char *line, int *i, int *who, t_info_cub *info)
{
	int		start;
	int		z;
	int		idx;
	char	*tmp;

	*i = cut_space(line, i);
	if (!is_valid(line, i))
		color_error(line, NULL, info);
	idx = 0;
	while (idx < 3)
	{
		*i = cut_space(line, i);
		start = *i;
		while (line[*i] && is_digit(line[*i]))
			(*i)++;
		z = cut_space(line, i);
		if ((idx < 2 && line[z] != ',') || (idx == 2 && line[z] != '\0'))
			color_error(line, NULL, info);
		tmp = ft_strdup_n(line, start, *i);
		if (has_only_space(tmp))
			color_error(line, tmp, info);
		set_color(tmp, info, idx, *who);
		free(tmp);
		if (line[*i] == ',' && idx < 2)
			(*i)++;
		idx++;
	}
}

void	take_info_color(char *line, int *who, int *i, t_info_cub *info)
{
	*i = *i + 1;
	verif_empty_color(line, i, who, info);
}
