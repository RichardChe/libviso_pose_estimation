#pragma once
#include <stdint.h>

// structure for storing matches
struct p_match {
	float   u1p, v1p; // u,v-coordinates in previous left  image
	int32_t i1p;     // feature index (for tracking)
	float   u2p, v2p; // u,v-coordinates in previous right image
	int32_t i2p;     // feature index (for tracking)
	float   u1c, v1c; // u,v-coordinates in current  left  image
	int32_t i1c;     // feature index (for tracking)
	float   u2c, v2c; // u,v-coordinates in current  right image
	int32_t i2c;     // feature index (for tracking)
	p_match(){}
	p_match(float u1p, float v1p, int32_t i1p, float u2p, float v2p, int32_t i2p,
		float u1c, float v1c, int32_t i1c, float u2c, float v2c, int32_t i2c) :
		u1p(u1p), v1p(v1p), i1p(i1p), u2p(u2p), v2p(v2p), i2p(i2p),
		u1c(u1c), v1c(v1c), i1c(i1c), u2c(u2c), v2c(v2c), i2c(i2c) {}
};