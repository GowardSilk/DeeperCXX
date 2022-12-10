#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Reactor.hpp"
#include "Terminal.hpp"

namespace wrd {
    template<typename T1, typename T2>
    class Shadow_prcl : public Terminal_prcl, public Reactor_prcl {
        private:
            //member data
            std::vector<std::pair<T1, T2>> m__test_cases;
            //!member data
        public:
            //default constructor
            Shadow_prcl() = default;
            //initializer constructor
            Shadow_prcl(initializer_list_t<T1, T2> init_l) 
                : m__test_cases(init_l) {}
            //functions
            void disconnect(wrd::Terminal_prcl& terminal) {
                terminal.is_shadowed = true;
            }
            void disconnect(wrd::Reactor_prcl& reactor) {
                reactor.is_shadowed = true;
            }
            //
            template<typename F>
            void hijack(F func) {
                int it = 0;
                for(const auto& t : this->m__test_cases) {
                    if(t.first != func(t.second)) {
                        std::cout << "[SHADOW]: test failed!\n";
                        std::cout << "function arguments: " << t.second << "\n";
                        std::cout << "expected function output: " << t.first << "\n";
                        std::cout << "but received: " << func(t.second) << "\n";
                    }
                    else
                        it++;
                }
                printf("out of %d tests, %d passed\n", this->m__test_cases.size(), it);
            }
            //
            void append(initializer_list_t<T1, T2> init_l) {
                this->m__test_cases.insert(std::end(this->m__test_cases), std::begin(init_l), std::end(init_l));
            }
            //!functions
    };
} //!wrd

#endif //!SHADOW_HPP