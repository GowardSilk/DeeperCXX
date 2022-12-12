#include "../Reactor.hpp"

wString reactor_function(wString str, int shift) {
    wString ans;
    if(shift >= 26) { shift %= 26; }
    std::for_each(std::begin(str), std::end(str), [&](char c) {
        if(c - shift < 'a') {
            int i;
            for(i = shift; c >= 'a'; c--, i--);
            c = 'z' - i;
        }
        else { c -= shift; }
        ans.push_back(c);
    });
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::MARSCHAL_v014);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}