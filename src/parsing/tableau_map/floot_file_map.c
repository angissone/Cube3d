/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floot_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:10 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 17:06:08 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

typedef struct s_flood
{
	int	**vis;
	int	err;
}	t_flood;

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
				info->player.x = *px;
				info->player.y = *py;
				info->player.z = c;
				(*count)++;
			}
			x++;
		}
		y++;
	}
}

static int	**alloc_visited(t_info_cub *info)
{
	int		**vis;
	int		y;
	int		x;
	int		len;

	vis = malloc(info->nbr_line_tab * sizeof(int *));
	if (!vis)
		exit_prog(MSG_007, info);
	y = 0;
	while (y < info->nbr_line_tab)
	{
		len = ft_strlen_z(info->map[y]);
		vis[y] = malloc(len * sizeof(int));
		if (!vis[y])
			exit_prog(MSG_007, info);
		x = 0;
		while (x < len)
		{
			vis[y][x] = 0;
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

static void	flood(t_info_cub *info, int y, int x, t_flood *f)
{
	int	len;

	if (f->err)
		return ;
	if (y < 0 || y >= info->nbr_line_tab)
		f->err = 1;
	else
	{
		len = ft_strlen_z(info->map[y]);
		if (x < 0 || x >= len || info->map[y][x] == ' ')
			f->err = 1;
	}
	if (f->err)
		return ;
	if (info->map[y][x] == '1' || f->vis[y][x])
		return ;
	f->vis[y][x] = 1;
	flood(info, y + 1, x, f);
	flood(info, y - 1, x, f);
	flood(info, y, x + 1, f);
	flood(info, y, x - 1, f);
}

int	check_map_closed(t_info_cub *info)
{
	t_flood	f;
	int		py;
	int		px;
	int		count;

	py = -1;
	px = -1;
	count = 0;
	find_player(info, &py, &px, &count);
	if (count != 1)
		exit_prog(MSG_009, info);
	f.err = 0;
	f.vis = alloc_visited(info);
	flood(info, py, px, &f);
	free_visited(f.vis, info->nbr_line_tab);
	if (f.err)
		exit_prog(MSG_008, info);
	return (0);
}
