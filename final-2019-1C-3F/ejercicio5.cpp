/*Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo*/

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>

int main(int, char*[]) try {
	SDL sdl(SDL_INIT_VIDEO);
	Window window("libSDL2pp demo: sprites", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
	Renderer render(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	render.SetDrawBlendMode(SDL_BLENDMODE_BLEND);

	while (1) {
		// Process input
		SDL_Event event;
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q)))
				return 0;

		// Clear screen
		render.SetDrawColor(0, 32, 32);
		render.Clear();

        // render.DrawRect(x1,y1,x2,y2);
        // render.FillRect(x1,y1,x2,y2);
        render.SetDrawColor(255, 0, 0); // RGB rojo
		render.DrawLine(10, 10, 450, 450);
        render.DrawLine(450, 10, 10, 450);

		render.Present();
		// Frame limiter
		SDL_Delay(1);
	}

	return 0;
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}