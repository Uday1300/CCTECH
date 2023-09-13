#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class FileReader {
public:
    FileReader(const std::string& file_path) : file_path_(file_path) {}

    std::vector<std::pair<std::string, std::string>> readData() {
        std::vector<std::pair<std::string, std::string>> data;
        std::ifstream file(file_path_);

        if (!file.is_open()) {
            std::cerr << "Error: Unable to open the file." << std::endl;
            return data;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string value1, value2;
            if (std::getline(iss, value1, ',') && std::getline(iss, value2)) {
                data.emplace_back(value1, value2);
            } else {
                std::cerr << "Ignored line: " << line << ". Expected format: value1, value2" << std::endl;
            }
        }

        file.close();
        return data;
    }
private:
    std::string file_path_;
};

int main() {

    FileReader reader("C:\\Users\\HP\\OneDrive\\Desktop\\HTML.txt");
    std::vector<std::pair<std::string, std::string>> data = reader.readData();

    for (const auto& entry : data) {
        std::cout << "Value1: " << entry.first << ", Value2: " << entry.second << std::endl;
    }

    return 0;
}
