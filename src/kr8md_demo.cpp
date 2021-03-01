#include <stdint.h>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>

#include <kr8md/kr8md.h>
#include <kr8md/std_helpers.h>

using namespace kr8md;

puint32 mandelbrot(pfloat &c_re, pfloat &c_im, unsigned int max_iterations)
{
    pfloat z_re = c_re, z_im = c_im;
    puint32 i{0u};
    puint32 pmax_iterations{max_iterations};
    pbool32 active{i < pmax_iterations};

    while (any(active))
    {
        masked(active, active) = z_re * z_re + z_im * z_im <= 4.f;

        if (!any(active))
        {
            break;
        }

        pfloat new_re = z_re * z_re - z_im * z_im;
        pfloat new_im = 2.f * z_re * z_im;

        z_re = c_re + new_re;
        z_im = c_im + new_im;

        masked(i, active) = i + puint32{1u};
        masked(active, active) = i < pmax_iterations;
    }

    return i;
}

void mandelbrot_loop(uint *dst, int width = 1080, int height = 720,
                     float cxmin = -2, float cxmax = 1, float cymin = -1, float cymax = 1,
                     unsigned int max_iterations = 256)
{
    float dx = (cxmax - cxmin) / width;
    float dy = (cymax - cymin) / height;

    for (size_t i = 0; i < height; i++)
    {
        pfloat y = cymin + i * dy;

        for (size_t j = 0; j < width; j += pfloat::width)
        {
            pfloat pj{(float)j};
            for (size_t p = 1; p < pfloat::width; p++)
            {
                pj.data[p] = pj.data[0] + p;
            }

            pfloat x = cxmin + pj * dx;

            puint32 result = mandelbrot(x, y, max_iterations);

            size_t index = i * width + j;
            store(&dst[index], result);
        }
    }
}

int main(void)
{
    size_t width = 1920;
    size_t height = 1080;
    size_t size = width * height;
    uint *pout_mandel = new uint[size];

    mandelbrot_loop(pout_mandel, width, height);
    delete[] pout_mandel;

    std::cout << "Max kr8md width/lanes (bytes): " << KR8MD_MAX_VEC_REGISTER_SIZE << std::endl;
    std::cout << "sizeof(pfloat): " << sizeof(pfloat) << std::endl;

    return 0;
}