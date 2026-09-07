#include <iostream>
#include <filesystem>
#include <zip.h>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    if (argc != 3 ) {

        std::cerr << "Usage: " << argv[0] << "<path-to-jar> " << "path-to-payload.class> \n";

        return 1;

    }

    
    fs::path jar = argv[1];

    if(!fs::is_regular_file(jar)) {

        std::cerr << jar << "Is not a File \n"
    }

    fs::path payload = argv[2];

    fs::path payload = argv[2];

        if(!fs::is_regular_file(payload)) {

        std::cerr << payload << "Is not a File \n"
    }

    


    return 0; 



}