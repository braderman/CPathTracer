#include <gtest/gtest.h>
#include "../ray.h"

TEST(RayTest, clear) 
{
	Ray r;
	ray_clear(&r);
	ASSERT_FLOAT_EQ(r.origin.x, 0.0f);
	ASSERT_FLOAT_EQ(r.origin.y, 0.0f);
	ASSERT_FLOAT_EQ(r.origin.z, 0.0f);
	ASSERT_FLOAT_EQ(r.direction.x, 0.0f);
	ASSERT_FLOAT_EQ(r.direction.y, 0.0f);
	ASSERT_FLOAT_EQ(r.direction.z, 0.0f);
}

TEST(RayTest, set) 
{
	Ray r;
	Vec3 origin;
	Vec3 direction;

	vec3_set(&origin, 1, 2, 3);
	vec3_set(&direction, 4, 5, 6);

	ray_set(&r, &origin, &direction);

	ASSERT_FLOAT_EQ(r.origin.x, 1.0f);
	ASSERT_FLOAT_EQ(r.origin.y, 2.0f);
	ASSERT_FLOAT_EQ(r.origin.z, 3.0f);
	ASSERT_FLOAT_EQ(r.direction.x, 4.0f);
	ASSERT_FLOAT_EQ(r.direction.y, 5.0f);
	ASSERT_FLOAT_EQ(r.direction.z, 6.0f);

	ASSERT_FLOAT_EQ(origin.x, 1.0f);
	ASSERT_FLOAT_EQ(origin.y, 2.0f);
	ASSERT_FLOAT_EQ(origin.z, 3.0f);
	ASSERT_FLOAT_EQ(direction.x, 4.0f);
	ASSERT_FLOAT_EQ(direction.y, 5.0f);
	ASSERT_FLOAT_EQ(direction.z, 6.0f);
}

TEST(RayTest, point_at_parameter) 
{
	Ray r;
	Vec3 origin;
	Vec3 direction;

	vec3_set(&origin, 1, 2, 3);
	vec3_set(&direction, 4, 5, 6);

	ray_set(&r, &origin, &direction);
	Vec3 p = ray_point_at_parameter(&r, 0.5f);

	ASSERT_FLOAT_EQ(p.x, 3.0f);
	ASSERT_FLOAT_EQ(p.y, 4.5f);
	ASSERT_FLOAT_EQ(p.z, 6.0f);

	ASSERT_FLOAT_EQ(origin.x, 1.0f);
	ASSERT_FLOAT_EQ(origin.y, 2.0f);
	ASSERT_FLOAT_EQ(origin.z, 3.0f);
	ASSERT_FLOAT_EQ(direction.x, 4.0f);
	ASSERT_FLOAT_EQ(direction.y, 5.0f);
	ASSERT_FLOAT_EQ(direction.z, 6.0f);
}