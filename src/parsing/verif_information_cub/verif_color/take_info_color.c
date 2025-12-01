/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/12/01 13:12:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_color(int val, t_info_cub *info, int i, int who)
{
	if (who == 5)
		info->floor_color[i] = val;
	else
		info->ceiling_color[i] = val;
}

char	*extract_component(char *line, int *i,
				int idx, t_info_cub *info)
{
	int		start;
	int		z;
	char	*tmp;

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
	return (tmp);
}

static int	get_value(char *tmp, char *line, t_info_cub *info)
{
	int	val;

	val = atoi(tmp);
	if (val < 0 || val > 255)
	{
		free(tmp);
		free(line);
		exit_prog("Valeur RGB hors limites", info);
	}
	return (val);
}

void	verif_empty_color(char *line, int *i, int *who, t_info_cub *info)
{
	int		idx;
	int		val;
	char	*tmp;

	*i = cut_space(line, i);
	if (!is_valid(line, i))
		color_error(line, NULL, info);
	idx = 0;
	while (idx < 3)
	{
		tmp = extract_component(line, i, idx, info);
		val = get_value(tmp, line, info);
		if (*who == 5 && info->floor_color[idx] != -1)
			color_error(line, tmp, info);
		if (*who == 6 && info->ceiling_color[idx] != -1)
			color_error(line, tmp, info);
		set_color(val, info, idx, *who);
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
