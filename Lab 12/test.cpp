#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream outfile("output.txt", std::ios::binary);
    std::string name = "Rezwan";

    std::size_t size = name.size();
    outfile.write(reinterpret_cast<char*>(&size), sizeof(size));
    outfile.write(name.c_str(), size);

    name.clear();
    outfile.close();
    size = 0;

    std::ifstream infile("output.txt", std::ios::binary);
    infile.read(reinterpret_cast<char*>(&size), sizeof(size));
    name.resize(size, '\0');
    infile.read(&name[0], size);

    std::cout << name << std::endl;
    return 0;
}