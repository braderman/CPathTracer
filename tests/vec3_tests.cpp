#include <gtest/gtest.h>
#include "../vec3.c"

TEST(Vec3Test, create_empty) 
{
	Vec3 v = vec3_create_empty();
	ASSERT_FLOAT_EQ(v.x, 0.0f);
	ASSERT_FLOAT_EQ(v.y, 0.0f);
	ASSERT_FLOAT_EQ(v.z, 0.0f);
	ASSERT_FLOAT_EQ(v.r, 0.0f);
	ASSERT_FLOAT_EQ(v.g, 0.0f);
	ASSERT_FLOAT_EQ(v.b, 0.0f);
}

TEST(Vec3Test, create)
{
	Vec3 v = vec3_create(1, 2, 3);
	ASSERT_FLOAT_EQ(v.x, 1.0f);
	ASSERT_FLOAT_EQ(v.y, 2.0f);
	ASSERT_FLOAT_EQ(v.z, 3.0f);	
	ASSERT_FLOAT_EQ(v.r, 1.0f);
	ASSERT_FLOAT_EQ(v.g, 2.0f);
	ASSERT_FLOAT_EQ(v.b, 3.0f);	
}

TEST(Vec3Test, set) 
{
	Vec3 v = vec3_create_empty();
	
	ASSERT_FLOAT_EQ(v.x, 0.0f);
	ASSERT_FLOAT_EQ(v.y, 0.0f);
	ASSERT_FLOAT_EQ(v.z, 0.0f);

	vec3_set(&v, 1, 2, 3);

	ASSERT_FLOAT_EQ(v.x, 1.0f);
	ASSERT_FLOAT_EQ(v.y, 2.0f);
	ASSERT_FLOAT_EQ(v.z, 3.0f);	
}

TEST(Vec3Test, neg)
{
	Vec3 v = vec3_create(1, 2, 3);
	v = vec3_neg(&v);
	ASSERT_FLOAT_EQ(v.x, -1.0f);
	ASSERT_FLOAT_EQ(v.y, -2.0f);
	ASSERT_FLOAT_EQ(v.z, -3.0f);
}

TEST(Vec3Test, neg_mod)
{
	Vec3 v = vec3_create(1, 2, 3);
	vec3_neg_mod(&v);
	ASSERT_FLOAT_EQ(v.x, -1.0f);
	ASSERT_FLOAT_EQ(v.y, -2.0f);
	ASSERT_FLOAT_EQ(v.z, -3.0f);
}

TEST(Vec3Test, add_vec)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	Vec3 v3 = vec3_add_vec(&v1, &v2);

	ASSERT_FLOAT_EQ(v3.x, 5.0f);
	ASSERT_FLOAT_EQ(v3.y, 7.0f);
	ASSERT_FLOAT_EQ(v3.z, 9.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 5.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, sub_vec)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	Vec3 v3 = vec3_sub_vec(&v2, &v1);

	ASSERT_FLOAT_EQ(v3.x, 3.0f);
	ASSERT_FLOAT_EQ(v3.y, 3.0f);
	ASSERT_FLOAT_EQ(v3.z, 3.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 5.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, mul_vec)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	Vec3 v3 = vec3_mul_vec(&v1, &v2);

	ASSERT_FLOAT_EQ(v3.x, 4.0f);
	ASSERT_FLOAT_EQ(v3.y, 10.0f);
	ASSERT_FLOAT_EQ(v3.z, 18.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 5.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, div_vec)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 6, 6);
	Vec3 v3 = vec3_div_vec(&v2, &v1);

	ASSERT_FLOAT_EQ(v3.x, 4.0f);
	ASSERT_FLOAT_EQ(v3.y, 3.0f);
	ASSERT_FLOAT_EQ(v3.z, 2.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 6.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, add_vec_mod)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	vec3_add_vec_mod(&v1, &v2);

	ASSERT_FLOAT_EQ(v1.x, 5.0f);
	ASSERT_FLOAT_EQ(v1.y, 7.0f);
	ASSERT_FLOAT_EQ(v1.z, 9.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 5.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, sub_vec_mod)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	vec3_sub_vec_mod(&v2, &v1);

	ASSERT_FLOAT_EQ(v2.x, 3.0f);
	ASSERT_FLOAT_EQ(v2.y, 3.0f);
	ASSERT_FLOAT_EQ(v2.z, 3.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);
}

TEST(Vec3Test, mul_vec_mod)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 5, 6);
	vec3_mul_vec_mod(&v1, &v2);

	ASSERT_FLOAT_EQ(v1.x, 4.0f);
	ASSERT_FLOAT_EQ(v1.y, 10.0f);
	ASSERT_FLOAT_EQ(v1.z, 18.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 5.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, div_vec_mod)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 6, 6);
	vec3_div_vec_mod(&v2, &v1);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 3.0f);
	ASSERT_FLOAT_EQ(v2.z, 2.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);
}

