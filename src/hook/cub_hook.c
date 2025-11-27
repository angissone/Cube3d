/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:49:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 15:37:34 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_hook_key(int keycode, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	if (m->mlx)
		cub_do_hook_key(m, keycode);
	return (0);
}

int	cub_mouse_hook(int x, int y, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	if (m->mlx)
	{
		cub_do_hook_mouse(m, x, y);
	}
	return (0);
}

int	cub_render_hook(void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	m->seed = 10;
	cub_do_hook_key_2(m);
	cub_render(m);
	mlx_put_image_to_window(m->mlx, m->window, m->image, 0, 0);
	return (0);
}

int	cub_hook_key_pressed(int keycode, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	if (m->mlx)
		m->key[get_key(keycode)] = 1;
	return (0);
}

int	cub_hook_key_released(int keycode, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	if (m->mlx)
		m->key[get_key(keycode)] = 0;
	return (0);
}