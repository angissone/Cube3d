/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:25 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"
# include "cub.h"
# include "get_next_line.h"
# include <stdbool.h> // !@#$!! Pourquoi n'est il pas vu de cub3d.h ? !@#$!!

void	set_ambient_light(t_cub **m, char **tokens);
void	set_camera(t_cub **m, char **tokens);
void	set_light(t_cub **m, char **tokens);
void	set_one_sphere(t_cub **m, char **tokens);
void	set_one_cylinder(t_cub **m, char **tokens);
void	set_one_plane(t_cub **m, char **tokens);
bool	is_nan(double x);
void	validate_token_count(char **tokens, t_cub **m, int expected_count,
				char *error_msg);

#endif