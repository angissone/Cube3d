/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:49:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/24 18:16:27 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_hook_key(int keycode, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	if (m->mlx)
	{
		cub_do_hook_key(m, keycode);
	}
	return (0);
}

int	cub_mouse_hook(int x, int y, void *param)
{
	t_cub	*m;
	int		dx;

	(void) y;
	m = (t_cub *)param;
	if (m->mlx)
	{
	 	 if (x != m->mouse.x)
		 {
			dx = x - m->mouse.x;
			m->player_dir = cub_rotate_xy(m, m->player_dir, ANGLE_MOUSE * dx);
			m->mouse.x = x;
		 }
	}
	return (0);
}

int	cub_render_hook(void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	m->seed = 10;
	// a voir cub_clear_window(m, COLOR_BLACK);
	cub_render(m);
	mlx_put_image_to_window(m->mlx, m->window, m->image, 0, 0);
	return (0);
}
