/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:11:48 by aoudin            #+#    #+#             */
/*   Updated: 2017/03/31 19:26:03 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			ft_launch_raycast(t_env *v)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_raycast_wall(v, x);
	}
}

void			ft_init_var(t_env *v)
{
	POSX = 15;
	POSY = 18;
	PLANEX = 0;
	PLANEY = 0.66;
	DIRX = -1;
	DIRY = 0;
	MS = 0.4;
	ROTSPEED = 0.1;
}

int				ft_wolf(t_env *v)
{
	ft_launch_raycast(v);
	//	dprintf(1, "tab[11] = %s", TAB[11]);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

t_env				*ft_create_struct(int fd)
{
	t_env	*v;

	if (!(v = (t_env*)ft_memalloc(sizeof(t_env))))
		exit(0);
	if (!(v->img = (t_img*)ft_memalloc(sizeof(t_img))))
		exit(0);
	if (!(v->wtex = (t_tex*)ft_memalloc(sizeof(t_tex))))
		exit(0);
	if (!(v->ftex = (t_tex_f*)ft_memalloc(sizeof(t_tex_f))))
		exit(0);
	if (!(v->wolf = (t_w*)ft_memalloc(sizeof(t_w))))
		exit(0);
	if (!(v->sp = (t_sprite*)ft_memalloc(sizeof(t_sprite))))
		exit(0);
	ft_ptr_ft(v);
	ft_parse_wolf(v, fd);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800, 500, WIDTH, HEIGHT, "Wolf3d");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	ft_init_tex(v);
	return (v);
}

int				main(int ac, char **av)
{
	t_env	*v;
	int		fd;

	if (ac != 2)
		ft_putendl("Usage : ./Wolf3d <map>");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(v = ft_create_struct(fd)))
			exit(0);
	mlx_loop_hook(MLX, ft_wolf, v);
	mlx_hook(WIN, 2, 0, ft_keypress, v);
//	mlx_hook(WIN, KeyPress, KeyPressMask, ft_keypress, v);
	//		mlx_hook(WIN, MotionNotify, ButtonMotionMask, wolf);
	//		mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_button, wolf);
//	mlx_hook(WIN, DestroyNotify, Button1MotionMask, ft_exitprog, v);
	mlx_loop(MLX);
	}
	return (0);
}
/*
   double posX = 22, posY = 12;  //x and y start position
   double dirX = -1, dirY = 0; //initial direction vector
   double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

   double time = 0; //time of current frame
   double oldTime = 0; //time of previous frame

   screen(512, 384, 0, "Raycaster");
   while(!done())
   {
   for(int x = 0; x < w; x++)
   {
//calculate ray position and direction
double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
double rayPosX = posX;
double rayPosY = posY;
double rayDirX = dirX + planeX * cameraX;
double rayDirY = dirY + planeY * cameraX;
//                                    //which box of the map we're in
int mapX = int(rayPosX);
int mapY = int(rayPosY);
//length of ray from current position to next x or y-side
double sideDistX;
double sideDistY;
//length of ray from one x or y-side to next x or y-side
double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
double perpWallDist;
//what direction to step in x or y-direction (either +1 or -1)
int stepX;
int stepY;
int hit = 0; //was there a wall hit?
int side; //was a NS or a EW wall hit?
//calculate step and initial sideDist
if (rayDirX < 0)
{
stepX = -1;
sideDistX = (rayPosX - mapX) * deltaDistX;
}
else
{
stepX = 1;
sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
}
if (rayDirY < 0)
{
stepY = -1;
sideDistY = (rayPosY - mapY) * deltaDistY;
}
else
{
stepY = 1;
sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
}
//perform DDA
while (hit == 0)
{
//jump to next map square, OR in x-direction, OR in y-direction
if (sideDistX < sideDistY)
{
sideDistX += deltaDistX;
mapX += stepX;
side = 0;
}
else
{
sideDistY += deltaDistY;
mapY += stepY;
side = 1;
}
//Check if ray has hit a wall
if (worldMap[mapX][mapY] > 0) hit = 1;
}
//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
//Calculate height of line to draw on screen
int lineHeight = (int)(h / perpWallDist);
//calculate lowest and highest pixel to fill in current stripe
int drawStart = -lineHeight / 2 + h / 2;
if(drawStart < 0)drawStart = 0;
int drawEnd = lineHeight / 2 + h / 2;
if(drawEnd >= h)drawEnd = h - 1;
//choose wall color
ColorRGB color;
switch(worldMap[mapX][mapY])
{
	case 1:  color = RGB_Red;  break; //red
	case 2:  color = RGB_Green;  break; //green
	case 3:  color = RGB_Blue;   break; //blue
	case 4:  color = RGB_White;  break; //white
	default: color = RGB_Yellow; break; //yellow
}
//give x and y sides different brightness
if (side == 1) {color = color / 2;}

//draw the pixels of the stripe as a vertical line
verLine(x, drawStart, drawEnd, color);
}
//timing for input and FPS counter
oldTime = time;
time = getTicks();
double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
print(1.0 / frameTime); //FPS counter
redraw();
cls();
//speed modifiers
double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
readKeys();
//move forward if no wall in front of you
if (keyDown(SDLK_UP))
{
	if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
}
//move backwards if no wall behind you
if (keyDown(SDLK_DOWN))
{
	if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
}
//rotate to the right
if (keyDown(SDLK_RIGHT))
{
	//both camera direction and camera plane must be rotated
	double oldDirX = dirX;
	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	double oldPlaneX = planeX;
	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
}
//rotate to the left
if (keyDown(SDLK_LEFT))
{
	//both camera direction and camera plane must be rotated
	double oldDirX = dirX;
	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	double oldPlaneX = planeX;
	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
}
}
return (0);
}*/
