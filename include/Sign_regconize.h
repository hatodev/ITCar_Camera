#ifndef _SIGN_REGCONIZE_H
#define _SIGN_REGCONIZE_H


#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <opencv2/objdetect.hpp>
#include "opencv2/cudaobjdetect.hpp"

using namespace cv;
using namespace std;
using namespace cv::ml;
using namespace cv::cuda;

#define VIDEO_NAME "/home/tan/Downloads/Bandicam2/bandicam 2018-03-26 19-33-41-781.mp4"     //Link video
#define Hblue_max 120           //Ngưỡng H xanh max
#define Hblue_min 100           //Ngưỡng H xanh min
#define Sblue_max 94            //Ngưỡng S xanh max
#define Sblue_min 64            //Ngưỡng S xanh min
#define Vblue_max 255           //Ngưỡng V xanh max
#define Vblue_min 64            //Ngưỡng B xanh min
#define ratio_max 1.2           //Tỉ lệ cạnh hình chữ nhật bao quanh lớn nhất để lọc hình học
#define ratio_min 0.75           //Tỉ lệ cạnh hình chữ nhật bao quanh nhỏ nhất để lọc hình học
#define MIN_OBJECT_AREA_SIGN 100            //Kích thước đối tượng tối thiểu nghi ngờ là biển báo
#define MAX_OBJECT_AREA_SIGN 1536000          //Kích thước đối tượng tối đa nghi ngờ là biển báo
#define MIN_OBJECT_COLOR_SEG 100             //Kích thước đối tượng tối thiểu nghi ngờ là biển báo sau khi phân đoạn màu
#define MAX_OBJECT_COLOR_SEG 1536000           //Kích thước đối tượng tối đa nghi ngờ là biển báo sau khi phân đoạn màu
#define max_vertices 7                      //Số đỉnh tối thiểu để là hình tròn hoặc Ellipse
#define ratio_area_max 0.45//0.42         //0.15              //Độ lệch max của tỉ lệ diện tích của hình ellipse
#define ratio_shape_max 0.4//0.38        //0.24              //Độ lệch max của tỉ lệ hình học của hình ellipse
#define E_max 1.2                     //1                 //Độ lệch tâm max của ellipse
#define E_min 0.9                 //0.968             //Độ lệch tâm min của ellipse

void Erosion(Mat src, Mat &dst, int erosion_elem, int erosion_size);
void Dilation(Mat src, Mat &dst, int dilation_elem, int dilation_size );
void BinaryOpening(Mat src, Mat &dst, int erosion_size, int dilation_size);
void BinaryClosing(Mat src, Mat &dst, int dilation_size, int erosion_size);
void removeSmallOject(Mat src, Mat &dst, int min_size, int max_size);
void blueColorSegmentation(Mat src, Mat &dst);
void signAreaDetection(Mat src, Mat &dst);
void areaAndRatio(Mat src, Mat &dst);
bool detectShape(Mat src, Rect rect);
void detectEllipse(Mat src, Mat &dst);
int trafficBlueSignRecognize(Mat src, Rect rect);
int recognizeBlueSign(Mat &src, Mat& dst);


#endif
