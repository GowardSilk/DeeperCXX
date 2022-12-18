#include "../Reactor.hpp"

wString reactor_function(wString str) {
    wString new_str;
    for(const char& ch : str) {
        if(ch < 48 || ch > 57) {
            new_str.push_back(ch);
        }
    }
    return new_str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::BEAMX_v093);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}