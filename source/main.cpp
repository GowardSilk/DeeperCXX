#include <Reactor.hpp>
#include <Shadow.hpp>

wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        str.at(i) -= 32;
    }
    return str;
}

int main() {
    wrd::Reactor_prcl reactor;
    wrd::Shadow_prcl<wString, wString> shadow;
    shadow.disconnect(reactor);
    shadow.append({
        {"ABC", "abc"},
        {"AbC", "abc"}
    });
    shadow.hijack(reactor_function);
    reactor.connect(wrd::_REACTOR_::IMPACT_v1_2A);
    reactor.hijack(reactor_function);
    reactor.override();
}
