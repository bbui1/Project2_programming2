#include <iostream>
#include "ImageData.h"

int main() {

    // variable for test cases passed
    int tests = 0;

    // load all input files
    // load layer 1
    ImageData layer1("input/layer1.tga");
    // load layer2
    ImageData layer2("input/layer2.tga");
    // load car
    ImageData car("input/car.tga");
    // load pattern2
    ImageData pattern2("input/pattern2.tga");
    // load text
    ImageData text("input/text.tga");
    // load circles
    ImageData circles("input/circles.tga");
    // load pattern1
    ImageData pattern1("input/pattern1.tga");
    // load red layer
    ImageData layer_red("input/layer_red.tga");
    // load green layer
    ImageData layer_green("input/layer_green.tga");
    // load blue layer
    ImageData layer_blue("input/layer_blue.tga");
    // load text2
    ImageData text2("input/text2.tga");


    // part 1 multiply --------------------------------------------------------------------
    // multiply the image with layer1 and pattern2
    ImageData part1 = layer1 * pattern1;

    // output the new image
    part1.writePicture("output/part1.tga");

    cout << "Test #1...... ";
    if (part1.testOutput("examples/EXAMPLE_part1.tga")) tests++;

    // part 2 subtract --------------------------------------------------------------------
    // subtract
    ImageData part2 = car - layer2;

    // output the new image
    part2.writePicture("output/part2.tga");

    cout << "Test #2...... ";
    if (part2.testOutput("examples/EXAMPLE_part2.tga")) tests++;

    // part 3 multiply then screen --------------------------------------------------------
    // multiply the results
    ImageData temp3 = pattern2 * layer1;

    // screen the result
    ImageData part3 = text.screen(temp3);

    // output the new image
    part3.writePicture("output/part3.tga");

    cout << "Test #3...... ";
    if (part3.testOutput("examples/EXAMPLE_part3.tga")) tests++;

    // part 4 multiply then subtract ------------------------------------------------------
    // multiply
    ImageData temp4 = layer2 * circles;

    // subtract
    ImageData part4 = temp4 - pattern2;

    // output the new image
    part4.writePicture("output/part4.tga");

    cout << "Test #4...... ";
    if (part4.testOutput("examples/EXAMPLE_part4.tga")) tests++;

    // part 5 overlay ---------------------------------------------------------------------
    // call overlay
    ImageData part5 = layer1.overLay(pattern1);

    // output the new image
    part5.writePicture("output/part5.tga");

    cout << "Test #5...... ";
    if (part5.testOutput("examples/EXAMPLE_part5.tga")) tests++;

    // part 6 add 200 to the green channel ------------------------------------------------
    // add 200 green
    ImageData part6 = car.addGreen(200);

    // output the new image
    part6.writePicture("output/part6.tga");

    cout << "Test #6...... ";
    if (part6.testOutput("examples/EXAMPLE_part6.tga")) tests++;

    // part 7 multiply red channel by 4 and blue channel by 0 -----------------------------
    // multiply red channel by 4 and blue channel by 0
    // keep green by multiplying by 1
    ImageData part7 = car.multiplyChannels(4, 1, 0);

    // output the new image
    part7.writePicture("output/part7.tga");

    cout << "Test #7...... ";
    if (part7.testOutput("examples/EXAMPLE_part7.tga")) tests++;

    // part 8 split the channels from each color ------------------------------------------
    vector<ImageData> part8 = car.splitChannels();
    // split output
    ImageData part8_r = part8.at(0);
    ImageData part8_g = part8.at(1);
    ImageData part8_b = part8.at(2);

    // output each new image
    // red
    part8_r.writePicture("output/part8_r.tga");

    // green
    part8_g.writePicture("output/part8_g.tga");

    // blue
    part8_b.writePicture("output/part8_b.tga");

    cout << "Test #8...... ";
    if (part8_r.testOutput("examples/EXAMPLE_part8_r.tga")) tests++;
    cout << "Test #9...... ";
    if (part8_g.testOutput("examples/EXAMPLE_part8_g.tga")) tests++;
    cout << "Test #10..... ";
    if (part8_b.testOutput("examples/EXAMPLE_part8_b.tga")) tests++;

    // part 9 merge layers into one image --------------------------------------------------
    // merge into one output
    ImageData part9 = layer_red.mergeChannels(layer_green, layer_blue);

    // output the new image
    part9.writePicture("output/part9.tga");

    cout << "Test #11..... ";
    if (part9.testOutput("examples/EXAMPLE_part9.tga")) tests++;

    // part10 rotate 180 degrees -----------------------------------------------------------
    // flip the image
    ImageData part10 = text2.flipImage();

    // output the new image
    part10.writePicture("output/part10.tga");

    cout << "Test #12..... ";
    if (part10.testOutput("examples/EXAMPLE_part10.tga")) tests++;


    // tally up all the tests and output result
    cout << "Test results: " << tests << "/12" << endl;


    return 0;
}
