/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:58:23 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_light_point(t_cub **m, char **tokens)
{
	int	i;

	(*m)->light_xyz_tokens = ft_split(tokens[1], ',');
	if ((*m)->light_xyz_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->light_xyz_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_L_DATA, *m);
	i = 0;
	while (i < 3)
	{
		(*m)->light.point.v[i] = ft_atod((*m)->light_xyz_tokens[i]);
		if (is_nan((*m)->light.point.v[i]))
			cub_exit(ERROR_INVALID_L_DATA, *m);
		i++;
	}
}

static void	parse_light_brightness(t_cub **m, char **tokens)
{
	(*m)->light.brightness = ft_atod(tokens[2]);
	if (is_nan((*m)->light.brightness)
		|| (*m)->light.brightness < 0.0
		|| (*m)->light.brightness > 1.0)
		cub_exit(ERROR_INVALID_L_DATA, *m);
}

static void	print_light_debug(t_cub **m, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	cub_print_vec("light point     ", (*m)->light.point);
	printf("[light brightness][%0.2f]\n\n", (*m)->light.brightness);
}

void	set_light(t_cub **m, char **tokens)
{
	validate_token_count(tokens, m, 3, ERROR_INVALID_L_DATA);
	parse_light_point(m, tokens);
	parse_light_brightness(m, tokens);
	print_light_debug(m, tokens);
}
