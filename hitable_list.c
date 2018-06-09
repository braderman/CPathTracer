#include <stdlib.h>
#include <string.h>
#include "hitable_list.h"
#include "sphere.h"

HitableList hitable_list_create(int size)
{
	HitableList retVal;
    retVal.hitable.hitableType = HitableTypeList;
	retVal.size = size;
	retVal.list = (Hitable**)malloc(size * sizeof(Hitable*));
	memset(retVal.list, 0, sizeof(Hitable*) * size);
	return retVal;
}

void hitable_list_destroy(HitableList* pThis)
{
	for(int i = 0;i < pThis->size;++i)
	{
		if (pThis->list[i])
			free(pThis->list[i]);
	}

	free(pThis->list);
	pThis->list = NULL;
	pThis->size = 0;
}

bool hitable_list_hit(const HitableList* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec)
{
	HitRecord temp_rec;
	bool hit_anything = FALSE;
	float closest_so_far = t_max;

	for(int i = 0;i < pThis->size;++i)
	{
		if (hitable_hit(pThis->list[i], r, t_min, closest_so_far, &temp_rec))
		{
			hit_anything = TRUE;
			closest_so_far = temp_rec.t;
			*pRec = temp_rec; 			
		}
	}

	return hit_anything;
}
