#include <string.h>
#include "ray.h"

void ray_clear(Ray* pThis)
{
	memset(pThis, 0, sizeof(Ray));
}

void ray_set(Ray *pThis, const Vec3* origin, const Vec3* direction)
{
	pThis->origin = *origin;
	pThis->direction = *direction;
	return;
}

Vec3 ray_point_at_parameter(const Ray* pThis, float t)
{
	//origin + t * direction
	Vec3 retVal = pThis->direction;
	vec3_mul_scalar_mod(&retVal, t);
	vec3_add_vec_mod(&retVal, &pThis->origin);
	return retVal;
}