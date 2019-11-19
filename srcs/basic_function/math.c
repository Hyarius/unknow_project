#include "unknow_project.h"

static int              ft_size(long nb)
{
        int             size;

        size = 0;
        if (nb <= 0)
        {
                nb *= -1;
                size++;
        }
        while (nb > 0)
        {
                nb /= 10;
                size++;
        }
        return (size);
}

char                    *ft_itoa(int n)
{
        char    *array;
        int             size;
        long    nb;

        nb = n;
        size = ft_size(nb);
        if (!(array = (char*)malloc(sizeof(char) * size + 1)))
                return (NULL);
        array[size--] = '\0';
        if (nb == 0)
                array[0] = '0';
        if (nb < 0)
        {
                array[0] = '-';
                nb *= -1;
        }
        while (nb > 0)
        {
                array[size] = (nb % 10) + '0';
                nb /= 10;
                size--;
        }
        return (array);
}

t_vector4		cross_t_vector4(t_vector4 a, t_vector4 b) //Produit vectoriel / cross product
{
	t_vector4	result;
	result = create_t_vector4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
								a.x * b.y - a.y * b.x);
	return (result);
}

t_vector4		normalize_t_vector4(t_vector4 v) // ramene la longueur du vecteur a 1
{
	float		length_of_v;

	length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (create_t_vector4(v.x / length_of_v, v.y
							/ length_of_v, v.z / length_of_v));
}

