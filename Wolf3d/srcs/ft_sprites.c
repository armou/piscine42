/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:53:05 by aoudin            #+#    #+#             */
/*   Updated: 2017/03/10 16:56:53 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
void			ft_sort_sprites(t_env *v)
{
	int			gap;
	int			i;
	int			j;

	i = 0;
	j = 0;
//	while (gap > 1)
}*/

void			ft_color_sprites(t_env *v, int texx, int texy)
{
	COLOR = mlx_get_pixel_clr(RABBIT, texx, texy);

}

void			ft_calc_sprites(t_env *v, int screenx, double transY)
{
	int		stripe;
	int		texx;
	int		texy;
	int		i;
	int		y;

	stripe = 0;
	i = 0;
	while (stripe++ < SPDRAWENDX)
	{
		texx = (int)((256 * (stripe - (-SPWIDTH / 2 + screenx)))) * SPTEXW;
		y = SPDRAWSTARTY;
		if (transY > 0 && stripe > 0 && stripe < WIDTH)
		{
			while (y++ < SPDRAWENDY)
			{
				i = (y) * 256 - HEIGHT * 128 + SPHEIGHT * 128;
				texy = ((i * SPTEXH) / SPHEIGHT / 256);
				ft_color_sprites(v, texx, texy);
			}
		}
	}
}

void			ft_create_sprites(t_env *v)
{
	double		transX;
	double		transY;
	double		inv;
	int			screenx;

	SPRITEPOSX = SPRITEX - POSX;
	SPRITEPOSY = SPRITEY - POSY;
	inv = 1.0 / (PLANEX * DIRY - DIRX * PLANEY);
	transX = inv * (DIRY * SPRITEX - DIRX * SPRITEY);
	transY = inv * (-PLANEY * SPRITEX + PLANEX * SPRITEY);
	screenx = (int)(((WIDTH / 2) * (1 + transX / transY)));
	SPHEIGHT = abs((int)(HEIGHT / (transY)));
	SPDRAWSTARTY = -SPHEIGHT / 2 + HEIGHT / 2;
	if (SPDRAWSTARTY < 0)
		SPDRAWSTARTY = 0;
	SPDRAWENDY = SPHEIGHT / 2 + HEIGHT / 2;
	if (SPDRAWENDY >= HEIGHT)
		SPDRAWENDY = HEIGHT - 1;
	SPWIDTH = abs((int)(HEIGHT / (transY)));
	SPDRAWSTARTX = -SPWIDTH / 2 + screenx;
	if (SPDRAWSTARTX < 0)
		SPDRAWSTARTX = 0;
	SPDRAWENDX = SPWIDTH / 2 + screenx;
	if (SPDRAWENDX >= WIDTH)
		SPDRAWENDX = WIDTH - 1;
	ft_calc_sprites(v, screenx, transY);
}
/*
	i = 0;
	for(int i = 0; i < numSprites; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y)); //sqrt not taken, unneeded
	}
	combSort(spriteOrder, spriteDistance, numSprites);

	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < numSprites; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = sprite[spriteOrder[i]].x - posX;
		double spriteY = sprite[spriteOrder[i]].y - posY;

		//transform sprite with the inverse camera matrix
		// [ PLANEX   DIRX ] -1                                       [ DIRY      -DIRX ]
		// [               ]       =  1/(PLANEX*DIRY-DIRX*PLANEY) *   [                 ]
		// [ PLANEY   DIRY ]                                          [ -PLANEY  PLANEX ]

		double invDet = 1.0 / (PLANEX * DIRY - DIRX * PLANEY); //required for correct matrix multiplication

		double transformX = invDet * (DIRY * spriteX - DIRX * spriteY);
		double transformY = invDet * (-PLANEY * spriteX + PLANEX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

		//calculate height of the sprite on screen
		int spriteHeight = abs(int(h / (transformY))); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + HEIGHT / 2;
		if(drawEndY >= h) drawEndY = h - 1;

		//calculate width of the sprite
		int spriteWidth = abs( int (h / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= w) drawEndX = w - 1;
		loop through every vertical stripe of the sprite on screen
			for(int stripe = drawStartX; stripe < drawEndX; stripe++)
			{
				int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
				//the conditions in the if are:
				//1) it's in front of camera plane so you don't see things behind you
				//2) it's on the screen (left)
				//3) it's on the screen (right)
				//4) ZBuffer, with perpendicular distance
				if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
					for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
					{
						int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
						int texY = ((d * texHeight) / spriteHeight) / 256;
						Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
						if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
					}
			}
	*/
