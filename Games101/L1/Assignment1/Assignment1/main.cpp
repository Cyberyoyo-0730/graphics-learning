#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;


//观察矩阵
Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

//旋转矩阵
//函数目的：实现三维中绕z轴旋转（z的坐标不变）的变换矩阵

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();//创建一个4*4的单位矩阵
    float rad = rotation_angle / 180.0 * MY_PI;//把角度转换成弧度（C++只认弧度）
    model(0, 0) = cos(rad);
    model(0, 1) = -sin(rad);
    model(1, 0) = sin(rad);
    model(1, 1) = cos(rad);//标准2D旋转矩阵
    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    return model;
}



//投影矩阵
//函数目的：使用给定的参数逐个元素地构建透视投影矩阵（出现“近大远小”效果）并返回该矩阵


Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    float rad = eye_fov / 180.0f * M_PI;
    float t = tan(rad / 2.0f) * fabs(zNear);//创建4*4单位矩阵Near);//eye_fov:视角大小；t:top,即画面上边界
    //Znear：近裁剪面（相机眼睛前面，最近能看到多近的东西），离相机太近的物体会被直接切掉，不画出来，能够避免物体贴到镜头上，画面糊掉、出错
   //转换成弧度后算tan，算出相机能看到的高度的一半
    float b = -t;// b:bottom, 即画面下边界（上边取反）
    float r = t * aspect_ratio;//aspect_ratio:宽高比；r:right,即画面右边界
    float l = -r; //l:left, 即画面左边界（右边取反）

    projection <<
        2 * zNear / (r - l), 0, (r + l) / (r - l), 0,
        0, 2 * zNear / (t - b), (t + b) / (t - b), 0,
        0, 0, -(zFar + zNear) / (zFar - zNear), -2 * zFar * zNear / (zFar - zNear),
        0, 0, -1, 0;

    return projection;
}
int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        angle += 2;

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
