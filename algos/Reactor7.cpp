#include "../Reactor.hpp"

bool reactor_function(wString str) {
    for(unsigned i = 0; i < str.length()/2; i++) {
        if(str[i] != str[str.length()-1-i])
            return false;
    }
    return true;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::JAMBO_v1_9);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}