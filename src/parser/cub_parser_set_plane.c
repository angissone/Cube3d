/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:58:36 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_plane_debug(t_plane *plane, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	cub_print_vec("plane point     ", plane->point);
	cub_print_vec("plane normal    ", plane->normal);
	printf("[plane color     ][%d,%d,%d]\n\n",
		plane->color.r,
		plane->color.g,
		plane->color.b);
}

static void	parse_plane_point(t_plane *plane, t_cub **m, char **tokens)
{
	int	i;

	(*m)->plane_xyz_tokens = ft_split(tokens[1], ',');
	if ((*m)->plane_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->plane_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_PL_DATA, *m);
	i = 0;
	while (i < 3)
	{
		plane->point.v[i] = ft_atod((*m)->plane_xyz_tokens[i]);
		if (is_nan(plane->point.v[i]))
			cub_exit(ERROR_INVALID_PL_DATA, *m);
		i++;
	}
}

static void	parse_plane_normal(t_plane *plane, t_cub **m, char **tokens)
{
	int	i;

	(*m)->plane_normal_tokens = ft_split(tokens[2], ',');
	if ((*m)->plane_normal_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->plane_normal_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_PL_DATA, *m);
	i = 0;
	while (i < 3)
	{
		plane->normal.v[i] = ft_atod((*m)->plane_normal_tokens[i]);
		if (is_nan(plane->normal.v[i])
			|| plane->normal.v[i] < -1.0
			|| plane->normal.v[i] > 1.0)
			cub_exit(ERROR_INVALID_PL_DATA, *m);
		i++;
	}
}

static void	parse_plane_rgb(t_plane *plane, t_cub **m, char **tokens)
{
	int	i;

	(*m)->plane_rgb_tokens = ft_split(tokens[3], ',');
	if ((*m)->plane_rgb_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->plane_rgb_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_PL_DATA, *m);
	plane->color.r = (unsigned char)ft_atod((*m)->plane_rgb_tokens[0]);
	plane->color.g = (unsigned char)ft_atod((*m)->plane_rgb_tokens[1]);
	plane->color.b = (unsigned char)ft_atod((*m)->plane_rgb_tokens[2]);
	if (is_nan(plane->color.r)
		|| is_nan(plane->color.g)
		|| is_nan(plane->color.b)
		|| plane->color.r < 0 || plane->color.r > 255
		|| plane->color.g < 0 || plane->color.g > 255
		|| plane->color.b < 0 || plane->color.b > 255)
		cub_exit(ERROR_INVALID_PL_DATA, *m);
}

static void	add_plane_to_list(t_cub **m, t_plane *plane)
{
	t_plane	*new_planes;

	new_planes = ft_calloc(((*m)->nb_plane + 1), sizeof(t_plane));
	if (!new_planes)
		cub_exit(ERROR_MALLOC, *m);
	if ((*m)->plane)
	{
		ft_memcpy(new_planes, (*m)->plane, (*m)->nb_plane * sizeof(t_plane));
		free((*m)->plane);
	}
	new_planes[(*m)->nb_plane] = *plane;
	(*m)->plane = new_planes;
	(*m)->nb_plane += 1;
}

void	set_one_plane(t_cub **m, char **tokens)
{
	t_plane	plane;

	validate_token_count(tokens, m, 4, ERROR_INVALID_PL_DATA);
	parse_plane_point(&plane, m, tokens);
	parse_plane_normal(&plane, m, tokens);
	parse_plane_rgb(&plane, m, tokens);
	add_plane_to_list(m, &plane);
	print_plane_debug(&plane, tokens);
	cub_free_tokens(&(*m)->plane_xyz_tokens);
	cub_free_tokens(&(*m)->plane_normal_tokens);
	cub_free_tokens(&(*m)->plane_rgb_tokens);
}
