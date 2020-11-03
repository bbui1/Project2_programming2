#include <iostream>
#include "ImageData.h"


int main() {

    int part = 0;
    cout << "Which part of the project would you like to run? " << endl;
    cin >> part;

    // load all input files
    // load layer 1
    ifstream inFile("input/layer1.tga",ios_base::binary);
    ImageData layer1(inFile);

    // load layer2
    ifstream inFile2("input/layer2.tga",ios_base::binary);
    ImageData layer2(inFile2);

    // load car
    ifstream  inFile3("input/car.tga",ios_base::binary);
    ImageData car(inFile3);

    // load pattern2
    ifstream inFile4("input/pattern2.tga",ios_base::binary);
    ImageData pattern2(inFile4);

    // load text
    ifstream inFile5("input/text.tga",ios_base::binary);
    ImageData text(inFile5);

    // load circles
    ifstream inFile6("input/circles.tga",ios_base::binary);
    ImageData circles(inFile6);

    // load pattern1
    ifstream inFile7("input/pattern1.tga",ios_base::binary);
    ImageData pattern1(inFile7);

    // load red layer
    ifstream inFile8("input/layer_red.tga",ios::binary);
    ImageData layer_red(inFile8);

    // load green layer
    ifstream inFile9("input/layer_green.tga",ios::binary);
    ImageData layer_green(inFile9);

    // load blue layer
    ifstream inFile10("input/layer_blue.tga",ios::binary);
    ImageData layer_blue(inFile10);

    // load text2
    ifstream inFile11("input/text2.tga",ios_base::binary);
    ImageData text2(inFile11);

    int tests = 0;


    // multiply
    if (part == 1) {
        // multiply the image with layer1 and pattern2
        ImageData part1 = layer1*pattern1;

        // output the new image
        ofstream outFile("output/part1.tga", ios_base::binary);
        part1.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #1...... ";
        if (part1.testOutput("examples/EXAMPLE_part1.tga")) tests++;
    }

    // subtract
    else if (part == 2) {
        // subtract
        ImageData part2 = car - layer2;

        // output the new image
        ofstream outFile("output/part2.tga", ios_base::binary);
        part2.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #2...... ";
        if (part2.testOutput("examples/EXAMPLE_part2.tga")) tests++;
    }

    // multiply then screen
    else if (part == 3) {

        // multiply the results
        ImageData temp3 = pattern2*layer1;

        // screen the result
        ImageData part3 = text.screen(temp3);

        // output the new image
        ofstream outFile("output/part3.tga", ios_base::binary);
        part3.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #3...... ";
        if (part3.testOutput("examples/EXAMPLE_part3.tga")) tests++;
    }

    // multiply then subtract
    else if (part == 4) {
        // multiply
        ImageData temp4 = layer2*circles;

        // subtract
        ImageData part4 = temp4 - pattern2;

        // output the new image
        ofstream outFile("output/part4.tga", ios_base::binary);
        part4.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #4...... ";
        if (part4.testOutput("examples/EXAMPLE_part4.tga")) tests++;
    }

    // overlay
    else if (part == 5) {
        // call overlay
        ImageData part5 = layer1.overLay(pattern1);

        // output the new image
        ofstream outFile("output/part5.tga", ios_base::binary);
        part5.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #5...... ";
        if (part5.testOutput("examples/EXAMPLE_part5.tga")) tests++;
    }

    // add 200 to the green channel
    else if (part == 6) {
        // add 200 green
        ImageData part6 = car.addGreen(200);

        // output the new image
        ofstream outFile("output/part6.tga", ios_base::binary);
        part6.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #6...... ";
        if (part6.testOutput("examples/EXAMPLE_part6.tga")) tests++;
    }

    // multiply red channel by 4 and blue channel by 0
    else if (part == 7) {
        // multiply red channel by 4 and blue channel by 0
        // keep green by multiplying by 1
        ImageData part7 = car.multiplyChannels(4,1,0);

        // output the new image
        ofstream outFile("output/part7.tga", ios_base::binary);
        part7.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #7...... ";
        if (part7.testOutput("examples/EXAMPLE_part7.tga")) tests++;
    }

    // split the channels from each color
    else if (part == 8) {
        vector<ImageData> part8 = car.splitChannels();

        // split output
        ImageData part8_r = part8.at(0);
        ImageData part8_g = part8.at(1);
        ImageData part8_b = part8.at(2);

        // output each new image
        // red
        ofstream outFileR("output/part8_r.tga", ios_base::binary);
        part8_r.writePicture(outFileR);

        // output each new image
        // green
        ofstream outFileG("output/part8_g.tga", ios_base::binary);
        part8_g.writePicture(outFileG);

        // output each new image
        // blue
        ofstream outFileB("output/part8_b.tga", ios_base::binary);
        part8_b.writePicture(outFileB);

        // compare the image to the given example
        cout << "Test #8...... ";
        if (part8_r.testOutput("examples/EXAMPLE_part8_r.tga")) tests++;

        cout << "Test #9...... ";
        if (part8_g.testOutput("examples/EXAMPLE_part8_g.tga")) tests++;

        cout << "Test #10..... ";
        if (part8_b.testOutput("examples/EXAMPLE_part8_b.tga")) tests++;

    }

    // merge layers into one image
    else if (part == 9) {
        // merge into one output
        ImageData part9 = layer_red.mergeChannels(layer_green,layer_blue);

        // output the new image
        ofstream outFile("output/part9.tga", ios_base::binary);
        part9.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #11..... ";
        if (part9.testOutput("examples/EXAMPLE_part9.tga")) tests++;
    }

    // rotate 180 degrees
    else if (part == 10) {
        // flip the image
        ImageData part10 = text2.flipImage();

        // output the new image
        ofstream outFile("output/part10.tga", ios_base::binary);
        part10.writePicture(outFile);

        // compare the image to the given example
        cout << "Test #12..... ";
        if (part10.testOutput("examples/EXAMPLE_part10.tga")) tests++;
    }


    cout << tests << endl;

    return 0;
}
