/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:49:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 18:21:43 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define FRAME_TIME_US (1000000 / TARGET_FPS)


void limit_fps()
{
    static struct timeval prev = {0};
    struct timeval now;
    long elapsed;
    long sleep_us;
	//long fram_time_us;

    gettimeofday(&now, NULL);

    if (prev.tv_sec != 0)
    {
        elapsed = (now.tv_sec - prev.tv_sec) * 1000000 +
                  (now.tv_usec - prev.tv_usec);

        if (elapsed < FRAME_TIME_US)
        {
            sleep_us = FRAME_TIME_US - elapsed;
            usleep(sleep_us);
        }
    }

    prev = now;
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
	limit_fps();
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
