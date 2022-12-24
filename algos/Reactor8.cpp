#include <Reactor.hpp>

bool contains(char& ch) {
    const char* punctuation = "!()-[]{};:'\",<>./?@#$%^&*_~";
    for(unsigned short i = 0; i < 28; i++) {
        if(punctuation[i] == ch) { 
            return true;
        }
    }
    return false;
}

/// @defgroup [C4 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
wString reactor_function(wString str) {
    wString new_str;
    for(char ch : str) {
        if(!contains(ch)) {
            new_str.push_back(ch);
        }
    }
    return new_str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::PLASIA_v0_2A);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}