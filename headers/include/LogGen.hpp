#ifndef LOG_GEN_HPP
#define LOG_GEN_HPP

#include <Log.hpp>
#include <Tester.hpp>
#include <random>

class LogGen {
	private:
		const char garbage_signs[22] = {
			'#', '@', '&', '%', '"', '*', '(', ')', '+', '/',
			(char)(0), 	//NULL
			(char)(1), 	//SOH
			(char)(2), 	//STX
			(char)(3), 	//ETX
			(char)(4), 	//ENQ
			(char)(5), 	//ACK
			(char)(6), 	//BEL
			(char)(7), 	//BS
			(char)(8), 	//HT
			(char)(9), 	//LF
			(char)(10), //VT
			(char)(11), //FF
		};
		char fill_gaps() {
			static std::random_device seeder;
			static std::mt19937 gen(seeder());
			std::uniform_int_distribution<int> dis(0, 22);
			return garbage_signs[dis(gen)];
		}
	public:
		//member data
		std::string m_encoded_text;
		std::string m_decoded_text;
		std::string m_addressee;
		std::string m_writer;
		std::vector<char> m_cm_arr;
		std::unordered_set<char> m_set;
		//!member data
		//constructor
		LogGen() = default;
		LogGen(std::string& text_to_encode) 
			: m_encoded_text(),
			  m_decoded_text(text_to_encode)
		{}
		LogGen(std::string& text_to_encode, std::string adrs, std::string wrtr)
			: m_encoded_text(),
			  m_decoded_text(text_to_encode),
			  m_addressee(adrs),
			  m_writer(wrtr)
		{}
		//!constructor
		void gen_cm_arr(std::string& str) {
			//save all characters in m_text (once)
			m_set.insert(str.at(0));
			for(unsigned i = 1; i < str.length(); i++) {
				if(m_set.find(str.at(i)) == std::end(m_set))
					m_set.insert(str.at(i));
			}
			//recreate the set into vector
			m_cm_arr = std::vector<char>(std::begin(m_set), std::end(m_set));
		}
		template<typename Func>
		void gen_cm_arr_custom(std::string& str, Func f) {
			//save all characters in m_text (once)
			m_set.insert(str.at(0));
			for(unsigned i = 1; i < str.length(); i++) {
				if(m_set.find(str.at(i)) == std::end(m_set))
					m_set.insert(str.at(i));
			}
			//recreate the set into vector
			uint_fast16_t i = 0;
			for(std::unordered_set<char>::iterator it = std::begin(m_set); it != std::end(m_set); ) {
				if(!f(i))
					m_cm_arr.push_back(fill_gaps());
				else {
					m_cm_arr.push_back(*it);
					//std::cout << "[" << i << "]:" << *it << std::endl;
					it++;
				}
				i++;
			}
			std::cout << std::endl;
		}
		template<typename Func>
		void encode_custom(bool ifGenText, Func next_valid) {
			if(ifGenText) {
				for(unsigned i = 0; i < m_decoded_text.length(); i++) {
					std::vector<char>::iterator it = std::find(
						std::begin(m_cm_arr),
						std::end(m_cm_arr),
						m_decoded_text.at(i)
					);
					m_encoded_text += std::to_string(
						std::distance(std::begin(m_cm_arr), it)
					) + ";";
					for(uint_fast16_t j = i; j < next_valid(i); j++) {
						m_encoded_text += std::to_string(
							std::distance(std::begin(m_cm_arr), std::find(
								std::begin(m_cm_arr),
								std::end(m_cm_arr),
								fill_gaps()
							))
						) + ";";
					}
				}
				std::cout << "[encoded_text]:" << m_encoded_text << std::endl;
			}
		}
		void encode() {
			//calculate the index position of 
			//every character of m_decoded_text/text_to_encode
			//this initial data will be then given to a user
			for(unsigned i = 0; i < m_decoded_text.length(); i++) {
				std::unordered_set<char>::iterator it = m_set.find(m_decoded_text[i]);
				m_encoded_text += std::to_string(
					std::distance(std::begin(m_set), it)
				) + ";";
			}
		}
		void write(const char* fileDest) {
			WriteIO writer(fileDest);
			if(!writer.good()) {
				std::cout << "[LogGen::write] Something went wrong with writer!\n";
			}
			//write m_encoded_text
			writer.write_string(m_encoded_text);
			//write addressee
			writer.write_string(m_addressee);
			//write writer
			writer.write_string(m_writer);
			//write size of vector
			writer.write_int(m_cm_arr.size());
			//char by char
			for(char c : m_cm_arr)
				writer.write_char(c);
			writer.flush();
			writer.close();
		}
		void read(const char* fileDest, wrd::Log& log) {
			ReadIO reader(fileDest);
			std::string e_text, adrs, wrtr;
			//read m_encoded_text
			reader.read_string(e_text);
			//read addressee
			reader.read_string(adrs);
			//read writer
			reader.read_string(wrtr);
			//read size of vector
			int size;
			reader.read_int(size);
			std::vector<char> v;
			for(int i = 0; i < size; i++) {
				char c;
				reader.read_char(c);
				v.push_back(c);
			}
			log = wrd::Log(v, adrs, wrtr, e_text);
		}
};

#endif //!LOG_GEN_HPP