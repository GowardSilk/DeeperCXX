#include <DEEP_EYE.hpp>

/*!
 * @defgroup I_g4 Pixel Rotation 2nd series
 * @ingroup I_g 
 * @brief "Pixel Rotated" Images of 2nd series have merged encodings of Row Rotation and Col Rotation
 * @code {.cpp}
 * Image encoeded {
 *  PIXEL1, PIXEL2, PIXEL3, PIXEL4
 *  PIXEL5, PIXEL6, PIXEL7, PIXEL8
 * } 
 * => [ALGORITHM] => 
 * Image decoded {
 *  PIXEL4, PIXEL7, PIXEL2, PIXEL5
 *  PIXEL8, PIXEL3, PIXEL6, PIXEL1
 * }
 * @endcode
*/

int main() {
}