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

    std::vector< cv::Mat > vec;

//    vec.push_back(cv::imread("owce/o21.jpeg"));
//        vec.push_back(cv::imread("swinie/s23.jpeg"));

        vec.push_back(cv::imread("plytki/pociete/p1.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p2.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p3.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p4.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p5.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p6.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p7.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p8.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p9.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p10.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p11.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p12.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p13.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p14.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p15.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p16.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p17.jpeg"));
//        vec.push_back(cv::imread("plytki/pociete/p18.jpeg"));
//        vec.push_back(cv::imread("plytki/Skanuj8.jpeg"));
//        vec.push_back(cv::imread("plytki/Skanuj9.jpeg"));
//        vec.push_back(cv::imread("plytki/Skanuj10.jpeg"));
//        vec.push_back(cv::imread("plytki/Skanuj11.jpeg"));

    int z = 0;
    for(cv::Mat &image : vec){


        std::string name = std::to_string(z).append(" obraz ");
        cv::Mat prog = progowanie(image, 175, false);

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
                //                cv::imshow(std::string("Sheep ").append(std::to_string(i)), mat.first);
                drawRect(image, matInfo.box, 255, 0 ,0);
                recognized = true;
            }

            if(isPig(matInfo)){
                //                cv::imshow(std::string("Pig ").append(std::to_string(i)), mat.first);
                drawRect(image, matInfo.box, 0, 0 ,255);

                recognized = true;
            }


            if(recognized){
                std::cout << "Id: " << i << " MathInfo: " ;
                printMatInfo(matInfo);

            } else {
//                cv::imshow(std::string("Siema ").append(std::to_string(i)), mat.first);
//                std::cout << "Id: " << i << " MathInfo: " ;
//                printMatInfo(matInfo);
            }
        }

        //    cv::imshow("Filtrowany",prog);
        std::cout << "Rozpoznanie zakonczone\n";

        //    cv::imwrite("prog.jpeg", max);
        cv::namedWindow(name, cv::WINDOW_NORMAL);

        cv::imshow(name,image);
        z++;
    }
    cv::waitKey(-1);
    return 0;
}
