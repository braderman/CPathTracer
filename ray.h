#pragma once

#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Ray_
{
	Vec3 origin, direction;
};

typedef struct Ray_ Ray;

void ray_clear(Ray* pThis);
void ray_set(Ray* pThis, const Vec3* origin, const Vec3* direction);
Vec3 ray_point_at_parameter(const Ray* pThis, float t);

#ifdef __cplusplus
}
#endif