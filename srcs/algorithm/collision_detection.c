#include "unknow_project.h"

void		sat_test(t_vector4 normale, t_vector4_list *vector_list, float *min, float *max)
{
	int		i;
	float	dot_result;

	*min = INT_MAX;
	*max = INT_MIN;
	i = -1;
	while (++i < vector_list->size)
	{
		dot_result = dot_t_vector4(normale, t_vector4_list_at(vector_list, i));
		if (dot_result < *min)
			*min = dot_result;
		if (dot_result > *max)
			*max = dot_result;
	}
}

int		is_t_mesh_intersecting(t_mesh *mesh_compared, t_mesh *mesh_target)
{
	int		i;
	float	val[4];

	i = -1;
	while (++i < mesh_compared->faces->size)
	{
		sat_test(t_face_list_get(mesh_compared->faces, i)->normale,
				mesh_compared->next_vertices_in_world, &(val[0]), &(val[1]));
		sat_test(t_face_list_get(mesh_compared->faces, i)->normale,
						mesh_target->vertices_in_world, &(val[2]), &(val[3]));
		if (!is_mid(val[0], val[1], val[2]) && !is_mid(val[2], val[3], val[0]))
			return (BOOL_FALSE);
	}
	i = -1;
	while (++i < mesh_target->faces->size)
	{
		sat_test(t_face_list_get(mesh_target->faces, i)->normale,
				mesh_compared->next_vertices_in_world, &(val[0]), &(val[1]));
		sat_test(t_face_list_get(mesh_target->faces, i)->normale,
						mesh_target->vertices_in_world, &(val[2]), &(val[3]));
		if (!is_mid(val[0], val[1], val[2]) && !is_mid(val[2], val[3], val[0]))
			return (BOOL_FALSE);
	}
	return (BOOL_TRUE);
}
