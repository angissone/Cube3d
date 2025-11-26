/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:09:35 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/26 15:50:58 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec3	ray_at(t_ray ray, double t)
{
	t_vec3	ret;

	ret = vec3_scale(ray.dir, t);
	ret = vec3_add(ret, ray.origin);
	return (ret);
}
