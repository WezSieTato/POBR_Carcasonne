#include "processing.h"
#include "cutting.h"
#include "moments.h"
#include "recognizing.h"
#include "paint.h"
#include <iostream>

#define presentation false
#define show( a, b )     (a) = b; \
    if(presentation){ \
    std::cout << "Zrobione\n"; \
cv::waitKey(-1); \
cv::imshow("Filtrowany",(a));}


int main(int, char *[]) {
    std::cout << "Start ..." << std::endl;

    cv::Mat image = cv::imread("plytki/pociete/p1.jpeg");
    cv::Mat prog = progowanie(image, 175, false);

    cv::imshow("Normalny",image);
    if(presentation){
        std::cout << "Zrobione\n"; \
        cv::imshow("Filtrowany",prog);
        cv::waitKey(-1);
    }

    show(prog, rankFilter(prog, 3, 8));
    show(prog, rankFilter(prog, 3, 8));
    show(prog, rankFilter(prog, 3, 0));
    show(prog, rankFilter(prog, 3, 0));
    show(prog, rankFilter(prog, 3, 0));

    MatBoxList list = partitionBoxes(prog);

    int i = 0;
    for( MatBox mat : list){            
        ++i;
        MatInfo matInfo = doTheMath(mat);
        bool recognized = false;
        if(isSheep(matInfo)){
//            cv::imshow(std::string("Sheep ").append(std::to_string(i)), mat.first);
            drawRect(image, matInfo.box, 255, 0 ,0);
            recognized = true;
        }

        if(isPig(matInfo)){
//            cv::imshow(std::string("Pig ").append(std::to_string(i)), mat.first);
            drawRect(image, matInfo.box, 0, 0 ,255);

            recognized = true;
        }

        if(recognized){
            std::cout << "Id: " << i << " MathInfo: " ;
            printMatInfo(matInfo);

        }
    }

    cv::imshow("Filtrowany",prog);
    std::cout << "Rozpoznanie zakonczone\n";

//    cv::imwrite("prog.jpeg", max);
//    cv::namedWindow("Max", cv::WINDOW_NORMAL);

    cv::imshow("Normalny",image);


    cv::waitKey(-1);
    return 0;
}
