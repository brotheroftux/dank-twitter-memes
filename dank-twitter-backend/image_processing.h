#ifndef image_processing_h
#define image_processing_h

#include <iostream>
#include <cstdio>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"
#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#pragma clang diagnostic pop

using namespace std;
using namespace cv;

void process_grayscale (string filename);

#endif /* image_processing_h */
