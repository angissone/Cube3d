/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:02:15 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 21:49:45 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define DEBUG 1

# define ERROR_MLX "Error CUB: Can not instantiate mlx.\n"
# define ERROR_WINDOW "Error CUB: Can not instantiate window.\n"
# define ERROR_IMAGE "Error CUB: Can not instantiate image.\n"
# define ERROR_ADDR "Error CUB: Can not instantiate buffer address.\n"
# define ERROR_MALLOC "Error CUB: Malloc failed.\n"
# define ERROR_ARGV "Error CUB: Expected 1 argument (file path) or -h \
(for help).\n"
# define COMMANDS "Quit=esc Move=asdw Rotate=UP/DOWN=\n"
# define WINDOW_TITLE "Mini RT"
# define HELP "-h"
# define ON_DESTROY 17
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOUSE 6
# define KEY_PRESS_MASK 1
# define FREE_STASH -1
# define MAX_DOUBLE	1e+30
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_GREY 0xAAAAAA
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_LIGHT_BLUE 0x80B4FF
# define COLOR_BCKGND_TOP COLOR_LIGHT_BLUE
# define COLOR_BCKGND_BOTTOM COLOR_WHITE
# define COLOR_BCKGND COLOR_GREY
# define C_255_999  255.999f
# define PI 3.14159265358979323846
# define CAMERA_MAX_DEPTH 10
# define ANGLE_FOV 90
# define EPSILON .001
# define EPSILON_MUR .001
# define C_0_5 0.5
# define V_POINT 0
# define V_VECTOR 1
# define MOVE_STEP .02
# define ANGLE_MOUSE .01
# define CHAR_0 '0'
# define CHAR_1 '1'
# define SIDE_VERTICAL 0
# define SIDE_HORIZONTAL 1
# define SCREEN_RATIO 2

typedef enum e_keys
{
	KEY_NONE = 0,
	KEY_ESC,
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_EXTRA1,
	KEY_EXTRA2,
	KEY_I,
}	t_keys;

#endif
