#ifndef REACTOR_HPP
#define REACTOR_HPP

#include "DeepMain.hpp"
#include "Tester.hpp"
// #include "json-develop/include/nlohmann/json.hpp"
// using json = nlohmann::json;

template<typename T1, typename T2>
class Shadow;

namespace wrd {
	enum class _REACTOR_ {
		R_DISCONNECTED,
        IMPACT_v1_2A,   //A sectors
        IMPACT_v0_9, TWINX_B, COLOSSUS_v0_5,    //B sectors
        MARSCHAL_v014, BUCKLAND_EX, JAMBO_v1_9, PLASIA_v0_2A,   //C sectors
        BEAMX_v093, CITADEL_v2_2B, PYRO_ULT, ERUPT_v0_2, HADES_v0_45    //D sectors
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
					case _REACTOR_::IMPACT_v1_2A: {
						ReadIO reader("Reactor1.dat");
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							//input for T function
							wString input;
							reader.read_string(input);
							//expected result
							wString expected;
							reader.read_string(expected);

							if(expected == func(input))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
					case _REACTOR_::IMPACT_v0_9: {
						ReadIO reader("Reactor2.dat");
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							wString input;
							reader.read_string(input);

							wString expected;
							reader.read_string(expected);

							if(expected == func(input))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
					case _REACTOR_::COLOSSUS_v0_5: {
						ReadIO reader("Reactor4.dat");
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							wString input;
							reader.read_string(input);

							wString expected;
							reader.read_string(expected);

							if(expected == func(input))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
					case _REACTOR_::PLASIA_v0_2A: {
						ReadIO reader("Reactor8.dat");
						//TEST_CASES
						for(unsigned short i = 0; i < 10; i++) {
							wString input, expected;
							reader.read_string(input);
							reader.read_string(expected);
							if(func(input) == expected)
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
					case _REACTOR_::BEAMX_v093: {
						ReadIO reader("Reactor9.dat");
						//TEST_CASES
						for(unsigned short i = 0; i < 10; i++) {
							wString input, expected;
							reader.read_string(input);
							reader.read_string(expected);
							if(func(input) == expected)
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
					case _REACTOR_::PYRO_ULT: {
						ReadIO reader("Reactor11.dat");
						//TEST_CASES
						//!TEST_CASES
						reader.close();
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
						ReadIO reader("Reactor3.dat");
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							wString key;
							wString value;
							reader.read_string(value);
							reader.read_string(key);

							sString s = {
								.key = key,
								.value = value
							};
							wString expected;
							reader.read_string(expected);

							if(expected == func(s))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
				}
			}
			void hijack(wString (*func)(wString, int)) {
				switch (this->reactor_type)
				{
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "not connected!\n";
						break;
					case _REACTOR_::MARSCHAL_v014: {
						ReadIO reader("Reactor5.dat");
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							wString input1;
							reader.read_string(input1);
							int input2;
							reader.read_int(input2);
							wString expected;
							reader.read_string(expected);

							if(expected == func(input1, input2))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES

						reader.close();
					}	break;
					default:
						break;
				}
			}
			void hijack(int (*func)(wString)) {
				switch(this->reactor_type) {
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "Not connected!\n";
						break;
					case _REACTOR_::BUCKLAND_EX: {
						ReadIO reader("Reactor6.dat");
						//TEST_CASES
						for(unsigned short i = 0; i < 10; i++) {
							wString input;
							reader.read_string(input);
							int expected;
							reader.read_int(expected);
							if(expected == func(input))
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
				}
			}
			void hijack(bool (*func)(wString)) {
				switch(this->reactor_type) {
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "Not connected!\n";
						break;
					case _REACTOR_::JAMBO_v1_9: {
						ReadIO reader("Reactor7.dat");
						//TEST_CASES
						for(unsigned short i = 0; i < 10; i++) {
							wString input;
							reader.read_string(input);
							bool expected;
							reader.read_bool(expected);
							if(func(input) == expected)
								this->reactor_hack_success += 0.1f;
						}
						//!TEST_CASES
						reader.close();
					}	break;
				}
			}
			void hijack(bool (*func)(wString, wString)) {
				switch(this->reactor_type) {
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "Not connected!\n";
						break;
					case _REACTOR_::CITADEL_v2_2B: {
						ReadIO reader("Reactor10.dat");
						//TEST_CASES
						//!TEST_CASES
						reader.close();
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