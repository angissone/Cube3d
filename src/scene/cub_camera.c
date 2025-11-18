/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:59:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:40:20 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_camera_vectors(t_cub *m)
{
	t_vec3		v;
	t_camera	*c;

	c = &m->camera;
	c->viewport_u = vec3_init(m->viewport_w, 0, 0);
	c->viewport_v = vec3_init(0, -m->viewport_h, 0);
	v = vec3_init(m->viewport_w / 2, -m->viewport_h / 2, m->focal_length);
	c->upper_left_corner = vec3_sub(c->center, v);
	c->pixel_delta_u = vec3_scale(c->viewport_u, 1.0 / m->width);
	c->pixel_delta_v = vec3_scale(c->viewport_v, 1.0 / m->height);
	c->pixel00_loc = vec3_add(c->upper_left_corner,
			vec3_scale(vec3_add(c->pixel_delta_u, c->pixel_delta_v),
				0.5));
}

static void	init_camera_wh(t_cub *m)
{
	m->focal_length = 1;
	m->viewport_w = 2.0 * m->focal_length
		* tan(degrees_to_radians(m->camera.fov_angle / 2.0));
	m->viewport_h = m->viewport_w * ((double)m->height / (double)m->width);
}

void	cub_init_camera(t_cub *m)
{
	init_camera_wh(m);
	init_camera_vectors(m);
	(m)->camera.max_depth = CAMERA_MAX_DEPTH;
}

// // test
// static void init_camera_vectors(t_cub *m)
// {
//     t_camera *c = &m->camera;

//     // Normaliser l'axis pour être sûr
//     c->axis = vec3_normalize(c->axis);

//     // Choisir un up global (Y+ par défaut)
//     t_vec3 up = vec3_init(0, 1, 0, 0);
//     // si axis parallèle à up, choisir un autre up
//     if (fabs(vec3_dot(c->axis, up)) > 0.999)
//         up = vec3_init(1, 0, 0, 0);

//     // Calcul des axes locaux de la caméra
//     t_vec3 w = vec3_scale(c->axis, -1);          // backward
//     t_vec3 u = vec3_normalize(vec3_cross(up, w)); // droite
//     t_vec3 v = vec3_cross(w, u);                 // haut

//     // Largeur et hauteur du viewport en unités monde
//     double viewport_w = 2.0 * m->focal_length * tan(degrees_to_radians(c->fov_angle / 2.0));
//     double viewport_h = viewport_w * ((double)m->height / (double)m->width);

//     // Vecteurs du viewport dans le repère caméra
//     c->viewport_u = vec3_scale(u, viewport_w);
//     c->viewport_v = vec3_scale(v, viewport_h);

//     // Coin supérieur gauche du viewport
//     t_vec3 half_u = vec3_scale(u, viewport_w / 2.0);
//     t_vec3 half_v = vec3_scale(v, viewport_h / 2.0);
//     c->upper_left_corner = vec3_sub(
//         vec3_add(c->center, vec3_scale(c->axis, m->focal_length)), // avancer vers la scène
//         vec3_add(half_u, half_v)                                  // reculer à gauche et en haut
//     );

//     // Delta pour parcourir pixel par pixel
//     c->pixel_delta_u = vec3_scale(c->viewport_u, 1.0 / m->width);
//     c->pixel_delta_v = vec3_scale(c->viewport_v, -1.0 / m->height); // - pour descendre

//     // Position du pixel (0,0) au centre du pixel
//     c->pixel00_loc = vec3_add(c->upper_left_corner,
//         vec3_scale(vec3_add(c->pixel_delta_u, c->pixel_delta_v), 0.5));
// }

// void cub_init_camera(t_cub *m)
// {
//     // Calcul focal length et viewport dimensions
//     m->focal_length = 1;
//     m->viewport_w = 2.0 * m->focal_length
//         * tan(degrees_to_radians(m->camera.fov_angle / 2.0));
//     m->viewport_h = m->viewport_w * ((double)m->height / (double)m->width);

//     // Initialiser les vecteurs de la caméra
//     init_camera_vectors(m);

//     m->camera.max_depth = CAMERA_MAX_DEPTH;
// }