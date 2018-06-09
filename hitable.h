#pragma once

#include "ray.h"
#include "common.h"

typedef struct {
	float t;
	Vec3 p;
	Vec3 normal;
} HitRecord;

typedef enum { HitableTypeSphere, HitableTypeList } HitableTypeEnum;

typedef struct
{
	HitableTypeEnum hitableType;
} Hitable;

bool hitable_hit(const Hitable* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec);