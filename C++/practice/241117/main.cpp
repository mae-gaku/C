#include <opencv2/opencv.hpp>

int main()
{
    // image.pngをimgに代入
    cv::Mat img = cv::imread("../image.jpg");

    // imgを白黒にしてimg_binに代入
    cv::Mat img_bin;
    cv::cvtColor(img, img_bin, cv::COLOR_BGR2GRAY);
    
    // cannyでエッジ検出
    cv::Mat img_canny;
    cv::Canny(img, img_canny, 500.0, 700.0);

    // チャンネル数の確認
    std::cout << "img     : " << img.channels() << " channel" << std::endl;
    std::cout << "img_bin : " << img_bin.channels() << " channel" << std::endl;

    // imgの表示
    cv::imshow("img_bin", img);
    cv::imshow("img_bin", img_bin);
    cv::imshow("img_bin", img_canny);

    // キーが押されるまで待機
    cv::waitKey(0);

    return 0;
}