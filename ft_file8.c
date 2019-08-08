/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:48:03 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/23 17:04:00 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init(t_params *params)
{
	params->varx = 0;
	params->vary = 0;
	params->varz = 0;
	params->trans.x = 0;
	params->trans.y = 0;
	params->trans.z = 0;
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	params->img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	params->data = (unsigned char *)mlx_get_data_addr(params->img_ptr,
			&params->bpp, &params->s_l, &params->endian);
}

int		red_cross(t_params *params)
{
	(void)params;
	exit(0);
	return (0);
}

void	tans_event(int key, t_params *params)
{
	if (key == 125)
		params->trans.y += 6;
	if (key == 126)
		params->trans.y -= 6;
	if (key == 124)
		params->trans.x += 6;
	if (key == 123)
		params->trans.x -= 6;
	if (key == 12)
		params->trans.z += 6;
	if (key == 0)
		params->trans.z -= 6;
}

void	rot_cam_event(int key, t_params *params)
{
	if (key == 91)
		params->varx = 3;
	if (key == 84)
		params->varx = -3;
	if (key == 88)
		params->vary = 3;
	if (key == 86)
		params->vary = -3;
	if (key == 92)
		params->varz = 3;
	if (key == 89)
		params->varz = -3;
}

int		key_press(int key, t_params *params)
{
	params->varx = 0;
	params->vary = 0;
	params->varz = 0;
	tans_event(key, params);
	rot_cam_event(key, params);
	if (key == 53)
	{
		ft_o_free(params);
		free(params->sce);
		mlx_destroy_image(params->mlx_ptr, params->img_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	mlx_destroy_image(params->mlx_ptr, params->img_ptr);
	params->img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	params->data = (unsigned char *)mlx_get_data_addr(params->img_ptr,
			&params->bpp, &params->s_l, &params->endian);
	ft_calcule(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr,
			params->img_ptr, 0, 0);
	return (0);
}
