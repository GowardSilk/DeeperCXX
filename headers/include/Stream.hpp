#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

const json DEFAULT_JSON_USR = {
    {
        {"is_shadowed", false}
    },
    {
        {"success", NULL},
        {"errors", NULL},
        {"log", NULL}
    }
};

class Stream {
    private:
        std::fstream fs;
        json jfile;
    public:
        Stream() {
            fs = std::fstream("default.json", std::ios_base::trunc | std::ios_base::in);
            jfile = DEFAULT_JSON_USR;
            fs << jfile;
            std::cout << jfile << std::endl;
        }
        template<typename T, typename U>
        void write(T json_prop, U value_to_write) {
            try
            {
                jfile[json_prop] = value_to_write;
                fs << jfile;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
};