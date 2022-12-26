#ifndef LOG_GEN_HPP
#define LOG_GEN_HPP

#include <unordered_set>
#include <vector>
#include <string>
#include <Log.hpp>

class LogGen {
	public:
		//member data
		std::string m_encoded_text;
		std::string m_decoded_text;
		std::vector<char> m_cm_arr;
		std::unordered_set<char> m_set;
		//!member data
		//constructor
		LogGen() = default;
		LogGen(std::string text_to_encode, bool ifGen = false, bool ifEncode = false) 
			: m_encoded_text(),
			  m_decoded_text(text_to_encode)
		{
			if(ifGen)
				gen_cm_arr(text_to_encode);
			if(ifEncode)
				encode(text_to_encode);
		}
		//!constructor
		void gen_cm_arr(std::string str) {
			//save all characters in m_text (once)
			m_set.insert(str.at(0));
			for(unsigned i = 1; i < str.length(); i++) {
				if(m_set.find(str.at(i)) == std::end(m_set))
					m_set.insert(str.at(i));
			}
			//recreate the set into vector
			m_cm_arr = std::vector<char>(m_set.size());
			for (auto it = std::begin(m_set); it != std::end(m_set); it++) {
				m_cm_arr.push_back(*it);
			}
		}
		void encode(std::string text_to_encode) {
			//calculate the index position of 
			//every character of m_decoded_text/text_to_encode
			//this initial data will be given to a user
			for(unsigned i = 0; i < text_to_encode.length(); i++) {
				std::unordered_set<char>::iterator it = m_set.find(text_to_encode.at(i));
				m_encoded_text += std::to_string(
					std::distance(std::begin(m_set), it)
				) + ";";
			}
		}
		template<typename Func>
		void encode(std::string text_to_encode, Func encoding_algo) {
			//calculate the index position of 
			//every character of m_text
			//this initial data will be given to a user
			for(unsigned i = 0; i < text_to_encode.length(); i++) {
				std::unordered_set<char>::iterator it = m_set.find(text_to_encode.at(i));
				m_encoded_text += encoding_algo(it);
			}
		}
		wrd::Log log_parse() {
			wrd::Log log;
			log.setLetterMap(m_cm_arr);
			log.getMessage().setText(m_encoded_text);
			return log;
		}
};

#endif //!LOG_GEN_HPP