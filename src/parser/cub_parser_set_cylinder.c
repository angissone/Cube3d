/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_cylinder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:58:08 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_cylinder_debug(t_cylinder *cylinder, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	cub_print_vec("cylinder center  ", cylinder->center);
	cub_print_vec("cylinder axis    ", cylinder->axis);
	printf("[cylinder diameter][%0.2f]\n", cylinder->diameter);
	printf("[cylinder height  ][%0.2f]\n", cylinder->height);
	printf("[cylinder color   ][%d,%d,%d]\n\n",
		cylinder->color.r,
		cylinder->color.g,
		cylinder->color.b);
}

void	parse_cylinder_center(t_cylinder *cylinder, t_cub **m, char **tokens)
{
	int	i;

	(*m)->cylinder_xyz_tokens = ft_split(tokens[1], ',');
	if ((*m)->cylinder_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->cylinder_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_CY_DATA, *m);
	i = 0;
	while (i < 3)
	{
		cylinder->center.v[i] = ft_atod((*m)->cylinder_xyz_tokens[i]);
		if (is_nan(cylinder->center.v[i]))
			cub_exit(ERROR_INVALID_CY_DATA, *m);
		i++;
	}
}

static void	parse_cylinder_axis(t_cylinder *cylinder, t_cub **m, char **tokens)
{
	int	i;

	(*m)->cylinder_axis_tokens = ft_split(tokens[2], ',');
	if ((*m)->cylinder_axis_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->cylinder_axis_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_CY_DATA, *m);
	i = 0;
	while (i < 3)
	{
		cylinder->axis.v[i] = ft_atod((*m)->cylinder_axis_tokens[i]);
		if (is_nan(cylinder->axis.v[i])
			|| cylinder->axis.v[i] < -1.0
			|| cylinder->axis.v[i] > 1.0)
			cub_exit(ERROR_INVALID_CY_DATA, *m);
		i++;
	}
}

static void	parse_cylinder_dimensions(t_cylinder *cylinder, char **tokens)
{
	cylinder->diameter = ft_atod(tokens[3]);
	if (is_nan(cylinder->diameter) || cylinder->diameter <= 0.0)
		cub_exit(ERROR_INVALID_CY_DATA, NULL);
	cylinder->height = ft_atod(tokens[4]);
	if (is_nan(cylinder->height) || cylinder->height <= 0.0)
		cub_exit(ERROR_INVALID_CY_DATA, NULL);
}

static void	parse_cylinder_rgb(t_cylinder *cylinder, t_cub **m, char **tokens)
{
	int	i;

	(*m)->cylinder_rgb_tokens = ft_split(tokens[5], ',');
	if ((*m)->cylinder_rgb_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->cylinder_rgb_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_CY_DATA, *m);
	cylinder->color.r = (unsigned char)ft_atod((*m)->cylinder_rgb_tokens[0]);
	cylinder->color.g = (unsigned char)ft_atod((*m)->cylinder_rgb_tokens[1]);
	cylinder->color.b = (unsigned char)ft_atod((*m)->cylinder_rgb_tokens[2]);
	if (is_nan(cylinder->color.r)
		|| is_nan(cylinder->color.g)
		|| is_nan(cylinder->color.b)
		|| cylinder->color.r < 0 || cylinder->color.r > 255
		|| cylinder->color.g < 0 || cylinder->color.g > 255
		|| cylinder->color.b < 0 || cylinder->color.b > 255)
		cub_exit(ERROR_INVALID_CY_DATA, *m);
}

static void	add_cylinder_to_list(t_cub **m, t_cylinder *cylinder)
{
	t_cylinder	*new_cylinders;

	new_cylinders = ft_calloc(((*m)->nb_cylinder + 1), sizeof(t_cylinder));
	if (!new_cylinders)
		cub_exit(ERROR_MALLOC, *m);
	if ((*m)->cylinder)
	{
		ft_memcpy(new_cylinders, (*m)->cylinder,
			(*m)->nb_cylinder * sizeof(t_cylinder));
		free((*m)->cylinder);
	}
	new_cylinders[(*m)->nb_cylinder] = *cylinder;
	(*m)->cylinder = new_cylinders;
	(*m)->nb_cylinder += 1;
}

void	set_one_cylinder(t_cub **m, char **tokens)
{
	t_cylinder	cylinder;

	validate_token_count(tokens, m, 6, ERROR_INVALID_CY_DATA);
	parse_cylinder_center(&cylinder, m, tokens);
	parse_cylinder_axis(&cylinder, m, tokens);
	parse_cylinder_dimensions(&cylinder, tokens);
	parse_cylinder_rgb(&cylinder, m, tokens);
	add_cylinder_to_list(m, &cylinder);
	print_cylinder_debug(&cylinder, tokens);
	cub_free_tokens(&(*m)->cylinder_xyz_tokens);
	cub_free_tokens(&(*m)->cylinder_axis_tokens);
	cub_free_tokens(&(*m)->cylinder_rgb_tokens);
}
