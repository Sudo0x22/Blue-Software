#include<iostream>
#include<vector>
#include"Glow.h"
#include"Aimbot.h"


#define color_red FF0000
#define color_blue 0000FF

inline void drawColor()
{
	struct colors {
		enum colors_t {
			blue,
			red,
			green,
		};
		colors_t colors;
		union {
			float blue_rgba;
			float red_rgba;
			float green_rgba;
		};
		float colors_s(float blue, float red, float green);
	};
}

inline void get_color(float g, float b, float a) {
	struct rgba {
		union {
			float r;
			float g;
			float b;
			float a;
		};
		float rgba_t(float r, float g, float b, float a);
	};

	float color_a = 14.0f;
	float* color_ac = &color_a;
	if (color_a) {
		float* get_color_code = &color_a;
		drawColor();
	}
}