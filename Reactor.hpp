#ifndef REACTOR_HPP
#define REACTOR_HPP

#include "DeepMain.hpp"
// #include "json-develop/include/nlohmann/json.hpp"
// using json = nlohmann::json;

template<typename T1, typename T2>
class Shadow;

namespace wrd {
	wString read(std::ifstream& rf) {
		wString s;
		int len;
		rf.read(reinterpret_cast<char *>(&len), sizeof(int));
		char *buf = new char[len+1];
		rf.read(buf, len);
		buf[len] = '\0';
		s = buf;
		delete [] buf;
		return s;
	}
	enum class _REACTOR_ {
		R_DISCONNECTED, IMPACT_v1_2A, IMPACT_v0_9, TWINX_B, COLOSSUS_v0_5
	};
	class Reactor_prcl {
		protected:
			bool is_shadowed = false;
		private:
			//evaluation of (expressed in %) test success rate 
			float reactor_hack_success = 0.f;
			//reactor type
			wrd::_REACTOR_ reactor_type = _REACTOR_::R_DISCONNECTED;
			//
			template<typename T1, typename T2>
			friend class Shadow_prcl;
		public:
			//default constructor
			Reactor_prcl() = default;

			void hijack(wString (*func)(wString)) {
				switch (reactor_type)
				{
				//check if usr is connected
				case _REACTOR_::R_DISCONNECTED:
					std::cout << "not connected!\n";
					break;
				//R_IMPACT 0074 v1.2A
				case _REACTOR_::IMPACT_v1_2A:
				{
					std::ifstream rf("Reactor1.dat", std::ios::out | std::ios::binary);
					if(!rf) {
						std::cout << "cannot read file!\n";
						exit(EXIT_FAILURE);
					}

					//TEST_CASES
					for(unsigned i = 0; i < 10; i++) {
						//input for T function
						wString input = read(rf);
						//expected result
						wString expected = read(rf);

						if(expected == func(input))
							this->reactor_hack_success += 0.1f;

						if(!rf.good()) {
							std::cout << "error occurred at reading time!\n";
						}
					}
					//!TEST_CASES
				}	break;
				//R_IMPACT 0075 v0.9
				case _REACTOR_::IMPACT_v0_9: 
				{
					std::ifstream rf("Reactor2.dat", std::ios::out | std::ios::binary);
					if(!rf) {
						std::cout << "cannot read file!\n";
					}

					//TEST_CASES
					for(unsigned i = 0; i < 10; i++) {
						wString input = read(rf);

						wString expected = read(rf);

						if(expected == func(input))
							this->reactor_hack_success += 0.1f;

						if(!rf.good()) {
							std::cout << "error occurred at reading time!\n";
						}
					}
					//!TEST_CASES

					rf.close();
				}	break;
				//R_COLOSSUS 0081 v0.5
				case _REACTOR_::COLOSSUS_v0_5: {
					std::ifstream rf("Reactor4.dat", std::ios::out | std::ios::binary);
					if(!rf) {
						std::cout << "cannot read file!\n";
					}

					//TEST_CASES
					for(unsigned i = 0; i < 10; i++) {
						wString input = read(rf);

						wString expected = read(rf);

						if(expected == func(input))
							this->reactor_hack_success += 0.1f;

						if(!rf.good()) {
							std::cout << "error occurred at reading time!\n";
						}
					}
					//!TEST_CASES

					rf.close();
				}	break;
				}
			}
			void hijack(wString (*func)(sString)) {
				switch(this->reactor_type) {
					//check if usr is connected
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "not connected!\n";
						break;
					//R_TWINX 0012 beta
					case _REACTOR_::TWINX_B: {
						std::ifstream rf("Reactor3.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}

						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							sString s = {
								.key = read(rf),
								.value = read(rf)
							};

							wString expected = read(rf);

							if(expected == func(s))
								this->reactor_hack_success += 0.1f;

							if(!rf.good()) {
								std::cout << "error occurred at reading time!\n";
							}
						}
						//!TEST_CASES

						rf.close();
					}	break;
				}
			}
			void override() {
				std::cout << this->reactor_hack_success*100 << "%" << '\n';
				{
					// std::ofstream wf("example.json");
					// json j = {
					// 	{"errors", "erros"},
					// 	{"warnings", "warnings"}
					// };
					// wf << j;
				}
				return ;
			}
			void connect(wrd::_REACTOR_ rt) {
				this->reactor_type = rt;
				return ;
			}
	};
} //!namespace Warden

#endif