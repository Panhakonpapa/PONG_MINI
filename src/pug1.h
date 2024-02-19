#ifndef PUG_H 
#define PUG_H
#include <utility> 
class Pug1 {
	private:
		int pugx;
		int pugy;
		int pugWidth; 
		int pugHeight; 
	public: 
		void init() {	
			pugx = 70; 
			pugy = 170;
			pugWidth = 40; 
			pugHeight = 300; 
		}
		std::pair <int, int> PugInit() {
			return std::make_pair(pugx, pugy); 
		}
		std::pair <int, int> PugObj_init() {
			return std::make_pair(pugWidth, pugHeight); 
		}
// call 
// Pug.init()
// x, y = Pug.PugObj_init();
// x.first; 
// y.secand;
// h.first; 
// w.secand; 
// renderer = Pug.pugx(), Pug.pugy(), w.secand, h.first
//
}; 

#endif 
