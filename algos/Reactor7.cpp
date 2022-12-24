#include <Reactor.hpp>

/// @defgroup [C3 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
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