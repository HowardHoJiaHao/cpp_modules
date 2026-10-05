#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Incorrect output argument count: filename, s1, s2 " << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (filename.empty() || s1.empty())
    {
        std::cout << "Empty parameter: filename or s1. " << std::endl;
        return 1;
    }

    std::ifstream inputfile(filename.c_str());
    if (!inputfile.is_open())
    {
        std::cout << "Unable to open input file " << std::endl;
        return 1;
    }

    std::ofstream outputfile((filename + ".replace").c_str());
    if (!outputfile.is_open())
    {
        inputfile.close();
        std::cout << "Unable to open output file " << std::endl;
        return 1;
    }

    std::string line;
    size_t pos;
    while (std::getline(inputfile, line))
    {
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos = line.find(s1, pos + s2.length());
        }
        outputfile << line << std::endl;
    }
    // inputfile.close();
    // outputfile.close();
    return 0;
}