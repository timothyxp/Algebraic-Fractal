#include <iostream>
#include <math.h>
#include <algorithm>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define int long double
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
RenderWindow window(VideoMode(window_W, window_H), "Julia set");
int l_x = -2;
int r_x = 2;
int r_y = 1.2;
int l_y = -1.2;
bool change = true;
bool change2 = true;
const int def_x = 10;
const int def_y = 45;
const int border = 200;
VertexArray p(LinesStrip, 5);
vector <Color> w;
Image a;

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
}

void my_colors() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(255 * i / 20, 0, 0);
	}
	w[maxi] = Color(192, 192, 192);
	for (int i = maxi; i >= maxi * 2 / 10; i--) {
		w[i] = Color(255 - (180 - (maxi - i)) * 255 / (180), 215 - (180 - (maxi - i)) * 215 / (180), 0);
	}
}

void my_colors1() {
	for (int i = 0; i <= maxi; i++) {
		w[i] = Color(255 - 255 * i / maxi, 255 - 255 * i / maxi, 255 - 255 * i / maxi);
	}
}

void my_colors2() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(255-50 * i / (maxi * 8 / 10),255- 200 * i / (maxi * 8 / 10), 255-50 * i / (maxi * 8 / 10));
	}
	w[maxi] = Color(192, 192, 192);
	for (int i = maxi; i >= maxi * 2 / 10; i--) {
		w[i] = Color(255 - (255 - (maxi - i)) * 255 / (180), 215 - (120 - (maxi - i)) * 20 / (180), 147 - (20 - (maxi - i)) * 147 / (180));
	}
}

void my_colors3() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(0, 0, 255 * i / 20);
	}
	for (int i = maxi; i >= maxi * 8 / 10; i--) {
		w[i] = Color(0,0, 235 - (180 - (maxi - i)) * 215 / (180));
	}
}

void my_colors4() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(0, 255 * i / 20, 0);
	}
	w[maxi] = Color(192, 192, 192);
	for (int i = maxi; i >= maxi * 2 / 10; i--) {
		w[i] = Color(255 - (180 - (maxi - i)) * 255 / (180), 0, 215 - (180 - (maxi - i)) * 215 / (180));
	}
	
}

void my_colors5() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(0, 0, 255 * i / 20);
	}
	w[maxi] = Color(192, 192, 192);
	for (int i = maxi; i >= maxi * 2 / 10; i--) {
		w[i] = Color(0, 255 - (180 - (maxi - i)) * 255 / (180), 215 - (180 - (maxi - i)) * 215 / (180));
	}
}

void my_colors6() {
	for (int i = 0; i < maxi * 8 / 10; i++) {
		w[i] = Color(255 * i / 20, 255 * i / 20, 255 * i / 20);
	}
	w[maxi] = Color(192, 192, 192);
	for (int i = maxi; i >= maxi * 2 / 10; i--) {
		w[i] = Color(255-(150-(maxi-i))*255/(150), 255 - (180 - (maxi - i)) * 255 / (180), 215 - (180 - (maxi - i)) * 215 / (180));
	}
}

void my_colors7() {
	for (int i = 0; i < maxi * 2 / 10; i++) {
		w[i] = Color(100 * i / 20, 150 * i / 20, 0);
	}
	for (int i = maxi * 2 / 10; i < maxi * 5 / 10; i++) {
		w[i] = Color(0, 255 - (180 - (maxi - i)) * 255 / (180), 215 - (180 - (maxi - i)) * 215 / (180));
	}
	w[maxi] = Color(0, 0, 0);;
	for (int i = maxi - 1; i >= maxi * 5 / 10; i--) {
		w[i] = Color(255 - (50 - (maxi - i)) * 255 / (50), 200 - (90 - (maxi - i)) * 255 / (90), 155 - (155 - (maxi - i)) * 155 / (180));
	}
}

