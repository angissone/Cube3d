/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floot_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:10 by zmata             #+#    #+#             */
/*   Updated: 2025/11/28 17:22:34 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

static void	find_player(t_info_cub *info, int *py, int *px, int *count)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < info->nbr_line_tab)
	{
		x = 0;
		while (info->map[y][x])
		{
			c = info->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				*py = y;
				*px = x;
				(*count)++;
			}
			x++;
		}
		y++;
	}
}

static void	flood(t_info_cub *info, int y, int x, int **vis, int *err)
{
	int	len;

	if (*err)
		return ;
	if (y < 0 || y >= info->nbr_line_tab)
	{
		*err = 1;
		return ;
	}
	len = ft_strlen(info->map[y]);
	if (x < 0 || x >= len)
	{
		*err = 1;
		return ;
	}
	if (info->map[y][x] == ' ')
	{
		*err = 1;
		return ;
	}
	if (info->map[y][x] == '1' || vis[y][x])
		return ;
	vis[y][x] = 1;
	flood(info, y + 1, x, vis, err);
	flood(info, y - 1, x, vis, err);
	flood(info, y, x + 1, vis, err);
	flood(info, y, x - 1, vis, err);
}

int	check_map_closed(t_info_cub *info)
{
	int		py;
	int		px;
	int		count;
	int		y;
	int		err;
	int		**vis;
	int		i;
	int		len;

	py = -1;
	px = -1;
	count = 0;
	err = 0;
	find_player(info, &py, &px, &count);
	if (count != 1)
		exit_prog("Nombre de joueur invalide", info);
	vis = malloc(info->nbr_line_tab * sizeof(int *));
	if (!vis)
		exit_prog("Erreur malloc visited", info);
	y = 0;
	while (y < info->nbr_line_tab)
	{
		len = ft_strlen(info->map[y]);
		vis[y] = malloc(len * sizeof(int));
		if (!vis[y])
			exit_prog("Erreur malloc visited", info);
		i = 0;
		while (i < len)
		{
			vis[y][i] = 0;
			i++;
		}
		y++;
	}
	flood(info, py, px, vis, &err);
	y = 0;
	while (y < info->nbr_line_tab)
	{
		free(vis[y]);
		y++;
	}
	free(vis);
	if (err)
		exit_prog("Map non fermee", info);
	return (0);
}
