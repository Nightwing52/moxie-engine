#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

class Input {
        public:
                Input();
                int Poll(void);
        private:
                SDL_Event event;
};

#endif
