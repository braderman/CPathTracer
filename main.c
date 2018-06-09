#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"
#include "common.h"
#include "hitable_list.h"
#include "sphere.h"

void get_color(const Ray *r, Hitable *world, Vec3* pColor)
{
	HitRecord rec;
	if (hitable_hit(world, r, 0.0, MAXFLOAT, &rec))
	{
		vec3_set(pColor, rec.normal.x + 1, rec.normal.y + 1, rec.normal.z + 1);
		vec3_mul_scalar_mod(pColor, 0.5f);
		return;
	}
	else
	{
		Vec3 unit_direction = vec3_unit_vector(&r->direction);
		float t = 0.5f * (unit_direction.y + 1.0f);
		vec3_set(pColor, 1, 1, 1);
		vec3_mul_scalar_mod(pColor, 1.0f - t);

		Vec3 color2;
		vec3_set(&color2, 0.5f, 0.7f, 1.0f);
		vec3_mul_scalar_mod(&color2, t);
		vec3_add_vec_mod(pColor, &color2);
	}
}

void get_ray_direction(float u, float v, const Vec3* pLower_left_corner, const Vec3* pHorizontal, const Vec3* pVertical, Vec3* pDirection)
{
	Vec3 horz = *pHorizontal;
	vec3_mul_scalar_mod(&horz, u);

	Vec3 vert = *pVertical;
	vec3_mul_scalar_mod(&vert, v);

	*pDirection = *pLower_left_corner;
	vec3_add_vec_mod(pDirection, &horz);
	vec3_add_vec_mod(pDirection, &vert);
}

int main(int argc, char* argv[])
{
	FreeImage_Initialise(FALSE);

	int nx = 200;
	int ny = 100;

	FIBITMAP* bmp = FreeImage_Allocate(nx, ny, 24, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
	unsigned int pitch  = FreeImage_GetPitch(bmp);
	BYTE *pRowPtr = FreeImage_GetBits(bmp);
	BYTE *pColPtr;
	Vec3 horizontal, vertical, lower_left_corner, color;

	vec3_set(&lower_left_corner, -2, -1, -1);
	vec3_set(&horizontal, 4, 0, 0);
	vec3_set(&vertical, 0, 2, 0);

	Ray r;
	ray_clear(&r);
	HitableList world = hitable_list_create(2);
	world.list[0] = sphere_create(0, 0, -1, 0.5f);
	world.list[1] = sphere_create(0, -100.5, -1, 100);

	for(int y = 0; y < ny; ++y)
	{
		pColPtr = pRowPtr;

		for(int x = 0; x < nx; ++x)
		{
			float u = (float)x / (float)nx;
			float v = (float)y / (float)ny;

			get_ray_direction(u, v, &lower_left_corner, &horizontal, &vertical, &r.direction);
			get_color(&r, (Hitable*)&world, &color);

			int ir = (int)(color.r * 255.99);
			int ig = (int)(color.g * 255.99);
			int ib = (int)(color.b * 255.99);

			pColPtr[FI_RGBA_RED]   = ir;
      		pColPtr[FI_RGBA_GREEN] = ig;
      		pColPtr[FI_RGBA_BLUE]  = ib;
			pColPtr += 3;
		}

		pRowPtr += pitch;
	}

	hitable_list_destroy(&world);

	FreeImage_Save(FIF_PNG, bmp, "output.png", 0);
	FreeImage_Unload(bmp);
	FreeImage_DeInitialise();
}
