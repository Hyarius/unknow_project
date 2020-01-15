#include "unknow_project.h"

void	draw_triangle_color_opengl(t_window *win, t_triangle *triangle, t_color *color)
{
	GLfloat vertex_buffer_data[9] = {
		triangle->a.x, triangle->a.y, 0.0f,
		triangle->b.x, triangle->b.y, 0.0f,
		triangle->c.x, triangle->c.y, 0.0f,
	};
	GLfloat color_buffer_data[12] = {
		color->r, color->g, color->b, color->a,
		color->r, color->g, color->b, color->a,
		color->r, color->g, color->b, color->a,
	};

	glBindVertexArray(win->vertex_array);
	glBindBuffer(GL_ARRAY_BUFFER, win->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data),
					vertex_buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data,
					GL_STATIC_DRAW);
	glUseProgram(win->program_color);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, win->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void	draw_buffer_opengl(t_window *win, t_color *color_data)
{
	int	screen_len;

	screen_len = win->size_x * win->size_y;
	glBindVertexArray(win->vertex_array);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_fixed_buffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 4 * screen_len,
									color_data);
	glUseProgram(win->program_color);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, win->vertex_fixed_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_fixed_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glDrawArrays(GL_POINTS, 0, screen_len);
}
