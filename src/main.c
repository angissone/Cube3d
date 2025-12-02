/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:33:53 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 16:18:20 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "cub3d.h"

void	cub(char *filepath)
{
	t_cub	*m;

	cub_init(&m, filepath);
	m->camera.max_depth = 10;
	cub_draw_window(m);
	cub_free_all(&m);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], HELP))
			cub(argv[1]);
		else
			printf(COMMANDS);
	}
	else
		printf(ERROR_ARGV);
}
