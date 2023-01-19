#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Reactor.hpp"
#include "Terminal.hpp"

namespace wrd {
    template<typename T1, typename T2>
    class Shadow_prcl : public Terminal_prcl, public Reactor_prcl {
        private:
            //string-parsing functions
            std::string _TO_STRING(const triplet<int>& tr) {
                return "{" + 
                std::to_string(tr._triplet_unit_1) + ","
                + std::to_string(tr._triplet_unit_2) + ","
                + std::to_string(tr._triplet_unit_3) + "}";
            }
            std::string _TO_STRING(const TripletContainer<int>& tr_con) {
                std::string final = "{";
                for(const triplet<int>& tr : tr_con)
                    final += "\n" + _TO_STRING(tr);
                return final + "\n}";
            }
            template<typename T>
            std::string _TO_STRING(const Vector2<T>& pos) {
                return "{" + std::to_string(pos.x) + "," + std::to_string(pos.y) + "}";
            }
            //!string-parsing functions
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
                json s_json = SHADOW_JSON;
                json failed_test_json;
                for(const auto& t : this->m__test_cases) {
                    if(t.first != func(t.second)) {
                        failed_test_json.push_back({
                            {"expected", _TO_STRING(t.first)},
                            {"actual", _TO_STRING(t.second)}
                        });
                    }
                    else
                        it++;
                }
                s_json["failed_tests"] = failed_test_json;
                s_json["n_of_tests"] = this->m__test_cases.size();
                s_json["passed"] = it;
                JSON_stream.call_disconnect(s_json);
            }
            //
            void append(initializer_list_t<T1, T2> init_l) {
                this->m__test_cases.insert(std::end(this->m__test_cases), std::begin(init_l), std::end(init_l));
            }
            //!functions
    };
} //!wrd

#endif //!SHADOW_HPP