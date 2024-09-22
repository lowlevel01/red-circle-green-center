#include<ncurses.h>
#include<vector>
#include<utility>

using namespace std;

#define R 20
#define CX LINES/2
#define CY COLS/2

vector<pair<int, int>> circlePoints(int cx, int cy, int r){

	vector<pair<int, int>> circle;
	int x = 0;
	int y = -r;
	while(x < -y){
		int yMid = y + 0.5;
		if(x*x + yMid*yMid > r*r){
			y++;
		}
		circle.push_back(make_pair(cx + x, cy + y));
		circle.push_back(make_pair(cx - x, cy + y));
		circle.push_back(make_pair(cx + x, cy - y));
		circle.push_back(make_pair(cx - x, cy - y));
		circle.push_back(make_pair(cx + y, cy + x));
		circle.push_back(make_pair(cx + y, cy - x));
		circle.push_back(make_pair(cx - y, cy + x));
		circle.push_back(make_pair(cx - y, cy - x));
		x++;
	}

	return circle;
}

int main(void){
	initscr();
	noecho();
	start_color();

	init_pair(1, COLOR_BLACK, COLOR_RED);   
    	init_pair(2, COLOR_BLACK, COLOR_GREEN); 

    	attron(COLOR_PAIR(2));
	mvaddch(CX, CY,' ');
	attron(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));
	vector<pair<int, int>> circle = circlePoints(CX, CY, R);

	for(const auto& pixel : circle){
		mvaddch(pixel.first, pixel.second,' ');
	}
	getch();
	endwin();
	return 0;
}
