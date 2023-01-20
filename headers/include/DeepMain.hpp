#ifndef DEEPMAIN_HPP
#define DEEPMAIN_HPP

// #define _HAS_AUTO_PTR_ETC 1 //https://stackoverflow.com/questions/48882439/how-to-restore-auto-ptr-in-visual-studio-c17

//include paths
//	STL
	#include <iostream>
	#include <iomanip>
	#include <string>
	#include <cmath>
	#include <vector>
	#include <functional>
	#include <type_traits>
	#include <unordered_map>
	#include <unordered_set>
	#include <algorithm>
	#include <numeric>
	#include <array>
	#include <memory>
	#include <iterator>
	#include <cstddef>
	#include <execution>
//	CUSTOM
	#include "Stream.hpp"
//!include paths

#ifndef STREAM
#define STREAM
inline Stream JSON_stream = Stream();
#endif

//definitions
#define DEEPER 0 //main return value

using json = nlohmann::json;
using symbol = char; //symbol type for CodeMatrix
using access_key = const char*; //access_key for logs -> DeepEye
using wString = std::string; //weak string

struct sString { //strong string
	wString key;
	wString value;
};

template<typename T1, typename T2>
using initializer_list_t = std::initializer_list<std::pair<T1, T2>>;

//triplet
template<typename T> struct triplet;

template<typename S>
std::ostream& operator<<(std::ostream& out, const triplet<S>& tr);

template <typename T>
struct triplet { //terminal triplet code
	T _triplet_unit_1;
	T _triplet_unit_2;
	T _triplet_unit_3;
public:
	triplet() {
		this->_triplet_unit_1 = NULL;
		this->_triplet_unit_2 = NULL;
		this->_triplet_unit_3 = NULL;
	}
	triplet(T t1, T t2, T t3) {
		this->_triplet_unit_1 = t1;
		this->_triplet_unit_2 = t2;
		this->_triplet_unit_3 = t3;
	}
	template<typename S>
	friend std::ostream& operator<<(std::ostream& out, const triplet<S>& tr);
	friend bool operator==(const triplet<T>& lhs, const triplet<T>& rhs){
		return 	lhs._triplet_unit_1 == rhs._triplet_unit_1 ||
				lhs._triplet_unit_2 == rhs._triplet_unit_2 ||
				lhs._triplet_unit_3 == rhs._triplet_unit_3;
	}
	friend bool operator!=(const triplet<T>& lhs, const triplet<T>& rhs){
		return lhs._triplet_unit_1 != rhs._triplet_unit_1 ||
			   lhs._triplet_unit_2 != rhs._triplet_unit_2 ||
			   lhs._triplet_unit_3 != rhs._triplet_unit_3;
	}
	friend bool operator <(const triplet<T>& lhs, const triplet<T>& rhs){
		return 	(lhs._triplet_unit_1 + lhs._triplet_unit_2 + lhs._triplet_unit_3)
				<
				(rhs._triplet_unit_1 + rhs._triplet_unit_2 + rhs._triplet_unit_3);
	}
	friend bool operator >(const triplet<T>& lhs, const triplet<T>& rhs){
		return 	(lhs._triplet_unit_1 + lhs._triplet_unit_2 + lhs._triplet_unit_3)
				>
				(rhs._triplet_unit_1 + rhs._triplet_unit_2 + rhs._triplet_unit_3);
	}
	triplet<T>& operator =(const triplet<int>& t){
		_triplet_unit_1 = t._triplet_unit_1;
		_triplet_unit_2 = t._triplet_unit_2;
		_triplet_unit_3 = t._triplet_unit_3;
		return *this;
	}
	triplet<T>& operator =(const triplet<wString>& t){
		_triplet_unit_1 = t._triplet_unit_1;
		_triplet_unit_2 = t._triplet_unit_2;
		_triplet_unit_3 = t._triplet_unit_3;
		return *this;
	}
};
template<typename S>
std::ostream& operator<<(std::ostream& out, const triplet<S>& tr) {
	out << "{" << tr._triplet_unit_1 << ","
		<< tr._triplet_unit_2 << ","
		<< tr._triplet_unit_3 << "}";
	return out;
}
triplet<int> to_int(triplet<wString> tr) {
	return triplet<int>(
		std::stoi(tr._triplet_unit_1),
		std::stoi(tr._triplet_unit_2),
		std::stoi(tr._triplet_unit_3)
	);
}
triplet<wString> to_wString(triplet<int> tr) {
	return triplet<wString>(
		std::to_string(tr._triplet_unit_1),
		std::to_string(tr._triplet_unit_2),
		std::to_string(tr._triplet_unit_3)
	);
}
//!triplet

