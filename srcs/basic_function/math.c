#include "unknow_project.h"

t_vector3		cross_t_vector3(t_vector3 a, t_vector3 b) //Produit vectoriel / cross product
{
	t_vector3 result;

	result = create_t_vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
								a.x * b.y - a.y * b.x);

	return (result);
}

t_vector3 		normalize_t_vector3(t_vector3 v) // ramener la longueur du vecteur a 1
{
   float length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
   return (create_t_vector3(v.x / length_of_v, v.y / length_of_v, v.z / length_of_v));
}

float			dot_t_vector3(t_vector3 a, t_vector3 b) //Produit scalaire / dot product
{
    float result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;

    return (result);
}
