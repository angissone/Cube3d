/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_acces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:00:33 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/03 14:00:33 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_map(const t_cub *m, int lig, int col)
{
	int	row;
	int	len;

	row = m->map_height - 1 - lig;
	if (row < 0 || row >= m->map_height)
		return (CHAR_1);
	if (m->map[row] == NULL)
		return (CHAR_1);
	len = ft_strlen(m->map[row]);
	if (col < 0 || col >= len)
		return (CHAR_1);
	return (m->map[row][col]);
}

int	is_inside_map(t_cub *m, int lig, int col)
{
	int	row;
	int	len;

	row = m->map_height - 1 - lig;
	if (row < 0 || row >= m->map_height)
		return (false);
	if (m->map[row] == NULL)
		return (false);
	len = ft_strlen(m->map[row]);
	if (col < 0 || col >= len)
		return (false);
	return (true);
}
