#include "unknow_project.h"

void draw_pixel_opengl(t_window *p_win, t_vector2 *p_coord, t_color *p_color)
{
	GLfloat vertex_buffer_data[] = {
		p_coord->x, p_coord->y, 0.0f
	};

	GLfloat color_buffer_data[] = {
		p_color->r,  p_color->g,  p_color->b, p_color->a
	};

	// bind VAO
	glBindVertexArray(p_win->vertex_array);

	// bind vertex_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// donne a vertex_buffer vertex_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	// bind color_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	// donne a color_buffer color_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);

	// indique le shader a utiliser
	glUseProgram(p_win->program_color);

	// indique la location du shader utiliser
	glEnableVertexAttribArray(0);
	// quelle est le buffer a utiliser
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// comment utiliser le buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// dessine un point
	glDrawArrays( GL_POINTS, 0, 1);
}

void draw_point_opengl(t_window *p_win, t_point *p_point, int size)
{
	glPointSize(size);

	GLfloat vertex_buffer_data[] = {
		p_point->x, p_point->y, 0.0f
	};

	GLfloat color_buffer_data[] = {
		p_point->color.r,  p_point->color.g,  p_point->color.b, p_point->color.a
	};

	// bind VAO
	glBindVertexArray(p_win->vertex_array);

	// bind vertex_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// donne a vertex_buffer vertex_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	// bind color_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	// donne a color_buffer color_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);

	// indique le shader a utiliser
	glUseProgram(p_win->program_color);

	// indique la location du shader utiliser
	glEnableVertexAttribArray(0);
	// quelle est le buffer a utiliser
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// comment utiliser le buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// dessine un point
	glDrawArrays( GL_POINTS, 0, 1);
	glPointSize(1);
}

void draw_line_opengl(t_window *p_win, t_point *p_a, t_point *p_b)
{
	GLfloat vertex_buffer_data[] = {
		p_a->x, p_a->y, 0.0f,
		p_b->x, p_b->y, 0.0f,
	};

	GLfloat color_buffer_data[] = {
		p_a->color.r,  p_a->color.g,  p_a->color.b, p_a->color.a,
		p_b->color.r,  p_b->color.g,  p_b->color.b, p_b->color.a,
	};

	// bind VAO
	glBindVertexArray(p_win->vertex_array);

	// bind vertex_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// donne a vertex_buffer vertex_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	// bind color_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	// donne a color_buffer color_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);

	// indique le shader a utiliser
	glUseProgram(p_win->program_color);

	// indique la location du shader utiliser
	glEnableVertexAttribArray(0);
	// quelle est le buffer a utiliser
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// comment utiliser le buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// dessine un triangle
	glDrawArrays(GL_LINES, 0, 2);
}

void draw_triangle_opengl(t_window *p_win, t_point *p_a, t_point *p_b, t_point *p_c)
{
	GLfloat vertex_buffer_data[] = {
		p_a->x, p_a->y, 0.0f,
		p_b->x, p_b->y, 0.0f,
		p_c->x, p_c->y, 0.0f,
	};

	GLfloat color_buffer_data[] = {
		p_a->color.r,  p_a->color.g,  p_a->color.b, p_a->color.a,
		p_b->color.r,  p_b->color.g,  p_b->color.b, p_b->color.a,
		p_c->color.r,  p_c->color.g,  p_c->color.b, p_c->color.a,
	};

	// bind VAO
	glBindVertexArray(p_win->vertex_array);

	// bind vertex_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// donne a vertex_buffer vertex_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	// bind color_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	// donne a color_buffer color_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);

	// indique le shader a utiliser
	glUseProgram(p_win->program_color);

	// indique la location du shader utiliser
	glEnableVertexAttribArray(0);
	// quelle est le buffer a utiliser
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// comment utiliser le buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// dessine un triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void draw_buffer_opengl(t_window *p_win)
{
	if (p_win->vertex_buffer_data.size == 0 || p_win->color_buffer_data.size == 0)
		return ;
	glBindVertexArray(p_win->vertex_array);

	// bind vertex_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// donne a vertex_buffer vertex_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * p_win->vertex_buffer_data.size * 3, t_vector3_list_obtain(&(p_win->vertex_buffer_data), 0), GL_STATIC_DRAW);

	// bind color_buffer
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	// donne a color_buffer color_buffer_data
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * p_win->color_buffer_data.size * 4, t_color_list_obtain(&(p_win->color_buffer_data), 0), GL_STATIC_DRAW);

	// indique le shader a utiliser
	glUseProgram(p_win->program_color);

	// indique la location du shader utiliser
	glEnableVertexAttribArray(0);
	// quelle est le buffer a utiliser
	glBindBuffer(GL_ARRAY_BUFFER, p_win->vertex_buffer);
	// comment utiliser le buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, p_win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// dessine un point
	glDrawArrays( GL_POINTS, 0, p_win->vertex_buffer_data.size);
}
