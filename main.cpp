#include "processing.h"
#include "cutting.h"
#include "moments.h"

int main(int, char *[]) {
    std::cout << "Start ..." << std::endl;

    cv::Mat image = cv::imread("swinie/s21.jpeg");
    cv::Mat prog = progowanie(image, 175, false);

    prog = rankFilter(prog, 3, 8);
    prog = rankFilter(prog, 3, 8);
    prog = rankFilter(prog, 3, 0);
    prog = rankFilter(prog, 3, 0);
    prog = rankFilter(prog, 3, 0);

    MatBoxList list = partitionBoxes(prog);

    int i = 0;
    for( MatBox mat : list){
        int a = 3;
        if(i == a)
            cv::imshow(std::to_string(i), mat.first);
        if(i == a){
            MatInfo matInfo = doTheMath(mat);
            printMatInfo(matInfo);
        }
        ++i;

    }

//    cv::imshow("Filtrowany",prog);
//    cv::imshow("Normalny",image);

//    cv::imwrite("prog.jpeg", max);
//    cv::namedWindow("Max", cv::WINDOW_NORMAL);

    cv::waitKey(-1);
    return 0;
}
