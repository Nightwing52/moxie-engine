#include "MoxieCore/Input.h"

Input::Input() {
}

int Input::Poll(void) {
        SDL_PollEvent(&event);
        if (event.type == SDL_KEYDOWN)
                return event.key.keysym.sym;
        return event.type;
}
