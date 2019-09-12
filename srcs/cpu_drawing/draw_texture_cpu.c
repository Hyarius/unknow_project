#include "unknow_project.h"

void	draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle *p_triangle, t_uv *p_uv)
{
	t_triangle tri;
	t_triangle c;
	t_triangle st;
	t_rasterizer	ab;
	t_rasterizer	ac;
	t_rasterizer	bc;

	tri = create_t_triangle(create_t_vector3(p_triangle->a.x, p_triangle->a.y, p_triangle->a.z),
							create_t_vector3(p_triangle->b.x, p_triangle->b.y, p_triangle->b.z),
							create_t_vector3(p_triangle->c.x, p_triangle->c.y, p_triangle->c.z));

	c = create_t_triangle(create_t_vector3(1, 0, 0),
							create_t_vector3(0, 1, 0),
							create_t_vector3(0, 0, 1));

	st = create_t_triangle(create_t_vector3(p_uv->uv.a.x, p_uv->uv.a.y, p_uv->uv.a.z),
							create_t_vector3(p_uv->uv.b.x, p_uv->uv.b.y, p_uv->uv.b.z),
							create_t_vector3(p_uv->uv.c.x, p_uv->uv.c.y, p_uv->uv.c.z));

	tri.a.x /= tri.a.z;
	tri.a.y /= tri.a.z;
	tri.b.x /= tri.b.z;
	tri.b.y /= tri.b.z;
	tri.c.x /= tri.c.z;
	tri.c.y /= tri.c.z;

	tri.a = convert_opengl_to_vector3(p_view_port, tri.a);
	tri.b = convert_opengl_to_vector3(p_view_port, tri.b);
	tri.c = convert_opengl_to_vector3(p_view_port, tri.c);

	//perspective correcte
	c.a.x /= tri.a.z;
	c.a.y /= tri.a.z;
	c.a.z /= tri.a.z;
	c.b.x /= tri.b.z;
	c.b.y /= tri.b.z;
	c.b.z /= tri.b.z;
	c.c.x /= tri.c.z;
	c.c.y /= tri.c.z;
	c.c.z /= tri.c.z;

	st.a.x /= tri.a.z;
	st.a.y /= tri.a.z;
	st.b.x /= tri.b.z;
	st.b.y /= tri.b.z;
	st.c.x /= tri.c.z;
	st.c.y /= tri.c.z;

	tri.a.z = 1 / tri.a.z;
	tri.b.z = 1 / tri.b.z;
	tri.c.z = 1 / tri.c.z;

	ab = create_t_rasterizer(tri.a, tri.b, tri.c);
	ac = create_t_rasterizer(tri.a, tri.c, tri.b);
	bc = create_t_rasterizer(tri.b, tri.c, tri.a);

	float area = edge_t_vector3(tri.a, tri.b, tri.c);
	int i;
	int j = 0;
	t_vector3 p;
	t_vector3 w;
	t_color rgb;
	float z;
	float s;
	float t;
	while (j < p_view_port->window->size_y)
	{
		i = 0;
		while (i < p_view_port->window->size_x)
		{
			//triangle du haut
			p = create_t_vector3(i + EPSILON, j + EPSILON, 0);
			w = create_t_vector3(calc_rasterizer(&bc, i, j),
								calc_rasterizer(&ac, i, j),
								calc_rasterizer(&ab, i, j));
			if (w.x >= 0.0 && w.y >= 0.0 && w.z >= 0.0)
			{
				w.x /= area;
				w.y /= area;
				w.z /= area;
				rgb = create_t_color((w.x * c.a.x + w.y * c.b.x + w.z * c.c.x),
									(w.x * c.a.y + w.y * c.b.y + w.z * c.c.y),
									(w.x * c.a.z + w.y * c.b.z + w.z * c.c.z),
									1.0);
				z = 1 / (w.x * tri.a.z + w.y * tri.b.z + w.z * tri.c.z);
				rgb.r *= z;
				rgb.g *= z;
				rgb.b *= z;
				s = (w.x * st.a.x + w.y * st.b.x + w.z * st.c.x) * z * p_uv->texture->surface->w;
				t = (w.x * st.a.y + w.y * st.b.y + w.z * st.c.y) * z * p_uv->texture->surface->h;
				rgb = get_pixel_color(p_uv->texture, s, t);
				if (z <= p_view_port->depth_buffer[i + (j * p_view_port->window->size_x)])
				{
					p_view_port->depth_buffer[i + (j * p_view_port->window->size_x)] = z;
					draw_pixel(p_view_port->window, (int)(i + p_view_port->pos.x), (int)(j + p_view_port->pos.y), rgb);
				}
			}
			i++;
		}
		j++;
	}
}

