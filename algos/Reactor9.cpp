#include <Reactor.hpp>

/// @defgroup [D1 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
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