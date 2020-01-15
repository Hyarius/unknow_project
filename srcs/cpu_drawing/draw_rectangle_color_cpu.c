/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle_color_cpu.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:44 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/15 15:59:08 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	draw_rectangle_color_cpu(t_view_port *p_view_port, t_rectangle p_rec,
															t_color *p_color)
{
	static t_color_list		*color_list = NULL;
	static t_triangle_list	*tri_list = NULL;
	t_triangle				tri;

	if (tri_list == NULL && color_list == NULL)
	{
		color_list = initialize_t_color_list();
		tri_list = initialize_t_triangle_list();
	}
	tri = create_t_triangle(create_t_vector4(p_rec.pos.x, p_rec.pos.y, 1.0),
				create_t_vector4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
				create_t_vector4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, tri);
	t_color_list_push_back(color_list, *p_color);
	tri = create_t_triangle(create_t_vector4(p_rec.pos.x + p_rec.size.x,
											p_rec.pos.y + p_rec.size.y, 1.0),
				create_t_vector4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
				create_t_vector4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, tri);
	t_color_list_push_back(color_list, *p_color);
	multithreading_draw_triangle_color_cpu(p_view_port, tri_list, color_list);
	clean_t_triangle_list(tri_list);
	clean_t_color_list(color_list);
}

void	draw_hud_rect(t_view_port *p_view_port,
											t_rectangle p_rec, t_color *p_color)
{
	t_triangle	tri;

	tri = create_t_triangle(create_t_vector4(p_rec.pos.x, p_rec.pos.y, 0.0),
				create_t_vector4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 0.0),
				create_t_vector4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 0.0));
	draw_triangle_color_cpu(p_view_port, &tri, p_color);
	tri = create_t_triangle(create_t_vector4(p_rec.pos.x + p_rec.size.x,
											p_rec.pos.y + p_rec.size.y, 0.0),
				create_t_vector4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 0.0),
				create_t_vector4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 0.0));
	draw_triangle_color_cpu(p_view_port, &tri, p_color);
}
