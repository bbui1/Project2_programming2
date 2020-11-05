
#include "ImageData.h"

// BIG THREE
// copy constructor
ImageData::ImageData(const ImageData &image) {
    this->operator=(image);
}

// copy assignment operator
ImageData &ImageData::operator=(const ImageData &image) {
    idLength = image.idLength;
    colorMapType = image.colorMapDepth;
    dataTypeCode = image.dataTypeCode;
    colorMapOrigin = image.colorMapOrigin;
    colorMapLength = image.colorMapLength;
    colorMapDepth = image.colorMapDepth;
    xOrigin = image.xOrigin;
    yOrigin = image.yOrigin;
    width = image.width;
    height = image.height;
    bitsPerPixel = image.bitsPerPixel;
    imageDescriptor = image.imageDescriptor;

    imageLength = image.imageLength;

    for (unsigned int ii = 0; ii < imageLength; ii++) {
        picture.push_back(image.picture.at(ii));
    }
    return *this;
}

// destructor
ImageData::~ImageData() {
    picture.clear();
}

// read file
ImageData::ImageData(const string& fileName) {
    ifstream inFile(fileName,ios_base::binary);
    this->readPicture(inFile);
}

// save the header information from the input file
void ImageData::readHeader(ifstream &inFile) {
    inFile.read(&idLength, sizeof(idLength));
    inFile.read(&colorMapType, sizeof(colorMapType));
    inFile.read((char*)&dataTypeCode, sizeof(dataTypeCode));
    inFile.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
    inFile.read((char*)&colorMapLength, sizeof(colorMapLength));
    inFile.read(&colorMapDepth, sizeof(colorMapDepth));
    inFile.read((char*)&xOrigin, sizeof(xOrigin));
    inFile.read((char*)&yOrigin, sizeof(yOrigin));
    inFile.read((char*)&width, sizeof(width));
    inFile.read((char*)&height, sizeof(height));
    inFile.read(&bitsPerPixel, sizeof(bitsPerPixel));
    inFile.read(&imageDescriptor, sizeof(imageDescriptor));

    imageLength = width*height;
}

// read a single pixel
void ImageData::readPixel(ifstream &inFile) {
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;

    inFile.read((char*) &blue,sizeof(blue));
    inFile.read((char*) &green,sizeof(green));
    inFile.read((char*) &red,sizeof(red));

    picture.push_back(Pixel(red,green,blue));
}

// read all of the pixels
void ImageData::readAllPixels(ifstream &inFile) {
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        readPixel(inFile);
    }
}

// read the entire file
void ImageData::readPicture(ifstream &inFile) {
    readHeader(inFile);
    readAllPixels(inFile);
}

void ImageData::writePicture(const string& fileName) {
    ofstream outFile(fileName, ios_base::binary);
    outFile.write(&idLength, sizeof(idLength));
    outFile.write(&colorMapType, sizeof(colorMapType));
    outFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));
    outFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
    outFile.write((char*)&colorMapLength, sizeof(colorMapLength));
    outFile.write(&colorMapDepth, sizeof(colorMapDepth));
    outFile.write((char*)&xOrigin, sizeof(xOrigin));
    outFile.write((char*)&yOrigin, sizeof(yOrigin));
    outFile.write((char*)&width, sizeof(width));
    outFile.write((char*)&height, sizeof(height));
    outFile.write(&bitsPerPixel, sizeof(bitsPerPixel));
    outFile.write(&imageDescriptor, sizeof(imageDescriptor));

    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel currentPixel = picture.at(ii);
        outFile.write((char*) &currentPixel.blue, sizeof(currentPixel.blue));
        outFile.write((char*) &currentPixel.green, sizeof(currentPixel.green));
        outFile.write((char*) &currentPixel.red, sizeof(currentPixel.red));
    }
}

// the top layer is the one calling the function
ImageData ImageData::multiply(ImageData &layer) {
    ImageData output = layer;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = picture.at(ii);
        Pixel& B = layer.picture.at(ii);
        Pixel& C = output.picture.at(ii);

        int red = (int) round(((float) A.red*(float) B.red)/255.0f);
        int green = (int) round(((float) A.green*(float) B.green)/255.0f);
        int blue =  (int) round(((float) A.blue*(float) B.blue)/255.0f);

        C = Pixel(red,green,blue);
    }
    return output;
}

ImageData ImageData::operator*(ImageData &layer) {
    return this->multiply(layer);
}

// the bottom layer is the one calling the function
ImageData ImageData::subtract(ImageData &layer) {
    ImageData output = layer;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = picture.at(ii);
        Pixel& B = layer.picture.at(ii);
        Pixel& C = output.picture.at(ii);

        int red = A.red - B.red;
        if (red < 0) red = 0;

        int green = A.green - B.green;
        if (green < 0) green = 0;

        int blue = A.blue - B.blue;
        if (blue < 0) blue = 0;

        C = Pixel(red,green,blue);
    }
    return output;
}

ImageData ImageData::operator-(ImageData &layer) {
    return this->subtract(layer);
}

ImageData ImageData::screen(ImageData &layer) {
    ImageData output = layer;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = picture.at(ii);
        Pixel& B = layer.picture.at(ii);
        Pixel& C = output.picture.at(ii);

        int red = 255 - (int) round(((float) (255-A.red)*(float) (255-B.red))/255.0f);
        int green = 255 - (int) round(((float) (255-A.green)*(float) (255-B.green))/255.0f);
        int blue = 255 - (int) round(((float) (255-A.blue)*(float) (255-B.blue))/255.0f);

        C = Pixel(red,green,blue);
    }
    return output;
}

