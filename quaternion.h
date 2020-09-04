struct quaternion {
	float a, b, c, d;
};

quaternion __operator__add__( quaternion z1, quaternion z2 ) {
	return quaternion( z1.a+z2.a, z1.b+z2.b, z1.c+z2.c, z1.d+z2.d );
}

quaternion __operator__add__( quaternion z, vector v ) {
	return quaternion( z.a+v[0], z.b+v[1], z.c+v[2], z.d );
}

quaternion __operator__sub__( quaternion z1, quaternion z2 ) {
	return quaternion( z1.a-z2.a, z1.b-z2.b, z1.c-z2.c, z1.d-z2.d );
}

quaternion __operator__sub__( quaternion z, vector v ) {
	return quaternion( z.a-v[0], z.b-v[1], z.c-v[2], z.d );
}

quaternion __operator__mul__( quaternion z1, quaternion z2 ) {
	return quaternion( z1.a*z2.a - z1.b*z2.b - z1.c*z2.c - z1.d*z2.d,
					   z1.a*z2.b + z1.b*z2.a + z1.c*z2.d - z1.d*z2.c,
					   z1.a*z2.c - z1.b*z2.d + z1.c*z2.a + z1.d*z2.b,
					   z1.a*z2.d + z1.b*z2.c - z1.c*z2.b + z1.d*z2.a );
}

quaternion __operator__mul__( quaternion z, float f ) {
	return quaternion( z.a*f, z.b*f, z.c*f, z.d*f );
}

quaternion __operator__mul__( float f, quaternion z ) {
	return quaternion( z.a*f, z.b*f, z.c*f, z.d*f );
}

quaternion __operator__div__( quaternion z, float f ) {
	return quaternion( z.a/f, z.b/f, z.c/f, z.d/f );
}

quaternion __operator__neg__(quaternion z) {
	return quaternion( -z.a, -z.b, -z.c, -z.d );
}

float mod2(quaternion z) {
	return z.a*z.a + z.b*z.b + z.c*z.c + z.d*z.d;
}

float mod(quaternion z) {
	return sqrt( mod2(z) );
}

quaternion vecToQuat(vector v) {
	return quaternion(v[0], v[1], v[2], 0);
}

quaternion vecToQuat(vector v, float f) {
	return quaternion(v[0], v[1], v[2], f);
}

vector quatToVec(quaternion z) {
	return vector(z.a, z.b, z.c);
}

quaternion abs(quaternion z) {
	return quaternion(abs(z.a), abs(z.b), abs(z.c), abs(z.d));
}

quaternion normalize(quaternion z) {
	return z/mod(z);
}

float dot(quaternion z1, quaternion z2) {
	return z1.a*z2.a + z1.b*z2.b + z1.c*z2.c + z1.d*z2.d;
}
