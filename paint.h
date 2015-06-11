#ifndef PAINT_H
#define PAINT_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

void drawRect(cv::Mat &mat, const cv::Rect &rect, const unsigned &r, const unsigned &g, const unsigned &b);
cv::Mat whiteFrame(cv::Mat& I, const int& N);

#endif // PAINT_H
