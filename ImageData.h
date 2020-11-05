#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#pragma once

using namespace std;

struct ImageData {
    struct Pixel{
        unsigned char red;
        unsigned char green;
        unsigned char blue;

        double getTone() const;

    public:
        Pixel(unsigned char _red, unsigned char _green, unsigned char _blue);
    };
        // instance variables
        char idLength;
        char colorMapType;
        char dataTypeCode;
        short colorMapOrigin;
        short colorMapLength;
        char colorMapDepth;
        short xOrigin;
        short yOrigin;
        short width;
        short height;
        char bitsPerPixel;
        char imageDescriptor;

        // vector to hold all the pixels
        vector<Pixel> picture;

        // integer to hold how big the width x height is
        unsigned int imageLength;

        // normal constructor but we can leave it blank hence = default
        ImageData() = default;

        // constructor to automatically load an image given the file name
        explicit ImageData(const string& fileName);

        // ============ Big Three ================
        ImageData(const ImageData& image);
        ImageData& operator=(const ImageData& image);
        ~ImageData();

        // helper functions
        void readHeader(ifstream &inFile);
        void readPixel(ifstream &inFile);
        void readAllPixels(ifstream &inFile);

        // file functions
        void readPicture(ifstream &inFile);
        void writePicture(const string& fileName);

        // part 1
        ImageData multiply(ImageData& layer);
        ImageData operator*(ImageData& layer);

        // part 2
        ImageData subtract(ImageData& layer);
        ImageData operator-(ImageData& layer);

        // part 3
        ImageData screen(ImageData& layer);

        // part 5
        ImageData overLay(ImageData& layer);

        // part 6
        ImageData addGreen(int value);

        // part 7
        ImageData multiplyChannels(int redValue, int greenValue, int blueValue);

        // part 8
        vector<ImageData> splitChannels();

        // part 9
        ImageData mergeChannels(ImageData& greenChannel, ImageData& blueChannel);

        // part 10
        ImageData flipImage();

        // test functions
        bool comparePictures(const string& fileName);
        bool testOutput(const string& fileName);
};


