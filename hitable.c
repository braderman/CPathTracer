#include <assert.h>
#include "hitable.h"
#include "sphere.h"
#include "hitable_list.h"

bool hitable_hit(const Hitable* pThis, const Ray* r, float t_min, float t_max, HitRecord *pRec)
{
	switch(pThis->hitableType)
	{
		case HitableTypeSphere:
			return sphere_hit((Sphere*)pThis, r, t_min, t_max, pRec); 
			break;
		case HitableTypeList:
			return hitable_list_hit((HitableList*)pThis, r, t_min, t_max, pRec); 
			break;
        defaut:
            assert(0 && "unknown hitable type");
	}
}
