#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using std::vector;
int main(){
    cv::Mat img=cv::imread("Target.png");
    cv::Mat gray;
    cv::cvtColor(img,gray,cv::COLOR_BGR2GRAY);
    cv::Mat binary;
    cv::threshold(gray,binary,160,255,cv::THRESH_BINARY);
    vector<vector<cv::Point>> side;
    cv::findContours(binary,side,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    vector<cv::Rect> lightrects;
    int imgheight=img.rows;
    int ymin=imgheight*0.2;
    int ymax=imgheight*0.8;
    for (const vector<cv::Point> & shape:side){
        cv::Rect rect=cv::boundingRect(shape);
        if (rect.width>5 && rect.height>30){
            if (rect.y>=ymin&&(rect.y+rect.height)<=ymax){
                lightrects.push_back(rect);
            }
        }
    }
    if (lightrects.size()>=2){
        std::sort(lightrects.begin(),lightrects.end(),[](cv::Rect & a,cv::Rect & b){
            return a.x<b.x;
        });
        cv::Rect leftlight=lightrects[0];
        cv::Rect rightlight=lightrects[1];
        cv::Point ltopcenter(leftlight.x+leftlight.width/2,leftlight.y);
        cv::Point lbotcenter(leftlight.x+leftlight.width/2,leftlight.y+leftlight.height);
        cv::Point rtopcenter(rightlight.x+rightlight.width/2,rightlight.y);
        cv::Point rbotcenter(rightlight.x+rightlight.width/2,rightlight.y+rightlight.height);
        cv::Point center((ltopcenter.x+rbotcenter.x)/2,(ltopcenter.y+rbotcenter.y)/2);
        cv::rectangle(img,leftlight,cv::Scalar(255,0,255),2);
        cv::rectangle(img,rightlight,cv::Scalar(255,0,255),2);
        cv::line(img,ltopcenter,rbotcenter,cv::Scalar(255,0,255),2);
        cv::line(img,lbotcenter,rtopcenter,cv::Scalar(255,0,255),2);
        cv::circle(img,ltopcenter,5,cv::Scalar(255,0,0),-1);
        cv::circle(img,rtopcenter,5,cv::Scalar(255,0,0),-1);
        cv::circle(img,lbotcenter,5,cv::Scalar(0,255,255),-1);
        cv::circle(img,rbotcenter,5,cv::Scalar(0,255,255),-1);
        cv::circle(img,center,5,cv::Scalar(0,255,0),-1);
    }
    cv::imshow("result",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}