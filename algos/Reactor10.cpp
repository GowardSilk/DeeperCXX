#include <Reactor.hpp>
#include <regex>

wString reactor_function(sString str) {
    wString key = str.key;
    std::regex pattern("([a-zA-Z])-([a-zA-Z]);");
    std::unordered_map<char, char> map;

    for(std::sregex_iterator i = std::sregex_iterator(key.begin(), key.end(), pattern);
        i != std::sregex_iterator();
        ++i) {
        std::smatch match = *i;
        map.insert(std::make_pair(match[1].str()[0], match[2].str()[0]));
    }

    wString final;
    for(const auto& ch : str.value)
        final.push_back(map[ch]);
    return final;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::CITADEL_v2_2B);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}