/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:40:35 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:25:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_H
# define PARAM_H

# include "cub.h"

// typedef struct s_param
// {
// 	t_cub		*m;
// 	double		a;
// 	double		b;
// 	t_vec3		v1;
// 	t_vec3		v2;
// 	double		x;
// 	double		y;
// }	t_param;

typedef struct s_param_sphere_hit // CHANGE TO t_param_hit ?
{
	t_ray			ray;
	t_interval		inter;
	t_hit_record	*rec;
	int				i; // UNDERSTAND USAGE TO MAKE IT SPECIFIC TO SPHERE, PL, CY IF NECESSARY

}	t_param_sphere_hit;

#endif
