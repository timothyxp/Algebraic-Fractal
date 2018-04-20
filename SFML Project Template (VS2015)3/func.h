#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

int maxi = 200;
int max_len = 2;
const int window_W = 1920;
const int window_H = 1080;
const int A = 1;
const int B = 1;
const int C = -0.0085;
const int D = 0.71;
const int E = 0.285;
const int F = 0.01;
const int Q = -0.8;
const int W = 0.156;

struct comp {
	int f, s;
	comp(int _f = 0, int _s = 0) {
		f = _f;
		s = _s;
	}
	comp operator +(comp a) {
		return comp(f + a.f, s + a.s);
	}
	comp operator -(comp a) {
		return comp(f - a.f, s - a.s);
	}
	comp operator *(comp a) {
		return comp(f*a.f - s*a.s, f*a.s + s*a.f);
	}
	comp operator *(int a) {
		return comp(f*a, s*a);
	}
	int len() {
		return sqrt(f*f + s*s);
	}
};

inline int f1(comp c, comp a = comp(0, 0), int d = -1) {
	for (int i = 0; i <= maxi; i++) {
		a = a*a;
		a = a*A;
		c = c*B;
		a = a + c;
		d++;
		if (a.len() > max_len)
			break;
	}
	return d;
}

inline int f2(comp a, comp c = comp(C, D), int d = -1) {
	for (int i = 0; i <= maxi; i++) {
		a = a*a;
		a = a*A;
		c = c*B;
		a = a + c;
		d++;
		if (a.len() > max_len) {
			break;
		}
	}
	return d;
}

inline int f3(comp a, comp c = comp(E, F), int d = -1) {
	for (int i = 0; i <= maxi; i++) {
		a = a*a;
		a = a*A;
		c = c*B;
		a = a + c;
		d++;
		if (a.len() > max_len) {
			break;
		}
	}
	return d;
}

inline int f4(comp a, comp c = comp(Q, W), int d = -1) {
	for (int i = 0; i <= maxi; i++) {
		a = a*a;
		a = a*A;
		c = c*B;
		a = a + c;
		d++;
		if (a.len() > max_len) {
			break;
		}
	}
	return d;
};