TEST(Vec3Test, mul_scalar)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_mul_scalar(&v1, 2.0f);

	ASSERT_FLOAT_EQ(v2.x, 2.0f);
	ASSERT_FLOAT_EQ(v2.y, 4.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);
}

TEST(Vec3Test, div_scalar)
{
	Vec3 v1 = vec3_create(4, 6, 10);
	Vec3 v2 = vec3_div_scalar(&v1, 2.0f);

	ASSERT_FLOAT_EQ(v2.x, 2.0f);
	ASSERT_FLOAT_EQ(v2.y, 3.0f);
	ASSERT_FLOAT_EQ(v2.z, 5.0f);

	ASSERT_FLOAT_EQ(v1.x, 4.0f);
	ASSERT_FLOAT_EQ(v1.y, 6.0f);
	ASSERT_FLOAT_EQ(v1.z, 10.0f);
}

TEST(Vec3Test, mul_scalar_mod)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	vec3_mul_scalar_mod(&v1, 2.0f);

	ASSERT_FLOAT_EQ(v1.x, 2.0f);
	ASSERT_FLOAT_EQ(v1.y, 4.0f);
	ASSERT_FLOAT_EQ(v1.z, 6.0f);
}

TEST(Vec3Test, div_scalar_mod)
{
	Vec3 v1 = vec3_create(4, 6, 10);
	vec3_div_scalar_mod(&v1, 2.0f);

	ASSERT_FLOAT_EQ(v1.x, 2.0f);
	ASSERT_FLOAT_EQ(v1.y, 3.0f);
	ASSERT_FLOAT_EQ(v1.z, 5.0f);
}

TEST(Vec3Test, lengths)
{
	Vec3 v = vec3_create(1, 2, 3);
	ASSERT_FLOAT_EQ(vec3_length(&v), 3.7416573867739413f);
	ASSERT_FLOAT_EQ(vec3_squared_length(&v), 14);

	ASSERT_FLOAT_EQ(v.x, 1.0f);
	ASSERT_FLOAT_EQ(v.y, 2.0f);
	ASSERT_FLOAT_EQ(v.z, 3.0f);
}

TEST(Vec3Test, dot)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_create(4, 6, 6);

	ASSERT_FLOAT_EQ(vec3_dot(&v1, &v2), 34.0f);

	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);

	ASSERT_FLOAT_EQ(v2.x, 4.0f);
	ASSERT_FLOAT_EQ(v2.y, 6.0f);
	ASSERT_FLOAT_EQ(v2.z, 6.0f);
}

TEST(Vec3Test, unit_vector)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	Vec3 v2 = vec3_unit_vector(&v1);
	ASSERT_FLOAT_EQ(vec3_length(&v2), 1.0f);
	ASSERT_FLOAT_EQ(vec3_squared_length(&v2), 1.0f);
	ASSERT_FLOAT_EQ(v2.x, 0.2672612419124244);
	ASSERT_FLOAT_EQ(v2.y, 0.5345224838248488);
	ASSERT_FLOAT_EQ(v2.z, 0.8017837257372732);	
	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 2.0f);
	ASSERT_FLOAT_EQ(v1.z, 3.0f);		
}

TEST(Vec3Test, make_unit_vector)
{
	Vec3 v1 = vec3_create(1, 2, 3);
	vec3_make_unit_vector(&v1);
	ASSERT_FLOAT_EQ(vec3_length(&v1), 1.0f);
	ASSERT_FLOAT_EQ(vec3_squared_length(&v1), 1.0f);
	ASSERT_FLOAT_EQ(v1.x, 0.2672612419124244);
	ASSERT_FLOAT_EQ(v1.y, 0.5345224838248488);
	ASSERT_FLOAT_EQ(v1.z, 0.8017837257372732);	
}

TEST(Vec3Test, cross)
{
	Vec3 v1 = vec3_create(1, 0, 0);
	Vec3 v2 = vec3_create(0, 1, 0);
	Vec3 v3 = vec3_cross(&v1, &v2);

	ASSERT_FLOAT_EQ(v3.x, 0.0f);
	ASSERT_FLOAT_EQ(v3.y, 0.0f);
	ASSERT_FLOAT_EQ(v3.z, 1.0f);	
	
	ASSERT_FLOAT_EQ(v1.x, 1.0f);
	ASSERT_FLOAT_EQ(v1.y, 0.0f);
	ASSERT_FLOAT_EQ(v1.z, 0.0f);		

	ASSERT_FLOAT_EQ(v2.x, 0.0f);
	ASSERT_FLOAT_EQ(v2.y, 1.0f);
	ASSERT_FLOAT_EQ(v2.z, 0.0f);		
}
