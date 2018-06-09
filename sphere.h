#pragma once

#include "common.h"
#include "hitable.h"
#include "vec3.h"
#include "ray.h"

typedef struct 
{
	Hitable hitable;
	Vec3 center;
	float radius;
} Sphere;

Hitable* sphere_create(float x, float y, float z, float radius);
void sphere_set(Sphere* pThis, const Vec3* center, float radius);
bool sphere_hit(const Sphere* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec);
