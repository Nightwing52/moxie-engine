#ifndef CHATTERBOX_H
#define CHATTERBOX_H

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Chatter {
        string text;
        int priority;
};

class ChatterBox {
        public:
                static ChatterBox* instance(void);
                void Post(const char *message, int priority);
        private:
                ChatterBox();
                static ChatterBox *s_instance;
                stack<Chatter> chatStack;
};

#endif
