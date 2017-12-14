#ifndef image_processing_h
#define image_processing_h

#include <iostream>
#include <cstdio>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"
#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#pragma clang diagnostic pop

using namespace std;
using namespace cv;

Mat process_grayscale (const Mat & input);
string convert_to_blob (const Mat & input);

#endif /* image_processing_h */
