#ifndef PUG2_H 
#define PUG2_H
#include <utility> 
class Pug2 {
	private:
		int pug2x;
		int pug2y;
		int pug2Width; 
		int pug2Height; 
	public: 
		void init() {	
			pug2x = 700; 
			pug2y = 170;
			pug2Width = 40; 
			pug2Height = 300; 
		}
		std::pair <int, int> PugInit() {
			return std::make_pair(pug2x, pug2y); 
		}
		std::pair <int, int> PugObj_init() {
			return std::make_pair(pug2Width, pug2Height); 
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
