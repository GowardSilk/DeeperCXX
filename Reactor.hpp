#ifndef REACTOR_HPP
#define REACTOR_HPP

#include "DeepMain.hpp"
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
					case _REACTOR_::IMPACT_v0_9: {
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
					case _REACTOR_::PLASIA_v0_2A: {
						std::ifstream rf("Reactor8.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
						//!TEST_CASES
						rf.close();
					}	break;
					case _REACTOR_::BEAMX_v093: {
						std::ifstream rf("Reactor9.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
						//!TEST_CASES
						rf.close();
					}	break;
					case _REACTOR_::PYRO_ULT: {
						std::ifstream rf("Reactor11.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
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
			void hijack(wString (*func)(wString, int)) {
				switch (this->reactor_type)
				{
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "not connected!\n";
						break;
					case _REACTOR_::MARSCHAL_v014: {
						std::ifstream rf("Reactor5.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
						for(unsigned i = 0; i < 10; i++) {
							wString input1 = read(rf);
							int input2;
							rf.read((char *) &input2, sizeof(int));
							wString expected = read(rf);

							if(expected == func(input1, input2))
								this->reactor_hack_success += 0.1f;

							if(!rf.good()) {
								std::cout << "error occurred at reading time!\n";
							}
						}
						//!TEST_CASES

						rf.close();
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
						std::ifstream rf("Reactor5.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
						//!TEST_CASES
						rf.close();
					}	break;
				}
			}
			void hijack(bool (*func)(wString)) {
				switch(this->reactor_type) {
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "Not connected!\n";
						break;
					case _REACTOR_::JAMBO_v1_9: {
						std::ifstream rf("Reactor11.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
						//!TEST_CASES
						rf.close();
					}	break;
				}
			}
			void hijack(bool (*func)(wString, wString)) {
				switch(this->reactor_type) {
					case _REACTOR_::R_DISCONNECTED:
						std::cout << "Not connected!\n";
						break;
					case _REACTOR_::CITADEL_v2_2B: {
						std::ifstream rf("Reactor10.dat", std::ios::out | std::ios::binary);
						if(!rf) {
							std::cout << "cannot read file!\n";
						}
						//TEST_CASES
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