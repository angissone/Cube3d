/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floot_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:06:05 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/01 13:19:55 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	find_player(t_info_cub *info, int *py, int *px, int *count)
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

void	flood_step(t_info_cub *info, int y, int x, int **vis)
{
	int	len;

	len = ft_strlen(info->map[y]);
	if (x < 0 || x >= len)
		return ;
	if (info->map[y][x] == '1' || vis[y][x])
		return ;
	if (info->map[y][x] == ' ')
	{
		vis[y][x] = -1;
		return ;
	}
	vis[y][x] = 1;
	flood_step(info, y + 1, x, vis);
	flood_step(info, y - 1, x, vis);
	flood_step(info, y, x + 1, vis);
	flood_step(info, y, x - 1, vis);
}
