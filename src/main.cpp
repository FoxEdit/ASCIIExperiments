#include <fstream>
#include <iostream>

#include "../lib/EasyBMP/EasyBMP.h"

int main() {
    BMP img;
    const std::string colorDepth = "@#:. ";

    std::string inputFile, outputFolder;
    std::cin >> inputFile >> outputFolder;
    if (!img.ReadFromFile(inputFile.c_str())) return 1;

    std::ofstream fileStream(outputFolder);
    fileStream.open(outputFolder + "/output.txt", std::ifstream::trunc);

    if (!fileStream.is_open()) {
        std::cout << "Error! Unable to open the file.";
        return 1;
    }

    int characterPos;
    std::string writeText;
    for (int y = 0; y < img.TellHeight() - 1; ++y) {
        for (int x = 0; x < img.TellWidth() - 1; ++x) {
            characterPos = static_cast<int>(img.GetPixel(x, y).Red) / 51;
            writeText.append(1, colorDepth[characterPos]);
        }
        writeText.append(1, '\n');
    }
    fileStream.write(writeText.c_str(), writeText.length());

    return 0;
}