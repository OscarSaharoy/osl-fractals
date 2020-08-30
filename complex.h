struct complex {
	float re, im;
};

complex __operator__add__( complex z1, complex z2 ) {
	return complex( z1.re+z2.re, z1.im+z2.im );
}

complex __operator__sub__( complex z1, complex z2 ) {
	return complex( z1.re-z2.re, z1.im-z2.im );
}

complex __operator__mul__( complex z1, complex z2 ) {
	return complex( z1.re*z2.re - z1.im*z2.im, z1.re*z2.im + z1.im*z2.re );
}

complex __operator__mul__( complex z1, float f ) {
	return complex( z1.re * f, z1.im * f );
}

complex __operator__div__( complex z1, float f ) {
	return complex( z1.re / f, z1.im / f );
}

complex __operator__neg__(complex z) {
	return complex( -z.re, -z.im );
}

float mod2(complex z) {
	return z.re*z.re + z.im*z.im;
}

color lerp(color color1, color color2, float x) {
	if(x < 0.0) return color1;
	if(x > 1.0) return color2;
	return color1 * (1-x) + color2 * x;
}

float __operator__mod__(float a, float b) {
	return a - int(a/b) * b;
}