void my_colors8() {
	for (int i = 0; i < maxi * 2 / 10; i++) {
		w[i] = Color(100 * i / 20, 0, 0);
	}
	for (int i = maxi * 2 / 10; i < maxi * 5 / 10; i++) {
		w[i] = Color(0, 180 - (120 - (maxi - i)) * 155 / (120), 0);
	}
	w[maxi] = Color(0, 0, 0);;
	for (int i = maxi - 1; i >= maxi * 5 / 10; i--) {
		w[i] = Color(0, 0, 155 - (155 - (maxi - i)) * 155 / (180));
	}
}

void my_colors9() {
	int sz = maxi / 10;
	for (int i = 0; i < maxi * 1 / 10; i++) {
		w[i] = Color(i * 255 / 10, 0, 0);
	}
	for (int i = maxi / 10; i < maxi * 2 / 10; i++) {
		w[i] = Color(0, i * 255 / 10, 0);
	}
	for (int i = maxi*2 / 10; i < maxi * 3 / 10; i++) {
		w[i] = Color(0, 0, i * 255 / 10);
	}
	for (int i = maxi*3 / 10; i < maxi * 4 / 10; i++) {
		w[i] = Color(i * 255 / 10, i * 255 / 10, 0);
	}
	for (int i = maxi*4 / 10; i < maxi * 5 / 10; i++) {
		w[i] = Color(i * 255 / 10, 0, i * 255 / 10);
	}
	for (int i = maxi*5 / 10; i < maxi * 6 / 10; i++) {
		w[i] = Color(0, i * 255 / 10, i * 255 / 10);
	}
	for (int i = maxi*6 / 10; i < maxi * 7 / 10; i++) {
		w[i] = Color(i * 255 / 10, i * 255 / 10, 0);
	}
	for (int i = maxi*7 / 10; i < maxi * 8 / 10; i++) {
		w[i] = Color(0, i * 255 / 10, 0);
	}
	for (int i = maxi*8 / 10; i < maxi * 9 / 10; i++) {
		w[i] = Color(0, 0, i * 255 / 10);
	}
	for (int i = maxi * 9 / 10; i <= maxi; i++) {
		w[i] = Color(i * 255 / 10, 0, 0);
	}
}

void my_colors10() {
#define sin cos
	int sz = maxi / 10;
	for (int i = 0; i < maxi * 1 / 10; i++) {
		w[i] = Color(sin(i) * 255 / 10, 0, 0);
	}
	for (int i = maxi / 10; i < maxi * 2 / 10; i++) {
		w[i] = Color(0, sin(i) * 255 / 10, 0);
	}
	for (int i = maxi * 2 / 10; i < maxi * 3 / 10; i++) {
		w[i] = Color(0, 0, sin(i) * 255 / 10);
	}
	for (int i = maxi * 3 / 10; i < maxi * 4 / 10; i++) {
		w[i] = Color(sin(i) * 255 / 10, sin(i) * 255 / 10, 0);
	}
	for (int i = maxi * 4 / 10; i < maxi * 5 / 10; i++) {
		w[i] = Color(sin(i) * 255 / 10, 0, sin(i) * 255 / 10);
	}
	for (int i = maxi * 5 / 10; i < maxi * 6 / 10; i++) {
		w[i] = Color(0, sin(i) * 255 / 10, sin(i) * 255 / 10);
	}
	for (int i = maxi * 6 / 10; i < maxi * 7 / 10; i++) {
		w[i] = Color(sin(i) * 255 / 10, sin(i) * 255 / 10, 0);
	}
	for (int i = maxi * 7 / 10; i < maxi * 8 / 10; i++) {
		w[i] = Color(0, sin(i) * 255 / 10, 0);
	}
	for (int i = maxi * 8 / 10; i < maxi * 9 / 10; i++) {
		w[i] = Color(0, 0, sin(i) * 255 / 10);
	}
	for (int i = maxi * 9 / 10; i <= maxi; i++) {
		w[i] = Color(sin(i) * 255 / 10, 0, 0);
	}
#undef sin
}

