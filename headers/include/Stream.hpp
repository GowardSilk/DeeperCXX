#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

const json DEFAULT_JSON_USR = {
    {
        {
            "is_shadowed", {}
        }
    },
    {
        {"success", NULL},
        {"log", NULL},
        {"image", NULL},
        {"footage", NULL},
    }
};

const json SHADOW_JSON = {
    {"failed_tests", NULL},
    {"n_of_tests", NULL},
    {"passed", NULL}
};

const json SUCCESS_JSON = {
    {"level", NULL},
    {"type", NULL},
    {"success", NULL}
};

const json FOOTAGE_JSON = {
    {"folderDest", NULL},
    {"timeDuration", NULL}
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
        void call_disconnect(json json_file) {
            this->jfile[0]["is_shadowed"].push_back(json_file);
            refresh();
        }
};