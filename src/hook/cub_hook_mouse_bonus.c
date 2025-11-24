/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_mouse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:37:30 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/24 21:54:30 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_do_hook_mouse(t_cub *m, int x, int y)
{
	int		dx;

	{
		(void) y;
		if (x != m->mouse.x)
		{
			dx = x - m->mouse.x;
			m->player_dir = cub_rotate_xy(m, m->player_dir, ANGLE_MOUSE * dx);
			m->mouse.x = x;
		}
	}
}

