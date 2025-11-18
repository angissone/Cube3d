/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:59:02 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_sphere_debug(t_sphere *sphere, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	cub_print_vec("sphere center   ", sphere->center);
	printf("[sphere radius   ][%0.2f]\n", sphere->radius);
	printf("[sphere color    ][%d,%d,%d]\n\n",
		sphere->color.r,
		sphere->color.g,
		sphere->color.b);
}

static void	parse_sphere_center(t_sphere *sphere, t_cub **m, char **tokens)
{
	int	i;

	(*m)->sphere_xyz_tokens = ft_split(tokens[1], ',');
	if ((*m)->sphere_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->sphere_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_SP_DATA, *m);
	i = 0;
	while (i < 3)
	{
		sphere->center.v[i] = ft_atod((*m)->sphere_xyz_tokens[i]);
		if (is_nan(sphere->center.v[i]))
			cub_exit(ERROR_INVALID_SP_DATA, *m);
		i++;
	}
}

static void	parse_sphere_radius(t_sphere *sphere, char **tokens)
{
	sphere->radius = ft_atod(tokens[2]) / 2.0;
	if (is_nan(sphere->radius) || sphere->radius <= 0.0)
		cub_exit(ERROR_INVALID_SP_DATA, NULL);
}

static void	parse_sphere_rgb(t_sphere *sphere, t_cub **m, char **tokens)
{
	int	i;

	(*m)->sphere_rgb_tokens = ft_split(tokens[3], ',');
	if ((*m)->sphere_rgb_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->sphere_rgb_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_SP_DATA, *m);
	sphere->color.r = (unsigned char)ft_atod((*m)->sphere_rgb_tokens[0]);
	sphere->color.g = (unsigned char)ft_atod((*m)->sphere_rgb_tokens[1]);
	sphere->color.b = (unsigned char)ft_atod((*m)->sphere_rgb_tokens[2]);
	if (is_nan(sphere->color.r)
		|| is_nan(sphere->color.g)
		|| is_nan(sphere->color.b)
		|| sphere->color.r < 0 || sphere->color.r > 255
		|| sphere->color.g < 0 || sphere->color.g > 255
		|| sphere->color.b < 0 || sphere->color.b > 255)
		cub_exit(ERROR_INVALID_SP_DATA, *m);
}

static void	add_sphere_to_list(t_cub **m, t_sphere *sphere)
{
	t_sphere	*new_spheres;

	new_spheres = ft_calloc(((*m)->nb_sphere + 1), sizeof(t_sphere));
	if (!new_spheres)
		cub_exit(ERROR_MALLOC, *m);
	if ((*m)->sphere)
	{
		ft_memcpy(new_spheres, (*m)->sphere,
			(*m)->nb_sphere * sizeof(t_sphere));
		free((*m)->sphere);
	}
	new_spheres[(*m)->nb_sphere] = *sphere;
	(*m)->sphere = new_spheres;
	(*m)->nb_sphere += 1;
}

void	set_one_sphere(t_cub **m, char **tokens)
{
	t_sphere	sphere;

	validate_token_count(tokens, m, 4, ERROR_INVALID_SP_DATA);
	parse_sphere_center(&sphere, m, tokens);
	parse_sphere_radius(&sphere, tokens);
	parse_sphere_rgb(&sphere, m, tokens);
	add_sphere_to_list(m, &sphere);
	print_sphere_debug(&sphere, tokens);
	cub_free_tokens(&(*m)->sphere_xyz_tokens);
	cub_free_tokens(&(*m)->sphere_rgb_tokens);
}
