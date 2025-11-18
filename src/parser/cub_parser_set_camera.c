/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:57:46 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_camera_center(t_cub **m, char **tokens)
{
	int	i;

	(*m)->camera_center_xyz_tokens = ft_split(tokens[1], ',');
	if ((*m)->camera_center_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->camera_center_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_C_DATA, *m);
	i = 0;
	while (i < 3)
	{
		(*m)->camera.center.v[i] = ft_atod((*m)->camera_center_xyz_tokens[i]);
		if (is_nan((*m)->camera.center.v[i]))
			cub_exit(ERROR_INVALID_C_DATA, *m);
		i++;
	}
}

static void	parse_camera_axis(t_cub **m, char **tokens)
{
	int	i;

	(*m)->camera_axis_xyz_tokens = ft_split(tokens[2], ',');
	if ((*m)->camera_axis_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->camera_axis_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_C_DATA, *m);
	i = 0;
	while (i < 3)
	{
		(*m)->camera.axis.v[i] = ft_atod((*m)->camera_axis_xyz_tokens[i]);
		if (is_nan((*m)->camera.axis.v[i])
			|| (*m)->camera.axis.v[i] > 1.0
			|| (*m)->camera.axis.v[i] < -1.0)
			cub_exit(ERROR_INVALID_C_DATA, *m);
		i++;
	}
}

static void	parse_camera_fov(t_cub **m, char **tokens)
{
	(*m)->camera.fov_angle = ft_atod(tokens[3]);
	if (is_nan((*m)->camera.fov_angle)
		|| (*m)->camera.fov_angle < 0
		|| (*m)->camera.fov_angle > 180)
		cub_exit(ERROR_INVALID_C_DATA, *m);
}

static void	print_camera_debug(t_cub **m, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	cub_print_vec("camera center   ", (*m)->camera.center);
	cub_print_vec("camera axis     ", (*m)->camera.axis);
	printf("[camera fov angle][%0.2f]\n\n", (*m)->camera.fov_angle);
}

void	set_camera(t_cub **m, char **tokens)
{
	validate_token_count(tokens, m, 4, ERROR_INVALID_C_DATA);
	parse_camera_center(m, tokens);
	parse_camera_axis(m, tokens);
	parse_camera_fov(m, tokens);
	print_camera_debug(m, tokens);
}
