#include "image_processing.h"

void process_grayscale (string filename) {
    Mat image = imread(filename, IMREAD_GRAYSCALE), destination;
    
    remove(filename.c_str());
    
    resize(image, destination, Size(), 3, 3);
    
    try {
        imwrite(filename + ".tif", destination);
    } catch (Exception & ex) {
        cout << "Failed to convert an image to grayscale." << endl;
        cout << ex.what() << endl;
    }
}
