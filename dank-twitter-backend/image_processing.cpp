#include "image_processing.h"

Mat process_grayscale (const Mat & input) {
    Mat destination;
    
    resize(input, destination, Size(), 3, 3);
    
    return destination;
} 


string convert_to_blob (const Mat & input) {
    vector<unsigned char> data;
    
    imencode(".png", input, data);
    
    string body_data(data.begin(), data.end());
    
    return body_data;
}
