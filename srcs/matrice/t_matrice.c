#include "unknow_project.h"

t_matrix create_t_matrix()
{
	t_matrix result;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i)
				result.value[i][j] = 0.0f;
			else
				result.value[i][j] = 1.0f;
			j++;
		}
		i++;
	}

	return (result);
}

t_matrix *initialize_t_matrix()
{
	t_matrix *result;

	if (!(result = (t_matrix *)malloc(sizeof(t_matrix))))
		error_exit(-13, "Can't create a t_matrix array");

	*result = create_t_matrix();

	return (result);
}

t_matrix create_translation_matrix(t_vector3 translation)
{
	t_matrix result;

	result = create_t_matrix();

	result.value[0][3] = translation.x;
	result.value[1][3] = translation.y;
	result.value[2][3] = translation.z;

	return (result);
}

t_matrix create_scaling_matrix(t_vector3 scaling)
{
	t_matrix result;

	result = create_t_matrix();

	result.value[0][0] = scaling.x;
	result.value[1][1] = scaling.y;
	result.value[2][2] = scaling.z;

	return (result);
}

t_matrix create_rotation_x_matrix(float angle)
{
	t_matrix 	result;
	float		radian;

	result = create_t_matrix();
	radian = degree_to_radius(angle);

	result.value[1][1] = cos(radian);
	result.value[1][2] = -sin(radian);
	result.value[2][1] = sin(radian);
	result.value[2][2] = cos(radian);

	return (result);
}

t_matrix create_rotation_y_matrix(float angle)
{
	t_matrix 	result;
	float		radian;

	result = create_t_matrix();
	radian = degree_to_radius(angle);

	result.value[0][0] = cos(radian);
	result.value[0][2] = sin(radian);
	result.value[2][0] = -sin(radian);
	result.value[2][2] = cos(radian);

	return (result);
}

t_matrix create_rotation_z_matrix(float angle)
{
	t_matrix	result;
	float		radian;

	result = create_t_matrix();
	radian = degree_to_radius(angle);

	result.value[0][0] = cos(radian);
	result.value[0][1] = -sin(radian);
	result.value[1][0] = sin(radian);
	result.value[1][1] = cos(radian);

	return (result);
}

t_matrix create_rotation_matrix(float x, float y, float z)
{
	t_matrix tmp[4];
	t_matrix result;

	tmp[0] = create_rotation_x_matrix(x);
	tmp[1] = create_rotation_y_matrix(y);
	tmp[2] = create_rotation_z_matrix(z);

	tmp[3] = mult_matrix_by_matrix(&tmp[0], &tmp[1]);
	result = mult_matrix_by_matrix(&tmp[3], &tmp[2]);

	return (result);
}

t_matrix mult_matrix_by_matrix(t_matrix *m1, t_matrix *m2)
{
	t_matrix	result;
	int			i;
	int			j;

	result = create_t_matrix();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.value[i][j] = (m1->value[i][0] * m2->value[0][j]) +
								(m1->value[i][1] * m2->value[1][j]) +
								(m1->value[i][2] * m2->value[2][j]) +
								(m1->value[i][3] * m2->value[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

t_vector3 mult_vector3_by_matrix(t_vector3 *vertex, t_matrix *m)
{
	float		result[3];

	result[0] = m->value[0][0] * vertex->x
				+ m->value[0][1] * vertex->y
				+ m->value[0][2] * vertex->z
				+ m->value[0][3];

	result[1] = m->value[1][0] * vertex->x
				+ m->value[1][1] * vertex->y
				+ m->value[1][2] * vertex->z
				+ m->value[1][3];

	result[2] = m->value[2][0] * vertex->x
				+ m->value[2][1] * vertex->y
				+ m->value[2][2] * vertex->z
				+ m->value[2][3];

	return (create_t_vector3(result[0], result[1], result[2]));
}

void			print_t_matrix(t_matrix *m)
{
	int	i;

	i = 0;
	printf("-----------------------------------------------------------------\n");
	while (i < 4)
	{
		printf("|\t%-4f|\t%-4f|\t%-4f|\t%-4f|\n", m->value[i][0], m->value[i][1],
		m->value[i][2], m->value[i][3]);
		i++;
	}
	printf("-----------------------------------------------------------------\n");
}