void my_colors11() {
	const int x = 5;
	const int_fast32_t y = 20;
	for (int i = 0; i < maxi / 5; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(241 - r, 166 - r, 34 - r);
	}
	for (int i = maxi * 1 / 6; i < maxi * 2 / 5; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(244 - r, 212 - r, 118 - r);
	}
	for (int i = maxi * 2 / 6; i < maxi; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(149 - r, 102 - r, 19 - r);
	}
	for (int i = maxi * 3 / 6; i < maxi; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(230 - r, 113 - r, 15 - r);
	}
	for (int i = maxi * 4 / 6; i < maxi; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(118 - r, 221 - r, 234 - r);
	}
	for (int i = maxi * 5 / 6; i < maxi; i++) {
		int r = x * (long long(i) % y);
		w[i] = Color(240 - r, 234 - r, 106 - r);
	}
	w[maxi] = Color(0, 0, 0);
}

void draw_image() {
	a.saveToFile("pictures.jpg");
	Texture b;
	b.loadFromImage(a);
	Sprite c;
	c.setTexture(b, true);
	c.setPosition(0, 0);
	window.clear();
	window.draw(c);
	window.display();
}

signed main() {
	window.setPosition(Vector2i(0, 0));
	a.create(window_W, window_H);
	w.resize(maxi + 1);
	my_colors4();
	int x1, y1;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
			if (Mouse::isButtonPressed(Mouse::Left) && change2) {
				Vector2i r = Mouse::getPosition();
				int x = r.x;
				int y = r.y;
				x1 = x;
				y1 = y;
				change2 = false;
			}
			if (Mouse::isButtonPressed(Mouse::Left) && !change) {
				Vector2i r = Mouse::getPosition();
				int x = r.x;
				int y = r.y;
				x -= def_x;
				x1 -= def_x;
				y -= def_y;
				y1 -= def_y;
				window.clear();
				p[0].position = Vector2f(x, y);
				p[0].color = Color(232, 227, 227);
				p[1].position = Vector2f(x, y1);
				p[1].color = Color(232, 227, 227);
				p[2].position = Vector2f(x1, y1);
				p[2].color = Color(232, 227, 227);
				p[3].position = Vector2f(x1, y);
				p[3].color = Color(232, 227, 227);
				p[4].position = p[0].position;
				p[4].color = Color(232, 227, 227);
				x += def_x;
				x1 += def_x;
				y += def_y;
				y1 += def_y;
				Texture b;
				b.loadFromImage(a);
				Sprite c;
				c.setTexture(b, true);
				c.setPosition(0, 0);
				window.draw(c);
				window.draw(p);
				window.display();
			}
			if (!Mouse::isButtonPressed(Mouse::Left) && !change2) {
				Vector2i r = Mouse::getPosition();
				int x = r.x;
				int y = r.y;
				x -= def_x;
				x1 -= def_x;
				y -= def_y;
				y1 -= def_y;
				int x2 = l_x + (r_x - l_x)*min(x, x1) / (window_W);
				int x3 = l_x + (r_x - l_x)*max(x, x1) / (window_W);
				int y2 = l_y + (r_y - l_y)*min(y1, y) / (window_H);
				int y3 = l_y + (r_y - l_y)*max(y, y1) / (window_H);
				l_x = x2;
				r_x = x3;
				l_y = y2;
				r_y = y3;
				change2 = true;
				change = true;
			}
			if (change) {
				for (int i = 0; i < window_W; i++) {
					for (int j = 0; j < window_H; j++) {
						RectangleShape q;
						q.setSize(Vector2f(1, 1));
						int x = l_x + (r_x - l_x)*(i / (window_W));
						int y = l_y + (r_y - l_y)*(j / (window_H));
						int r = f1(comp(x, y));
						a.setPixel(i, j, w[r]);
					}
					//draw_image();
				}
				draw_image();
				change = false;
			}
		}
	}
	return 0;
}