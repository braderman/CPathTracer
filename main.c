#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"
#include "common.h"
#include "hitable_list.h"
#include "sphere.h"
#include "camera.h"

void random_in_unit_sphere(Vec3* p)
{
	Vec3 one;

	vec3_set(&one, 1, 1, 1);

	do 
	{
		vec3_set(p, drand48(), drand48(), drand48());
		vec3_mul_scalar_mod(p, 2.0f);
		vec3_sub_vec_mod(p, &one);
	} while (vec3_squared_length(p) >= 1.0f);
}

void get_color(const Ray *r, Hitable *world, Vec3* pColor)
{
	HitRecord rec;
	Vec3 target;

	if (hitable_hit(world, r, 0.001f, MAXFLOAT, &rec))
	{
		random_in_unit_sphere(&target);
		vec3_add_vec_mod(&target, &rec.normal);

		Ray r1;
		ray_set(&r1, &rec.p, &target);
		get_color(&r1, world, pColor);
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


int main(int argc, char* argv[])
{
	FreeImage_Initialise(FALSE);

	int nx = 200;
	int ny = 100;
	int ns = 100;

	FIBITMAP* bmp = FreeImage_Allocate(nx, ny, 24, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
	unsigned int pitch  = FreeImage_GetPitch(bmp);
	BYTE *pRowPtr = FreeImage_GetBits(bmp);
	BYTE *pColPtr;
	Vec3 pixColor, rayColor;

	Ray r;
	ray_clear(&r);
	HitableList world = hitable_list_create(2);
	world.list[0] = sphere_create(0, 0, -1, 0.5f);
	world.list[1] = sphere_create(0, -100.5, -1, 100);

	Camera cam;
	camera_init(&cam);

	for(int y = 0; y < ny; ++y)
	{
		pColPtr = pRowPtr;

		for(int x = 0; x < nx; ++x)
		{
			vec3_clear(&pixColor);

			for(int s = 0;s < ns;++s)
			{
				float u = (float)(x + drand48()) / (float)nx;
				float v = (float)(y+ drand48()) / (float)ny;
				camera_get_ray(&cam, u, v, &r);
				get_color(&r, (Hitable*)&world, &rayColor);
				vec3_add_vec_mod(&pixColor, &rayColor);
			}

			vec3_div_scalar_mod(&pixColor, ns);
			pixColor.x = sqrt(pixColor.x);
			pixColor.y = sqrt(pixColor.y);
			pixColor.z = sqrt(pixColor.z);

			int ir = (int)(pixColor.r * 255.99);
			int ig = (int)(pixColor.g * 255.99);
			int ib = (int)(pixColor.b * 255.99);

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
