#include "unknow_project.h"

t_vector3		cross_t_vector3(t_vector3 a, t_vector3 b) //Produit vectoriel / cross product
{
	t_vector3	result;

	result = create_t_vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
								a.x * b.y - a.y * b.x);
	return (result);
}

t_vector3		normalize_t_vector3(t_vector3 v) // ramene la longueur du vecteur a 1
{
	float		length_of_v;

	length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (create_t_vector3(v.x / length_of_v, v.y
							/ length_of_v, v.z / length_of_v));
}

float			dot_t_vector3(t_vector3 a, t_vector3 b) //Produit scalaire / dot product
{
	float		result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

float			edge_t_vector3(t_vector3 a, t_vector3 b, t_vector3 c)
{
	float		result;

	result = ((c.x - a.x) * (b.y - a.y)) - ((c.y - a.y) * (b.x - a.x));
	return (result);
}

t_vector3		intersect_plane_by_line(t_vector3 p_normal, t_vector3 p_center, t_vector3 start, t_vector3 end)
{
	t_vector3	intersection;
	t_vector3	basic_line;
	t_vector3	normalized_plane;
	float		normal_delta;
	float		dist_start;
	float		dist_end;
	float		t;

	normalized_plane = normalize_t_vector3(p_normal);
	normal_delta = dot_t_vector3(normalized_plane, p_center);
	dist_start = dot_t_vector3(start, normalized_plane);
	dist_end = dot_t_vector3(end, normalized_plane);
	t = (normal_delta - dist_start) / (dist_end - dist_start);
	basic_line = substract_vector3_to_vector3(end, start);
	intersection = mult_vector3_by_float(basic_line, t);
	return (add_vector3_to_vector3(start, intersection));
}

int				is_point_on_line(t_vector3 a, t_vector3 b, t_vector3 c)
{
	float dist_tot;
	float dist_part_one;
	float dist_part_two;

	dist_tot = calc_dist_vector3_to_vector3(a, b);
	dist_part_one = calc_dist_vector3_to_vector3(a, c);
	dist_part_two = calc_dist_vector3_to_vector3(c, b);

	if (dist_part_one == 0)
		return (-1);
	if (dist_part_two == 0)
		return (-2);
	if (dist_tot == dist_part_one + dist_part_two)
		return (1);
	return (0);
}

int				intersect_triangle_by_segment(t_triangle p_triangle, t_vector3 p_normal, t_vector3 point_one, t_vector3 point_two)
{
	int		point_type;
	float dist_one;
	float dist_two;
	t_vector3 intersection;
	t_vector3 w;
	t_vector3 u;
	t_vector3 v;
	float uv;
	float wv;
	float vv;
	float wu;
	float uu;
	float s;
	float t;

	if (dot_t_vector3(p_normal, normalize_t_vector3(substract_vector3_to_vector3(point_two, point_one))) == 0)
		return (0);

	intersection = intersect_plane_by_line(p_normal, p_triangle.a, point_one, point_two);

	if (is_point_on_line(point_one, point_two, intersection) != 1)
		return (0);

	w = substract_vector3_to_vector3(intersection, p_triangle.a);
	u = substract_vector3_to_vector3(p_triangle.b, p_triangle.a);
	v = substract_vector3_to_vector3(p_triangle.c, p_triangle.a);
	uv = dot_t_vector3(u, v);
	wv = dot_t_vector3(w, v);
	vv = dot_t_vector3(v, v);
	wu = dot_t_vector3(w, u);
	uu = dot_t_vector3(u, u);
	s = ((uv * wv) - (vv * wu)) / ((uv * uv) - (uu * vv));
	t = ((uv * wu) - (uu * wv)) / ((uv * uv) - (uu * vv));

	if (s <= 0.0 || s >= 1.0 || t <= 0.0 || t >= 1.0 || s + t <= 0.0 || s + t >= 1.0)
		return (0);
	return (1);
}


float			calc_distance_to_plane(t_vector3 p_normal, t_vector3 p_center, t_vector3 p_point)
{
	t_vector3	normalized_plane;
	float		result;

	normalized_plane = normalize_t_vector3(p_normal);
	result = p_point.x * normalized_plane.x
			+ p_point.y * normalized_plane.y
			+ p_point.z * normalized_plane.z
			- dot_t_vector3(normalized_plane, p_center);
	return (result);
}

float			clamp_float_value(float min, float value, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int			clamp_int_value(int min, int value, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_vector3		interpolate_vector3_over_line(float ratio_x, float ratio_y, t_vector3 ua, t_vector3 ub)
{
	t_vector3	result;

	result.x = ((ub.x - ua.x) * ratio_x) + ua.x;
	result.y = ((ub.y - ua.y) * ratio_y) + ua.y;
	result.z = 0;
	return (result);
}

float			interpolate_ratio(float a, float b, float c)
{
	if (b - a == 0)
		return (0);
	return ((c - a) / (b - a));
}

float			calc_dist_vector3_to_vector3(t_vector3 a, t_vector3 b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)));
}

float			ft_abs_float(float src)
{
	if (src < 0)
		return (-src);
	return (src);
}
