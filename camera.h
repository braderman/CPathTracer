#pragma once

#include "ray.h"

typedef struct 
{
	Vec3 origin;
	Vec3 lower_left_corner;
	Vec3 horizontal;
	Vec3 vertical;
} Camera;

void camera_init(Camera *pThis);
void camera_get_ray(const Camera *pThis, float u, float v, Ray *pRay);