#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <SDL2/SDL.h>
#include "src/pug1.h"
#include "src/pug2.h"
#include "src/pong.h"
#define WIDTH 800
#define HEIGHT 600
#define UP -30 
#define DOWN 30 
#define CONSTENDIS 800 

// Movement {Bool return value}
bool checkCollis(int x1, int y1, int w, int h, int x2, int y2, int w2, int h2) {
	return(x1 < x2 + w2 && 
		x1 + w > x2 &&
		y1 < y2 + h2 &&
		y1 + h > y2);
}

void Aimove(int& x1, int& y1, int x2, int y2, int speeds) {
	double dalataY = y2 - y1;	
	double dalataX = x2 - x1;
	float distances = std::abs(sqrt(dalataY * dalataY + dalataX * dalataX));  
	
	if (distances <= CONSTENDIS) {
		if (y2 > 0) {
			y1 += static_cast<int>(round((y2 - y1) * speeds / distances));		
		}	
		if (y2 < 0) {	
			y1 -= static_cast<int>(round((y2 - y1) * speeds / distances));		
		}
	}
}
int main() {
	SDL_Window* window; 
	SDL_Renderer* renderer; 
	
	// Init PUNG { 1 } 	
	Pug1 pug1Object; 
	pug1Object.init(); 
	std::pair<int, int> xyPair = pug1Object.PugInit(); 
	std::pair <int, int> WHPair = pug1Object.PugObj_init(); 
	
	// Init PUNG { 2 } 	
	Pug2 pug2Object; 
	pug2Object.init(); 
	std::pair <int, int> xyPair2 = pug2Object.PugInit(); 		
	std::pair <int, int> WHPair2 = pug1Object.PugObj_init(); 
	
	// Init PONG { [] }	
	Pong pong; 
	pong.Init(); 
	std::pair<int, int> getPair = pong.get_POSPONG(); 
	std::pair<int, int> getPairPONG = pong.get_POSOBJ(); 
	
	// Varibales for POUG { 1 }	
	int x1 = xyPair.first;	
	int y1 = xyPair.second; 
	int w = WHPair.first; 
	int h = WHPair.second; 
	
	// Varibalesfor POUG { 2 }	
	int x2 = xyPair2.first;	
	int y2 = xyPair2.second; 	
	int w2 = WHPair.first; 
	int h2 = WHPair.second; 
		
	// Varibalesfor PONG { [] }	
		
	//int xVelosity = 10; 
	//int yVelosity = 10; 	
	float angle = 30.0f;
	float speeds = 8.0f;  
	int xpong = getPair.first; 
	int ypong = getPair.second;
	int wpong = getPairPONG.first; 
	int hpong = getPairPONG.second; 

	SDL_Init(SDL_INIT_EVERYTHING);  
	window = SDL_CreateWindow(
			NULL, 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED,
			WIDTH, 
			HEIGHT, 
			0
			);
	renderer = SDL_CreateRenderer(window, -1, 0); 

	
	SDL_Event event; 
	while (true) { 	
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return -1; 	
			}

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL); 
			if (currentKeyStates[SDL_SCANCODE_UP]) { 
				y1 += UP; 	
			} 
			if (currentKeyStates[SDL_SCANCODE_DOWN]) {  
				y1 += DOWN; 	
			}
        
		}
			
				
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
		SDL_RenderClear(renderer);	
	

		
		xpong += static_cast<int>(speeds * std::cos(angle * M_PI / 180.0f)); 						
		ypong += static_cast<int>(speeds * std::sin(angle * M_PI / 180.0f)); 				
		if (ypong <= 0 || ypong + hpong >= HEIGHT) {						
			// yVelosity =  -yVelosity;
			angle = -angle; 
		}	
			
		if (xpong <= 0 || xpong + wpong >= WIDHT) {				
			xpong = WIDTH / 2;
			ypong = HEIGHT / 2; 	
		}

		SDL_Rect pig = {xpong, ypong, wpong, hpong}; 		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
		SDL_RenderFillRect(renderer, &pig);	

		if (checkCollis(x1, y1, 20, 300, xpong, ypong, wpong, hpong) == true) {
				
			angle = 180.0f - angle; 	
		}	

		SDL_Rect pug1 = {x1, y1, 20, 200}; 		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
		SDL_RenderFillRect(renderer, &pug1);
		
		
		Aimove(x2, y2, xpong, ypong, 50); 
		if (checkCollis(x2, y2, 20, 300, xpong, ypong, wpong, hpong) == true) {	
			angle = 180.0f - angle;	
		}		

		SDL_Rect pug2 = {x2, y2, 20, 200}; 		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
		SDL_RenderFillRect(renderer, &pug2);


		SDL_RenderPresent(renderer);	
		SDL_Delay(16); 

	}
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window);


	return 0; 
}
