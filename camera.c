#include "camera.h"

void camera_init(Camera *pThis)
{
	vec3_set(&pThis->lower_left_corner, -2.0f, -1.0f, -1.0f);
	vec3_set(&pThis->horizontal, 4.0f, 0.0f, 0.0f);
	vec3_set(&pThis->vertical, 0.0f, 2.0f, 0.0f);
	vec3_set(&pThis->origin, 0.0f, 0.0f, 0.0f);
}

void camera_get_ray(const Camera *pThis, float u, float v, Ray *pRay)
{
	pRay->origin = pThis->origin;
	Vec3 uhorz = pThis->horizontal;
	ve3_mul_scalar_mod(&uhorz, u);
	Vec3 vvert = pThis->vertical;
	ve3_mul_scalar_mod(&vvert, v);
	pRay->direction = pThis->lower_left_corner;
	vec3_add_vec_mod(&pRay->direction, &uhorz);
	vec3_add_vec_mod(&pRay->direction, &vvert);
	vec3_sub_vec_mod(&pRay->direction, &pThis->origin);
}