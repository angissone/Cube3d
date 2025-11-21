/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:29 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 14:39:57 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

typedef struct s_mat4
{
	double m[4][4];
} t_mat4;

t_vec3	mat4_mult_vec3(t_mat4 m, t_vec3 v);
double	cub_degrees_to_radians(double degrees);
t_vec2	cub_rotate_xy(t_cub *m, t_vec2 p, double angle);
double	cub_div(double x, double y);
void	cub_move_forward(t_vec2 *p, t_vec2 dir, double step);
void	cub_move_side(t_vec2 *p, t_vec2 dir, double step);

#endif
