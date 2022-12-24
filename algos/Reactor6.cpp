#include <Reactor.hpp>

/// @defgroup [C2 sector] REACTOR
/// \brief create an algorithm (via function)
/// that takes string as param and returns
/// all string of all characters upper-cased
/// @param str consists of only lower-cased characters
/// @return expected return type consits of upper-cases characters
///
int reactor_function(wString str) {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int final_count = 0;
    for(char ch : str) {
        for(unsigned short i = 0; i < 5; i++) {
            if(vowels[i] == ch) {
                final_count++;
                break;
            }
        }
    }
    return final_count;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::BUCKLAND_EX);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}