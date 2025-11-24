/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:02:15 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/24 19:08:14 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define DEBUG 1

// # define FALSE 0 // type int replaced by more explicit type bool true/false
// # define TRUE 1 // type int replaced by more explicit type bool true/false
# define ERROR_MLX "Error CUB: Can not instantiate mlx.\n"
# define ERROR_WINDOW "Error CUB: Can not instantiate window.\n"
# define ERROR_IMAGE "Error CUB: Can not instantiate image.\n"
# define ERROR_ADDR "Error CUB: Can not instantiate buffer address.\n"
# define ERROR_MALLOC "Error CUB: Malloc failed.\n"
# define ERROR_ARGV "Error CUB: Expected 1 argument (file path) or -h \
(for help).\n"
# define ERROR_WRONG_EXT "Error\nError CUB: Wrong file extension. \
Shall be a *.rt file.\n"
# define ERROR_FILE_NOT_FOUND "Error\nError CUB: File not found.\n"
# define ERROR_OPEN_FILE "Error\nError CUB: Issue when opening input file.\n"
# define ERROR_EMPTY_FILE "Error\nError CUB: File is empty.\n"
# define ERROR_WRONG_OBJECT_ID "Error\nError CUB: Wrong object identifier. \
Shall be A, C, L, pl, sp, cy.\n"
# define ERROR_INVALID_AL_DATA "Error\nError CUB: Invalid ambiant light data.\n\
Check ambiant lighting ratio (normalized values within [0.0,1.0]) \
and R,G,B colors (within [0-255]).\nAll shall be numerical values.\n\
Example : A 0.2 255,255,255\n"
# define ERROR_INVALID_C_DATA "Error\nError CUB: Invalid camera data.\n\
Check coordinates, orientation vector (normalized values within \
[-1,1]) and FOV (within [0-180]).\nAll shall be numerical values.\n\
Example : C -50.0,0,20 0,0,1 70\n"
# define ERROR_INVALID_L_DATA "Error\nError CUB: Invalid light data.\n\
Check coordinates, light brightness (normalized values within \
[0.0,1.0]).\nAll shall be numerical values.\n\
Example : L -40.0,50.0,0.0 0.6\n"
# define ERROR_INVALID_SP_DATA "Error\nError CUB: Invalid sphere data.\n\
Check coordinates, diameter and R,G,B colors (within [0-255]).\n\
All shall be numerical values.\n\
Example : sp 0.0,0.0,20.6 12.6 10,0,255\n"
# define ERROR_INVALID_PL_DATA "Error\nError CUB: Invalid plane data.\n\
Check coordinates, normal vector (normalized values within \
[-1,1]) and R,G,B colors (within [0-255]).\n\
All shall be numerical values.\n\
Example : pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225\n"
# define ERROR_INVALID_CY_DATA "Error\nError CUB: Invalid cylinder data.\n\
Check coordinates, normal vector (normalized values within \
[-1,1]), cylinder diameter, cylinder height and \
R,G,B colors (within [0-255]).\n\
All shall be numerical values.\n\
Example : cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255\n"
# define COMMANDS "Quit=esc Zoom=zxcvbn(scroll) Move=asdw Misc=[0-9][keys]\n"
# define WINDOW_TITLE "Mini RT"
# define HELP "-h"
# define ON_DESTROY 17
# define KEY_PRESS 2
# define KEY_PRESS_MASK 1
# define FREE_STASH -1
# define MAX_DOUBLE	1.7976931348623157e+308 // OR DBL_MAX FROM <FLOAT.H>?
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
# define C_255  255.0f
# define C_1_160 1e-160
# define PI 3.14159265358979323846
# define CAMERA_MAX_DEPTH 10
# define VERY_LITTLE 0.001f
# define EPSILON 1e-6 // TO CHECK IF VECTOR ARE PARALLEL (IF SCALAR PRODUCT = 0)
						// A REGROUPER AVEC VERY_LITTLE ?
# define V_POINT 0
# define V_VECTOR 1
# define MOVE_STEP .05
# define ANGLE_STEP .15
# define ANGLE_MOUSE .015
# define HIT_0 0
# define HIT_1 1
# define CHAR_0 '0'
# define CHAR_1 '1'
# define SIDE_VERTICAL 0
# define SIDE_HORIZONTAL 1
# define SHADE_RATIO 0.05
# define SCREEN_RATIO 2

#endif
