#include <iostream>
#include <filesystem>
#include <zip.h>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <set>
#include <fstream>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    
    if (argc < 3 || argc > 4 ) {
        std::cerr << "Usage: " << argv[0] << " <path-to-jar> <path-to-payload.class>\n";
        return 1;
    };

    if (argc == 4) {
        fs::path wordlist = argv[4];
        if (wordlist.extension() != ".txt") {
            std::cerr << "Given Wordlist Path has to be a .txt file";
        };

    } else {
        std::ifstream wordlist("wordlist.txt");
        if (!file) {

            std::cerr << "Could not open wordlist.txt\n";
            return 1;

        }

    }

    
    fs::path jar_path = argv[1];

    if(!fs::is_regular_file(jar_path)) {
        std::cerr << jar_path << "Is not a File \n";
        return 1;
    };

    fs::path payload = argv[2];

    if(!fs::is_regular_file(payload)) {

        std::cerr << payload << "Is not a File \n";
        return 1;

    };

    int err;
    zip_t *jar; 
    
    if ((jar = zip_open(jar_path.string().c_str(), 0, &err )) == NULL ) {
        zip_error_t error;
        zip_error_init_with_code(&error, err);
        fprintf(stderr, "%s: cannot open zip archive '%s': %s\n",
	        argv[0], jar_path.string().c_str(), zip_error_strerror(&error));
        zip_error_fini(&error);
        return -1;
    };


    int index = zip_name_locate(jar, "fabric.mod.json", ZIP_FL_ENC_GUESS);

    if (index < 0) throw std::runtime_error("couldnt find fabric.mod.json");

    zip_stat_t st; 

    zip_stat_init(&st);

    if (zip_stat(jar, "fabric.mod.json", 0, &st) != 0 || !(st.valid & ZIP_STAT_SIZE)) {
        throw std::runtime_error("stat failed at fabric.mod.json");
    }


    std::string buf(static_cast<size_t>(st.size), '\0');

    zip_file_t *zf = zip_fopen(jar, "fabric.mod.json", 0);
    if (!zf) throw std::runtime_error("opening fabric.mod.json failed");
    
    zip_int64_t n = zip_fread(zf, buf.data(), buf.size());
    zip_fclose(zf);

    if ( n < 0 ) throw std::runtime_error("reading fabric.mod.json failed");

    buf.resize(static_cast<size_t>(n));

    std::cout << buf << "test print uwu\n";

    zip_discard(jar);
    return 0; 



}

std::string insert_entrypoint(mod_json, class_name, worldlist_txt_path) {

    


}


std::set<std::string> list_folders(zip_t* archive) {

    std::set<std::string> folders;
    zip_int64_t n = zip_get_num_entries(archive, 0);

    for(int i = 0, i < n , i++) {
        std::string name = zip_get_name(archive, i, 0)
        folders.insert(name);
    };

    return folders

};

std::vector<std::string> load_list(const std::string& path) {


    std::vector<std::string> words;
    std::ifstream file(path);
    std::string line;

    while(std::getline(file, line)) {
        if(!line.empty()) words.push_back(line);
    }

    return words; 

}

std::string generate_path(std::vector<std::string>& wordlist,
                          const std::unordered_set<std::string>& present_entries) {

    
    std::vector<std::string> result;

    for(const auto& w: wordlist) {

        if(present_entries.count(w) == 0) {
            result.push_back(w);
        }

    }

    static std::mt19937 gen(std::random_device{}());   // seeded once
    std::uniform_int_distribution<int> dist(1, 5);  // min and max both included
    int num_of_subfolders= dist(gen);

    std::string generated_path;

    

    

}