void	*thread_draw_texture_cpu(void *void_list)
{
	t_void_list 	*data;
	int				i;
	int				start;
	int				len;
	t_view_port 	*p_view_port;
	t_triangle_list	*triangle_list;
	t_uv_list	*uv_list;
	t_triangle		*triangle;
	t_uv		*uv;

	data = (t_void_list *)(void_list);
	start = (int)(t_void_list_at(data, 0));
	len = (int)(t_void_list_at(data, 1));
	p_view_port = (t_view_port *)(t_void_list_at(data, 2));
	triangle_list = (t_triangle_list *)(t_void_list_at(data, 3));
	uv_list = (t_uv_list *)(t_void_list_at(data, 4));
	i = 0;
	while (i < len && (start + i) < triangle_list->size)
	{
		triangle = t_triangle_list_get(triangle_list, start + i);
		uv = t_uv_list_get(uv_list, start + i);
		draw_triangle_texture_cpu(p_view_port, triangle, uv);
		i++;
	}
	pthread_exit(NULL);
}

void	multithreading_draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle_list *p_triangle_list, t_uv_list *p_uv_list)
{
	int start;
	int	modulo;
	int len;
	int i;
	int nb_thread;


	start = 0;
	modulo = p_triangle_list->size % NB_THREAD_MAX;
	i = 0;
	nb_thread = p_triangle_list->size / (NB_TRIANGLE_MAX);
	if (nb_thread == 0)
		nb_thread++;
	if (nb_thread >= NB_THREAD_MAX)
		nb_thread = NB_THREAD_MAX;
	while (i < nb_thread)
	{
		len = p_triangle_list->size / nb_thread;
		if (i < modulo)
			len++;
		clean_t_void_list(&(p_view_port->window->data[i]));
		t_void_list_add_back(&p_view_port->window->data[i], 5, (long)start, (long)len, p_view_port, p_triangle_list, p_uv_list);
		pthread_create(&(p_view_port->window->threads[i]), NULL, thread_draw_texture_cpu, &(p_view_port->window->data[i]));
		i++;
		start += len;
	}
	i = 0;
	while (i < nb_thread)
	{
		pthread_join(p_view_port->window->threads[i], NULL); // join et free des threads
		i++;
	}
}

void    draw_rectangle_texture_cpu(t_view_port *p_view_port, t_rectangle p_rec, t_texture *p_texture)
{
	t_triangle_list	*tri_list;
	t_triangle		*tri;
	t_uv_list		*uv_list;
	t_uv			*uv;

	uv_list = initialize_t_uv_list();
	tri_list = initialize_t_triangle_list();
	tri = initialize_t_triangle(create_t_vector3(p_rec.pos.x, p_rec.pos.y, 1.0),
							create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
							create_t_vector3(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, *tri);
	uv = initialize_t_uv(create_t_triangle(create_t_vector3(0, 1, 0), create_t_vector3(1, 1, 0), create_t_vector3(0, 0, 0)), p_texture);
	t_uv_list_push_back(uv_list, *uv);

	tri = initialize_t_triangle(create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y + p_rec.size.y, 1.0),
							create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
							create_t_vector3(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, *tri);
	uv = initialize_t_uv(create_t_triangle(create_t_vector3(1, 0, 0), create_t_vector3(1, 1, 0), create_t_vector3(0, 0, 0)), p_texture);
	t_uv_list_push_back(uv_list, *uv);
	multithreading_draw_triangle_texture_cpu(p_view_port, tri_list,	uv_list);
}
