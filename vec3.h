#pragma once

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

union Vec3_
{
	struct { float x, y, z;	};
	struct { float r, g, b; };
};

typedef union Vec3_ Vec3;

Vec3 vec3_neg(const Vec3* pVec);
void vec3_neg_mod(Vec3* pVec);
void vec3_add_vec_mod(Vec3* pThis, const Vec3* pVec);
void vec3_sub_vec_mod(Vec3* pThis, const Vec3* pVec);
void vec3_mul_vec_mod(Vec3* pThis, const Vec3* pVec);
void vec3_div_vec_mod(Vec3* pThis, const Vec3* pVec);
void vec3_mul_scalar_mod(Vec3* pThis, float val);
void vec3_div_scalar_mod(Vec3* pThis, float val);
Vec3 vec3_add_vec(const Vec3* pVec1, const Vec3* pVec2);
Vec3 vec3_sub_vec(const Vec3* pVec1, const Vec3* pVec2);
Vec3 vec3_mul_vec(const Vec3* pVec1, const Vec3* pVec2);
Vec3 vec3_div_vec(const Vec3* pVec1, const Vec3* pVec2);
Vec3 vec3_mul_scalar(const Vec3* pVec, float val);
Vec3 vec3_div_scalar(const Vec3* pVec, float val);
float vec3_length(const Vec3* pThis);
float vec3_squared_length(const Vec3* pThis);
void vec3_make_unit_vector(Vec3* pThis);
Vec3 vec3_unit_vector(const Vec3 *pVec);
float vec3_dot(const Vec3* pVec1, const Vec3* pVec2);
Vec3 vec3_cross(const Vec3* pVec1, const Vec3* pVec2);
void vec3_set(Vec3* pThis, float x, float y, float z);
void vec3_clear(Vec3* pThis);

#ifdef __cplusplus
}
#endif