// template<class T>
// struct std::hash
// {
// std::size_t operator()(const triplet<T>& tr) const
// {
// 	// Compute individual hash values for first,
// 	// second and third and combine them using XOR
// 	// and bit shifting:

// 	return ((std::hash<triplet<T>>()(tr._triplet_unit_1)
// 			^ (std::hash<triplet<T>>()(tr._triplet_unit_2) << 1)) >> 1)
// 			^ (std::hash<triplet<T>>()(tr._triplet_unit_3) << 1);
// }
//   };

template <typename T>
class TripletContainer : public std::vector<triplet<T>> {
	public:
		//constructors
		TripletContainer() : std::vector<triplet<T>>() {} //default
		TripletContainer(std::vector<triplet<T>>& tr) : std::vector<triplet<T>>(tr) {} //by vector - DEPRECATED
		TripletContainer(std::initializer_list<triplet<T>> init_l) : std::vector<triplet<T>>(init_l) {} //preferred way
		template<typename Iterator>
		TripletContainer(Iterator first, Iterator last) : std::vector<triplet<T>>(first, last) {} //
		TripletContainer(std::size_t sz) : std::vector<triplet<T>>(sz) {}
		TripletContainer(std::size_t sz, triplet<T> val) : std::vector<triplet<T>>(sz, val) {} //
		void push_back(triplet<T> tr) {
			std::vector<triplet<T>>::push_back(tr);
		}
		void push_back(T t1, T t2, T t3) {
			std::vector<triplet<T>>::push_back(
				(triplet<T>) {
					._triplet_unit_1=t1,
            		._triplet_unit_2=t2,
            		._triplet_unit_3=t3
				}
			);
		}
		template<typename Iterator, class U>
		U sum_at(U& init_val, Iterator from, Iterator to) {
			for (; from != to; ++from) {
				init_val += from->_triplet_unit_1 + from->_triplet_unit_2 + from->_triplet_unit_3;
			}
			return init_val;
		}
		template<typename Iterator, class U>
		U sum_at(U init_val, Iterator from) {
			sum_at(init_val, from, from+1);
		}
}; 

template<typename S>
std::ostream& operator<<(std::ostream& out, const TripletContainer<S>& tr_con) {
	for(const triplet<S> tr : tr_con) {
		out << "{" << tr._triplet_unit_1 << ","
		<< tr._triplet_unit_2 << ","
		<< tr._triplet_unit_3 << "}";
	}
	return out;
}
//!triplet container

template<typename T>
class Vector2 {
	public:
		//default constructor
		Vector2() {}
		//constructor with 2 parameters (X, Y)
		Vector2(T x, T y) {
			this->x = x;
			this->y = y;
		}
		//member data
		T x;
		T y;
		//operators
};
//define most common use cases
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<std::size_t> Vector2sz;
typedef Vector2<float> Vector2f;

class CodeMatrix {
	private:
		std::vector<symbol> cm_arr;
	public:
		//default constructor
		CodeMatrix() = default;
		CodeMatrix(std::vector<symbol> v) : cm_arr(v) {}
		//destructor
		~CodeMatrix() {}
		//functions
		symbol get_symbol(unsigned pos) { return cm_arr.at(pos); }
		unsigned get_size() { return cm_arr.size(); }
		void push(symbol s) { cm_arr.push_back(s); }
		//iterator f
		std::vector<symbol>::iterator begin() { return std::begin(cm_arr); }
		std::vector<symbol>::iterator end() { return std::end(cm_arr); }
}; //!CodeMatrix

//!definitions

#endif