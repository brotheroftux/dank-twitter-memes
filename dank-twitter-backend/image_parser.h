#ifndef image_parser_h
#define image_parser_h

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <vector>
#include <cstddef>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"
#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/text/ocr.hpp>
#pragma clang diagnostic pop

#include "cpp-httplib-mixin.h"

#include <url.hpp>

using namespace std;
using namespace cv;
using namespace cv::text;

Mat fetch_image (const string & url);
string parse_image (Mat image);

#endif /* image_parser_h */
