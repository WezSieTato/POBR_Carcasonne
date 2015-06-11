#include "paint.h"
#include "processing.h"

void drawRect(cv::Mat &mat, const cv::Rect &rect, const unsigned &r, const unsigned &g, const unsigned &b)
{
    cv::Mat_<cv::Vec3b> _I = mat;

    int w = 3;

    for( int i = rect.x; i < rect.x + rect.width; ++i){
        for(int j = i - w; j < i + w; ++j){
            int z = 2;

            _I(rect.y - z, j)[2] = _I( rect.y + rect.height, j)[2] = r;
            _I(rect.y - z, j)[1] = _I( rect.y + rect.height, j)[1] = g;
            _I(rect.y - z, j)[0] = _I( rect.y + rect.height, j)[0] = b;
        }
    }

    for( int i = rect.y; i < rect.y + rect.height; ++i){
        for(int j = i - w; j < i + w; ++j){
            int z = 4;
            _I(j, rect.x - z)[2] = _I(j, rect.x + rect.width)[2] = r;
            _I(j, rect.x - z)[1] = _I(j, rect.x + rect.width)[1] = g;
            _I(j, rect.x - z)[0] = _I(j, rect.x + rect.width)[0] = b;
        }
    }

    mat = _I;

}

cv::Mat whiteFrame(cv::Mat& I, const int& N){
    cv::Mat_<cv::Vec3b> _I = I;

    for( int i = 0; i < 0 + N; ++i){
        for(int j = 0; j < I.cols; ++j){
            setGrayScale(_I(i,j), 255);
        }
    }



    I = _I;
    return I;
}
