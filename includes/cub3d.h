/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:29:40 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 15:45:23 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "param.h"
# include "vec3.h"
# include "color.h"
# include "vertex.h"
# include "cub.h"
# include "math.h"
# include "constants.h"
# include "mlx.h"
# include "libft.h"
# include "ray.h"
# include "mat4.h"
# include "camera.h"
# include "interval.h"
# include "parser.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <X11/keysym.h>

int			cub_render_hook(void *param);
int			cub_mouse_hook(int buton, int x, int y, void *param);
int			cub_close_window(void *param);
int			cub_hook_key(int keycode, void *param);
void		cub_putpixel(t_cub *m, int x, int y, int color);
void		cub_exit(char *message, t_cub *m);
void		cub_free_null(void **ptr);
void		cub_free_all(t_cub **m);
void		cub_free_mat(char **mat, int n);
void		cub_free_tokens(char ***tokens);
void		cub_clear_window(t_cub *m, int color);
void		cub_draw_window(t_cub *m);
void		cub_init(t_cub **m, char *filepath);
void		cub_render(t_cub *m);
void		cub_print_var_d(char *s, double n);
void		cub_print_vec(char *s, t_vec3 v);
void		cub_debug_camera(t_cub *m);
double		random_double(t_cub *m);
double		random_double_range(t_cub *m, double min, double max);
void		cub_print_color(char *s, t_vec3 v);
void		cub_do_hook_key(t_cub *m, int keycode);
void		cub_init_texture(t_cub *m);

#endif
