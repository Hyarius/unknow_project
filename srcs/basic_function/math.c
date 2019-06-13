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

float			edge_vector3(t_vector3 a, t_vector3 b, t_vector3 c)
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

void			clamp_float_value(float min, float *value, float max)
{
	if (*value < min)
		*value = min;
	if (*value > max)
		*value = max;
}

void			clamp_int_value(int min, int *value, int max)
{
	if (*value < min)
		*value = min;
	if (*value > max)
		*value = max;
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