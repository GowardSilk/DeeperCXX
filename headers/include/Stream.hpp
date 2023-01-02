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
        {"log", NULL},
        {"image", NULL},
        {"footage", NULL}
    }
};

class Stream {
    private:
        void refresh() {
            fs = std::ofstream("x.json", std::ios_base::trunc | std::ios_base::in);
            fs << jfile;
        }
        std::ofstream fs;
        json jfile;
    public:
        Stream() {
            fs = std::ofstream("x.json", std::ios_base::trunc | std::ios_base::in);
            jfile = DEFAULT_JSON_USR;
            fs << jfile;
        }
        ~Stream() {
            fs.close();
        }
        template<typename T, typename U>
        void write(T json_prop, U value_to_write) {
            try
            {
                jfile[1][json_prop] = value_to_write;
                refresh();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        void call_disconnect(bool b) {
            jfile[0]["is_shadowed"] = b;
            refresh();
        }
};