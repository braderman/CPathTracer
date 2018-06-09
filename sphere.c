#include <stdlib.h>
#include "sphere.h"

void sphere_set(Sphere* pThis, const Vec3* center, float radius)
{
	pThis->center = *center;
	pThis->radius = radius;
}

Hitable* sphere_create(float x, float y, float z, float radius)
{
    Sphere* pSphere = (Sphere*)malloc(sizeof(Sphere));
    pSphere->hitable.hitableType = HitableTypeSphere;
    vec3_set(&pSphere->center, x, y, z);
    pSphere->radius = radius;
    return (Hitable*)pSphere;
}

bool sphere_hit(const Sphere* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec)
{
	Vec3 oc = r->origin;
	vec3_sub_vec_mod(&oc, &pThis->center);
	float a = vec3_dot(&r->direction, &r->direction);
	float b = vec3_dot(&oc, &r->direction);
	float c = vec3_dot(&oc, &oc) - pThis->radius * pThis->radius;
	float discriminant = b * b - a * c;

	if (discriminant > 0)
	{
		float temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min)
		{
			pRec->t = temp;
			pRec->p = ray_point_at_parameter(r, pRec->t);
			pRec->normal = pRec->p;
			vec3_sub_vec_mod(&pRec->normal, &pThis->center);
			vec3_div_scalar_mod(&pRec->normal, pThis->radius);
			return TRUE;
		}
		
		temp = (-b + sqrt(b * b - a * c )) / a;

		if (temp < t_max && temp > t_min)
		{
			pRec->t = temp;
			pRec->p = ray_point_at_parameter(r, pRec->t);
			pRec->normal = pRec->p;
			vec3_sub_vec_mod(&pRec->normal, &pThis->center);
			vec3_div_scalar_mod(&pRec->normal, pThis->radius);
			return TRUE;
		}
	}

	return FALSE;
}
