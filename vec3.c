#include "vec3.h"
#include <string.h>

void vec3_add_vec_mod(Vec3* pThis, const Vec3* pVec)
{
	pThis->x += pVec->x;
	pThis->y += pVec->y;
	pThis->z += pVec->z;
}

void vec3_sub_vec_mod(Vec3* pThis, const Vec3* pVec)
{
	pThis->x -= pVec->x;
	pThis->y -= pVec->y;
	pThis->z -= pVec->z;
}

void vec3_mul_vec_mod(Vec3* pThis, const Vec3* pVec)
{
	pThis->x *= pVec->x;
	pThis->y *= pVec->y;
	pThis->z *= pVec->z;
}

void vec3_div_vec_mod(Vec3* pThis, const Vec3* pVec)
{
	pThis->x /= pVec->x;
	pThis->y /= pVec->y;
	pThis->z /= pVec->z;
}

void vec3_mul_scalar_mod(Vec3* pThis, float val)
{
	pThis->x *= val;
	pThis->y *= val;
	pThis->z *= val;
}

void vec3_div_scalar_mod(Vec3* pThis, float val)
{
	float k = 1.0f / val;
	pThis->x *= k;
	pThis->y *= k;
	pThis->z *= k;
}

Vec3 vec3_add_vec(const Vec3* pVec1, const Vec3* pVec2)
{
	Vec3 retVal;
	retVal.x = pVec1->x + pVec2->x;
	retVal.y = pVec1->y + pVec2->y;
	retVal.z = pVec1->z + pVec2->z;
	return retVal;
}

Vec3 vec3_sub_vec(const Vec3* pVec1, const Vec3* pVec2)
{
	Vec3 retVal;
	retVal.x = pVec1->x - pVec2->x;
	retVal.y = pVec1->y - pVec2->y;
	retVal.z = pVec1->z - pVec2->z;
	return retVal;
}

Vec3 vec3_mul_vec(const Vec3* pVec1, const Vec3* pVec2)
{
	Vec3 retVal;
	retVal.x = pVec1->x * pVec2->x;
	retVal.y = pVec1->y * pVec2->y;
	retVal.z = pVec1->z * pVec2->z;
	return retVal;
}

Vec3 vec3_div_vec(const Vec3* pVec1, const Vec3* pVec2)
{
	Vec3 retVal;
	retVal.x = pVec1->x / pVec2->x;
	retVal.y = pVec1->y / pVec2->y;
	retVal.z = pVec1->z / pVec2->z;
	return retVal;
}

Vec3 vec3_mul_scalar(const Vec3* pVec, float val)
{
	Vec3 retVal;
	retVal.x = pVec->x * val;
	retVal.y = pVec->y * val;
	retVal.z = pVec->z * val;
	return retVal;
}

Vec3 vec3_div_scalar(const Vec3* pVec, float val)
{
	Vec3 retVal;
	float k = 1.0f / val;
	retVal.x = pVec->x * k;
	retVal.y = pVec->y * k;
	retVal.z = pVec->z * k;
	return retVal;
}

float vec3_length(const Vec3* pThis)
{
	return sqrt((pThis->x * pThis->x) + (pThis->y * pThis->y) + (pThis->z * pThis->z));
}

float vec3_squared_length(const Vec3* pThis)
{
	return (pThis->x * pThis->x) + (pThis->y * pThis->y) + (pThis->z * pThis->z);
}

void vec3_make_unit_vector(Vec3* pThis)
{
	vec3_div_scalar_mod(pThis, vec3_length(pThis));
}

Vec3 vec3_unit_vector(const Vec3 *pVec)
{
	return vec3_div_scalar(pVec, vec3_length(pVec));
}

float vec3_dot(const Vec3* pVec1, const Vec3* pVec2)
{
	return (pVec1->x * pVec2->x) + (pVec1->y * pVec2->y) + (pVec1->z * pVec2->z);
}

Vec3 vec3_cross(const Vec3* pVec1, const Vec3* pVec2)
{
	Vec3 retVal;
	retVal.x = (pVec1->y * pVec2->z) - (pVec1->z * pVec2->y);
	retVal.y = -((pVec1->x * pVec2->z) - (pVec1->z * pVec2->x));
	retVal.z = (pVec1->x * pVec2->y) - (pVec1->y * pVec2->x);
	return retVal;
}

Vec3 vec3_neg(const Vec3* pVec)
{
	Vec3 retVal;
	retVal.x = -pVec->x;
	retVal.y = -pVec->y;
	retVal.z = -pVec->z;
	return retVal;
}

void vec3_neg_mod(Vec3* pVec)
{
	pVec->x = -pVec->x;
	pVec->y = -pVec->y;
	pVec->z = -pVec->z;
}

void vec3_set(Vec3* pThis, float x, float y, float z)
{
	pThis->x = x;
	pThis->y = y;
	pThis->z = z;
}

void vec3_clear(Vec3* pThis)
{
	memset(pThis, 0, sizeof(Vec3));
}