// check to see if the first 200 pixels are the same
bool ImageData::comparePictures(const string& fileName) {
    bool truthValue = true;

    //comparing to example file
    ifstream example(fileName,ios_base::binary);
    ImageData image;
    image.readPicture(example);

    for (unsigned int ii = 0; ii < imageLength; ii++){
        Pixel& pixel1 = picture.at(ii);
        Pixel& pixel2 = image.picture.at(ii);

        if (pixel1.red - pixel2.red != 0) {
            cout << "red " << ii << endl;
            cout << (int) pixel1.red << " " << (int) pixel2.red << endl;
            truthValue = false;
        }
        if (pixel1.green - pixel2.green != 0) {
            cout << "green " << ii << endl;
            cout << (int) pixel1.green << " " << (int) pixel2.green << endl;
            truthValue = false;
        }
        if (pixel1.blue - pixel2.blue != 0) {
            cout << "blue " << ii << endl;
            cout << (int) pixel1.blue << " " << (int) pixel2.blue << endl;
            truthValue = false;
        }
    }
    return truthValue;
}

// top layer will call the bottom layer
ImageData ImageData::overLay(ImageData &layer) {
    ImageData output = layer;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = picture.at(ii);
        Pixel& B = layer.picture.at(ii);
        Pixel& C = output.picture.at(ii);

//        double gray = sqrt(3*pow(128,2));
//        double tonalValue = B.getTone();

        float gray = 0.5f;
        float tonalValue = ((float)B.red + (float)B.green + (float)B.blue)/(255*3);

        if (tonalValue <= gray) {
            // basically copying multiply but noe we're going to multiply by 2
            int red = (int) (round(2*((float) A.red*(float) B.red)/255.0f));
            if (red > 255) red = 255;

            int green = (int) (round(2*((float) A.green*(float) B.green)/255.0f));
            if (green > 255) green = 255;

            int blue = (int) (round(2*((float) A.blue*(float) B.blue)/255.0f));
            if (blue > 255) blue = 255;

            C = Pixel(red,green,blue);

            // else case we run something similar to screen but multiply it by 2
        } else {
            int red = 255 - (int) (round(2*((float) (255-A.red)*(float) (255-B.red))/255.0f));
            if (red < 0) red = 0;

            int green = 255 - (int) (round(2*((float) (255-A.green)*(float) (255-B.green))/255.0f));
            if (green < 0) green = 0;

            int blue = 255 - (int) (round(2*((float) (255-A.blue)*(float) (255-B.blue))/255.0f));
            if (blue < 0) blue = 0;

            C = Pixel(red,green,blue);
        }

    }

    // cout << "Red at 2441: " << (int) output.picture.at(2441).red << endl;

    return output;
}

// add 200 to the green value in pixel and cap at 255
ImageData ImageData::addGreen(int value) {
    ImageData output = *this;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = output.picture.at(ii);
        int green = A.green + value;
        if (green > 255) green = 255;

        A = Pixel(A.red,green,A.blue);
    }
    return output;
}

// multiply red by a specified value
ImageData ImageData::multiplyChannels(int redValue, int greenValue, int blueValue) {

    ImageData output = *this;

    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = output.picture.at(ii);

        int red = A.red*redValue;
        if (red > 255) red = 255;

        int green = A.green*greenValue;
        if (green > 255) green = 255;

        int blue = A.blue*blueValue;
        if (blue > 255) blue = 255;

        A = Pixel(red,green,blue);
    }
    return output;
}

vector<ImageData> ImageData::splitChannels() {
    vector<ImageData> output;

    // create 3 different ImageData variables for each channel
    ImageData redChannel = *this;
    ImageData greenChannel = *this;
    ImageData blueChannel = *this;
    for (unsigned int ii = 0; ii < imageLength; ii++) {

        // grab corresponding pixel for each color channel
        Pixel& R = redChannel.picture.at(ii);
        Pixel& G = greenChannel.picture.at(ii);
        Pixel& B = blueChannel.picture.at(ii);

        // negate the other colors
        R = Pixel(R.red,R.red,R.red);
        G = Pixel(G.green,G.green,G.green);
        B = Pixel(B.blue,B.blue,B.blue);

    }

    // push it all back to the output
    output.push_back(redChannel);
    output.push_back(greenChannel);
    output.push_back(blueChannel);
    return output;
}

// red channel calls it
ImageData ImageData::mergeChannels(ImageData& greenChannel, ImageData& blueChannel) {
    ImageData output = greenChannel;
    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& R = picture.at(ii);
        Pixel& G = greenChannel.picture.at(ii);
        Pixel& B = blueChannel.picture.at(ii);
        Pixel& C = output.picture.at(ii);

        C = Pixel(R.red,G.green,B.blue);
    }

    return output;
}

ImageData ImageData::flipImage() {
    ImageData output = *this;

    for (unsigned int ii = 0; ii < imageLength; ii++) {
        Pixel& A = picture.at(imageLength-ii-1);
        Pixel& B = output.picture.at(ii);

        B = A;
    }

    return output;
}

bool ImageData::testOutput(const string &fileName) {
    if (this->comparePictures(fileName)) {
        cout << "Passed!" << endl;
        return true;
    } else {
        cout << "Failed!" << endl;
        return false;
    }
}

ImageData::Pixel::Pixel(unsigned char _red, unsigned char _green, unsigned char _blue) {
    red = _red;
    green = _green;
    blue = _blue;
}

// used for getting the tonal value of the background
double ImageData::Pixel::getTone() const {
    return sqrt(pow(red,2) + pow(green,2) + pow(blue,2));
}
