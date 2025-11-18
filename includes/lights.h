/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:00 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:25:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vec4.h"
# include "color.h"

typedef struct s_cub	t_cub;

typedef struct s_ambient_light
{
	double	ratio;
	t_color	color;
	t_vec3	colorN;
}	t_ambient_light;

typedef struct s_light
{
	t_vec3	point;
	double	brightness;
	// t_color	color;
}	t_light;

#endif
