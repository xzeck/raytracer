#include <iostream>
#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"

using namespace std;
int main()
{

    // Image generations
    auto aspect_ratio = 16.0 / 9.0;

    int image_width = 400;

    // calculating image height
    int image_height = static_cast<int>(image_width / aspect_ratio);

    image_height = image_height < 1 ? 1: image_height;

    // viewport and camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // x, y, z
    // -viewport_height because we are using right handed co-ordinates
    // x to the right side of the screen
    // y going up
    // z going into the screen
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculating the horizontal and vertical delta
    auto pixel_delta_u = viewport_u / image_width;

    cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for(int j = 0; j < image_height; j++)
    {

        clog << "Scan lines remaining: " << (image_height - j) << endl << flush; 

        for(int i = 0; i < image_width; i++)
        {
            auto pixel_color = color(double(i) / image_width, double(j) / image_height, 0);
            write_color(std::cout, pixel_color);
        }
    }

    clog << "Done" << "\n" << flush;
}