float			dot_t_vector4(t_vector4 a, t_vector4 b) //Produit scalaire / dot product
{
	float		result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

float			edge_t_vector4(t_vector4 a, t_vector4 b, t_vector4 c)
{
	float		result;

	result = (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
	return (result);
}

t_vector4		intersect_plane_by_line(t_vector4 p_normal, t_vector4 p_center, t_vector4 start, t_vector4 end)
{
	t_vector4	intersection;
	t_vector4	basic_line;
	t_vector4	normalized_plane;
	float		normal_delta;
	float		dist_start;
	float		dist_end;
	float		t;

	normalized_plane = normalize_t_vector4(p_normal);
	normal_delta = dot_t_vector4(normalized_plane, p_center);
	dist_start = dot_t_vector4(start, normalized_plane);
	dist_end = dot_t_vector4(end, normalized_plane);
	t = (normal_delta - dist_start) / (dist_end - dist_start);
	basic_line = substract_vector4_to_vector4(end, start);
	intersection = mult_vector4_by_float(basic_line, t);
	return (add_vector4_to_vector4(start, intersection));
}

int				is_point_on_line(t_vector4 a, t_vector4 b, t_vector4 c)
{
	float dist_tot;
	float dist_part_one;
	float dist_part_two;

	dist_tot = calc_dist_vector4_to_vector4(a, b);
	dist_part_one = calc_dist_vector4_to_vector4(a, c);
	dist_part_two = calc_dist_vector4_to_vector4(c, b);

	if (dist_tot == dist_part_one + dist_part_two)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int				is_triangle_parallele(t_triangle p_a, t_triangle p_b)
{
	t_vector4	normal_a;
	t_vector4 	normal_b;

	normal_a = cross_t_vector4(substract_vector4_to_vector4(p_a.b, p_a.a), substract_vector4_to_vector4(p_a.c, p_a.a));
	normal_b = cross_t_vector4(substract_vector4_to_vector4(p_b.b, p_b.a), substract_vector4_to_vector4(p_b.c, p_b.a));
	float dot = dot_t_vector4(normal_a, normal_b);

	if (dot == 1 || dot == -1)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int				intersect_triangle_by_segment(t_triangle p_triangle, t_vector4 p_normal, t_line line, t_vector4 *intersection)
{
	if (dot_t_vector4(p_normal, normalize_t_vector4(substract_vector4_to_vector4(line.b, line.a))) == 0)
		return (BOOL_ERROR);
	*intersection = intersect_plane_by_line(p_normal, p_triangle.a, line.a, line.b);
	if (is_point_on_line(line.a, line.b, *intersection) == BOOL_FALSE)
		return (BOOL_FALSE);
	if (is_point_on_triangle(p_triangle, *intersection) == BOOL_FALSE)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}

int				same_side(t_vector4 p1, t_vector4 p2, t_vector4 a, t_vector4 b)
{
	t_vector4	cp1;
	t_vector4	cp2;
	t_vector4	b_a;

	b_a = substract_vector4_to_vector4(b, a);
	cp1 = cross_t_vector4(b_a, substract_vector4_to_vector4(p1, a));
	cp2 = cross_t_vector4(b_a, substract_vector4_to_vector4(p2, a));
	if (dot_t_vector4(cp1, cp2) >= 0)
		return (BOOL_TRUE);
	else
		return (BOOL_FALSE);
}

int				is_point_on_triangle(t_triangle a, t_vector4 point)
{
	if (same_side(point, a.a, a.b, a.c) == BOOL_TRUE
		&& same_side(point, a.b, a.c, a.a) == BOOL_TRUE
		&& same_side(point, a.c, a.a, a.b) == BOOL_TRUE)
		return (BOOL_TRUE);
	else
		return (BOOL_FALSE);
}

// int				is_point_on_triangle(t_triangle a, t_vector4 point)
// {
// 	t_vector4 normale;
// 	t_vector4 w;
// 	t_vector4 u;
// 	t_vector4 v;
// 	float uv;
// 	float wv;
// 	float vv;
// 	float wu;
// 	float uu;
// 	float s;
// 	float t;

// 	normale = cross_t_vector4(substract_vector4_to_vector4(a.b, a.a), substract_vector4_to_vector4(a.c, a.a));
// 	// A		: 9.9995 / 9.9995 / 5.0000
// 	// B		: 9.9995 / 5.0000 / 5.0000
// 	// C		: 5.0000 / 9.9995 / 5.0000
// 	// Normale : -0.0000 / -0.0000 / -24.9950

// 	if (calc_distance_to_plane(normale, a.a, point) != 0)
// 		return (BOOL_FALSE);

// 	//point = 5 / 15 / 5

// 	w = substract_vector4_to_vector4(point, a.a);
// 	u = substract_vector4_to_vector4(a.b, a.a);
// 	v = substract_vector4_to_vector4(a.c, a.a);

// 	uv = dot_t_vector4(u, v);
// 	wv = dot_t_vector4(w, v);
// 	vv = dot_t_vector4(v, v);
// 	wu = dot_t_vector4(w, u);
// 	uu = dot_t_vector4(u, u);

// 	s = ((uv * wv) - (vv * wu)) / ((uv * uv) - (uu * vv));
// 	t = ((uv * wu) - (uu * wv)) / ((uv * uv) - (uu * vv));
// 	// printf("s = %f\n", s);
// 	// printf("t = %f\n", t);
// 	// printf("s + t = %f\n", s + t);
// 	if ((s >= 0.0 || t >= 0.0) && s + t <= 1.0)
// 		return (BOOL_TRUE);

// 	return (BOOL_FALSE);
// }

int				intersect_segment_by_segment(t_vector4 a, t_vector4 b, t_vector4 c, t_vector4 d)
{
	t_vector4 u;
	t_vector4 v;
	t_vector4 w;

	float uv;
	float wv;
	float vv;
	float wu;
	float uu;

	float denominator;
	float s;
	float t;

	u = substract_vector4_to_vector4(b, a);
	v = substract_vector4_to_vector4(d, c);
	w = substract_vector4_to_vector4(a, c);

	uu = dot_t_vector4(u, u);
	uv = dot_t_vector4(u, v);
	vv = dot_t_vector4(v, v);
	wu = dot_t_vector4(w, u);
	wv = dot_t_vector4(w, v);

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
    t_vector4   result = add_vector4_to_vector4(w, substract_vector4_to_vector4(mult_vector4_by_float(u,sc), mult_vector4_by_float(v, tc)));  // =  S1(sc) - S2(tc)

	if (sc == 0 || tc == 0 || sc == 1 || tc == 1)
		return (BOOL_FALSE);
	if (result.x == 0 && result.y == 0 && result.z == 0)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

float			calc_distance_to_triangle(t_triangle p_triangle, t_vector4 point)
{
	float    sb, sn, sd;
	t_vector4	normal;

	normal = cross_t_vector4(substract_vector4_to_vector4(p_triangle.b, p_triangle.a), substract_vector4_to_vector4(p_triangle.c, p_triangle.a));
    sn = -dot_t_vector4(normal, substract_vector4_to_vector4(point, p_triangle.a));
    sd = dot_t_vector4(normal, normal);
    sb = sn / sd;

    return (sb);
}

float			calc_distance_to_plane(t_vector4 p_normal, t_vector4 p_center, t_vector4 p_point)
{
	t_vector4	normalized_plane;
	float		result;

	normalized_plane = normalize_t_vector4(p_normal);
	result = p_point.x * normalized_plane.x
			+ p_point.y * normalized_plane.y
			+ p_point.z * normalized_plane.z
			- dot_t_vector4(normalized_plane, p_center);
	return (result);
}

int				is_middle(float min, float max, float value)
{
	if (value >= min && value <= max)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
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

t_vector4		interpolate_vector4_over_line(float ratio_x, float ratio_y, t_vector4 ua, t_vector4 ub)
{
	t_vector4	result;

	result.x = ((ub.x - ua.x) * ratio_x) + ua.x;
	result.y = ((ub.y - ua.y) * ratio_y) + ua.y;
	result.z = 0;
	result.w = 0;
	return (result);
}

float			interpolate_ratio(float a, float b, float c)
{
	if (b - a == 0)
		return (0);
	return ((c - a) / (b - a));
}

float			calc_dist_vector4_to_vector4(t_vector4 a, t_vector4 b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)));
}

float			ft_abs_float(float src)
{
	if (src < 0)
		return (-src);
	return (src);
}

int				is_same_sign(float a, float b)
{
	if (a < 0)
	{
		if (b < 0)
			return (BOOL_TRUE);
		else
			return (BOOL_FALSE);
	}
	else
	{
		if (b >= 0)
			return (BOOL_TRUE);
		else
			return (BOOL_FALSE);
	}

}

int				is_triangle_cut_triangle(t_triangle p_a, t_triangle p_b)
{
	int cut_ab;
	int cut_ac;
	int cut_bc;

	cut_ab = intersect_segment_by_segment(p_a.a, p_a.b, p_b.a, p_b.b);
	cut_ac = intersect_segment_by_segment(p_a.a, p_a.c, p_b.a, p_b.b);
	cut_bc = intersect_segment_by_segment(p_a.b, p_a.c, p_b.a, p_b.b);

	if (cut_ab == BOOL_TRUE || cut_ac == BOOL_TRUE || cut_bc == BOOL_TRUE)
		return (BOOL_TRUE);

	cut_ab = intersect_segment_by_segment(p_a.a, p_a.b, p_b.a, p_b.c);
	cut_ac = intersect_segment_by_segment(p_a.a, p_a.c, p_b.a, p_b.c);
	cut_bc = intersect_segment_by_segment(p_a.b, p_a.c, p_b.a, p_b.c);

	if (cut_ab == BOOL_TRUE || cut_ac == BOOL_TRUE || cut_bc == BOOL_TRUE)
		return (BOOL_TRUE);

	cut_ab = intersect_segment_by_segment(p_a.a, p_a.b, p_b.b, p_b.c);
	cut_ac = intersect_segment_by_segment(p_a.a, p_a.c, p_b.b, p_b.c);
	cut_bc = intersect_segment_by_segment(p_a.b, p_a.c, p_b.b, p_b.c);

	if (cut_ab == BOOL_TRUE || cut_ac == BOOL_TRUE || cut_bc == BOOL_TRUE)
		return (BOOL_TRUE);

	return (BOOL_FALSE);
}

int 			is_triangle_in_triangle(t_triangle p_a, t_triangle p_b)
{
	if (is_triangle_parallele(p_a, p_b) == BOOL_FALSE)
	{
		return (BOOL_FALSE);
	}
	if (calc_distance_to_triangle(p_a, p_b.a) != 0)
	{
		return (BOOL_FALSE);
	}
	if (is_point_on_triangle(p_a, p_b.a) == BOOL_TRUE ||
		is_point_on_triangle(p_a, p_b.b) == BOOL_TRUE ||
		is_point_on_triangle(p_a, p_b.c) == BOOL_TRUE)
		return (BOOL_TRUE);
	if (is_point_on_triangle(p_b, p_a.a) == BOOL_TRUE ||
		is_point_on_triangle(p_b, p_a.b) == BOOL_TRUE ||
		is_point_on_triangle(p_b, p_a.c) == BOOL_TRUE)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}