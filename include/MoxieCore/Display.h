#ifndef DISPLAY_H
#define DISPLAY_H

#include "SDL.h"
#include "GL/glew.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Display {
        public:
                Display(const string &title, const int width, const int height,
                                const bool fullscreen);
                bool CheckExtensions(const string glVersion,
                                const string extensions);
                void Clear(void);
                void Swap(void);
                ~Display();
        private:
                SDL_Window *gWin;
                SDL_GLContext gCont;
};

#endif
