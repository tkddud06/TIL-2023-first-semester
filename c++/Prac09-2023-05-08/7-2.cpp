#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << " " << green << " " << blue << endl; }
};

int main()
{
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();
	Color* colors = new Color[3];
	p = colors;

	colors[0].setColor(255, 0, 0);
	colors[1].setColor(0, 255, 0);
	colors[2].setColor(0, 0, 255);

	p[0].show();
	p[1].show();
	p[2].show();


	return 0;
}