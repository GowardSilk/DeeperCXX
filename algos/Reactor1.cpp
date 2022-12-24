#include <Reactor.hpp>

/// @defgroup [A1 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        str.at(i) -= 32;
    }
    return str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::IMPACT_v1_2A);
    reactor.hijack(reactor_function);
    reactor.override();

}