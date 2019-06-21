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

	if (dist_tot == dist_part_one + dist_part_two)
		return (1);
	return (0);
}

int				intersect_triangle_by_segment(t_triangle p_triangle, t_vector3 p_normal, t_vector3 point_one, t_vector3 point_two)
{
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

	if (is_point_on_line(point_one, point_two, intersection) == 0)
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


	if (s < 0.0 || s > 1.0 - 0.0 || t < 0.0 || t > 1.0 - 0.0 || s + t < 0.0 || s + t > 1.0 - 0.0)
		return (0);
	if ((s == 0.0 && t == 1.0 - 0.0) || (t == 0.0 && s == 1.0 - 0.0) || s + t == 0.0 || s + t == 1.0 - 0.0)
	{
		printf("----\n");
		print_t_triangle(p_triangle, "Triangle test");
		print_t_vector3(point_one, "One : ");
		print_t_vector3(point_two, "Two : ");
		printf("Result -> s = %f / t = %f\n", s, t);
		printf("----\n");
		return (-1);
	}
	return (1);
}

int				intersect_segment_by_segment(t_vector3 a, t_vector3 b, t_vector3 c, t_vector3 d)
{
	t_vector3 u;
	t_vector3 v;
	t_vector3 w;

	float uv;
	float wv;
	float vv;
	float wu;
	float uu;

	float denominator;
	float s;
	float t;

	u = substract_vector3_to_vector3(b, a);
	v = substract_vector3_to_vector3(d, c);
	w = substract_vector3_to_vector3(a, c);

	uu = dot_t_vector3(u, u);
	uv = dot_t_vector3(u, v);
	vv = dot_t_vector3(v, v);
	wu = dot_t_vector3(w, u);
	wv = dot_t_vector3(w, v);

	denominator = (uu * vv) - (uv * uv);

    float    sc, sN, sD = denominator;       // sc = sN / sD, default sD = D >= 0
    float    tc, tN, tD = denominator;       // tc = tN / tD, default tD = D >= 0

    // compute the line parameters of the two closest points
    if (denominator < EPSILON) { // the lines are almost parallel
        sN = 0.0;         // force using point P0 on segment S1
        sD = 1.0;         // to prevent possible division by 0.0 later
        tN = wv;
        tD = vv;
    }
    else {                 // get the closest points on the infinite lines
        sN = (uv*wv - vv*wu);
        tN = (uu*wv - uv*wu);
        if (sN < 0.0) {        // sc < 0 => the s=0 edge is visible
            sN = 0.0;
            tN = wv;
            tD = vv;
        }
        else if (sN > sD) {  // sc > 1  => the s=1 edge is visible
            sN = sD;
            tN = wv + uv;
            tD = vv;
        }
    }

    if (tN < 0.0) {            // tc < 0 => the t=0 edge is visible
        tN = 0.0;
        // recompute sc for this edge
        if (-wu < 0.0)
            sN = 0.0;
        else if (-wu > uu)
            sN = sD;
        else {
            sN = -wu;
            sD = uu;
        }
    }
    else if (tN > tD) {      // tc > 1  => the t=1 edge is visible
        tN = tD;
        // recompute sc for this edge
        if ((-wu + uv) < 0.0)
            sN = 0;
        else if ((-wu + uv) > uu)
            sN = sD;
        else {
            sN = (-wu +  uv);
            sD = uu;
        }
    }
    // finally do the division to get sc and tc
    sc = (fabsf(sN) < EPSILON ? 0.0 : sN / sD);
    tc = (fabsf(tN) < EPSILON ? 0.0 : tN / tD);

    // get the difference of the two closest points
    t_vector3   result = add_vector3_to_vector3(w, substract_vector3_to_vector3(mult_vector3_by_float(u,sc), mult_vector3_by_float(v, tc)));  // =  S1(sc) - S2(tc)

	if (result.x == 0 && result.y == 0 && result.z == 0)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
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
