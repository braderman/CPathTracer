#pragma once

#include "hitable.h"
#include "ray.h"
#include "common.h"

typedef struct {
	Hitable hitable;
	Hitable **list;
	int size;
} HitableList;

HitableList hitable_list_create(int size);
void hitable_list_destroy(HitableList* pThis);
bool hitable_list_hit(const HitableList* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec);