/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floot_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:10 by zmata             #+#    #+#             */
/*   Updated: 2025/12/01 13:05:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

static int	flood_check_err(int **vis, int lines)
{
	int	y;
	int	x;

	y = 0;
	while (y < lines)
	{
		x = 0;
		while (vis[y][x] != -2)
		{
			if (vis[y][x] == -1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	**alloc_visited(t_info_cub *info)
{
	int		**vis;
	int		y;
	int		x;
	int		len;

	vis = malloc(info->nbr_line_tab * sizeof(int *));
	if (!vis)
		exit_prog("Erreur malloc visited", info);
	y = 0;
	while (y < info->nbr_line_tab)
	{
		len = ft_strlen(info->map[y]);
		vis[y] = malloc((len + 1) * sizeof(int));
		if (!vis[y])
			exit_prog("Erreur malloc visited", info);
		x = 0;
		while (x < len)
		{
			vis[y][x] = -2;
			x++;
		}
		y++;
	}
	return (vis);
}

static void	free_visited(int **vis, int lines)
{
	int	y;

	y = 0;
	while (y < lines)
	{
		free(vis[y]);
		y++;
	}
	free(vis);
}

static void	check_one_player(int count, t_info_cub *info)
{
	if (count != 1)
		exit_prog("Nombre de joueur invalide", info);
}

int	check_map_closed(t_info_cub *info)
{
	int		py;
	int		px;
	int		count;
	int		**vis;

	py = -1;
	px = -1;
	count = 0;
	find_player(info, &py, &px, &count);
	check_one_player(count, info);
	vis = alloc_visited(info);
	flood_step(info, py, px, vis);
	if (flood_check_err(vis, info->nbr_line_tab))
	{
		free_visited(vis, info->nbr_line_tab);
		exit_prog("Map non fermee", info);
	}
	free_visited(vis, info->nbr_line_tab);
	return (0);
}
