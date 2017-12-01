#include "image_processing.h"

Mat process_grayscale (const Mat & input) {
    Mat destination;
    
    resize(input, destination, Size(), 3, 3);
    
    return destination;
}
