#ifndef PONG_H
#define PONG_H
#include <utility> 
#define WIDHT 800
#define HEIGHT 600
class Pong {
	private: 
		int x; 
		int y; 
		int width; 
		int height; 
	public: 
		void Init() {	
			width = 50; 
			height = 50;	
			x = WIDHT / 2 - width / 2 ;		
			y = HEIGHT / 2 - height / 2; 	
		}
		std::pair<int, int> get_POSPONG() {
			return std::make_pair(x, y); 
		}
		std::pair<int, int> get_POSOBJ() {
			return std::make_pair(width, height);
		}
}; 
#endif 
