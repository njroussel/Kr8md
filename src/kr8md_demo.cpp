#include <kr8md/kr8md.h>
#include <kr8md/std_helpers.h>

#include <iostream>

using namespace kr8md;

pint32 mandelbrot(pfloat &c_re, pfloat &c_im, int max_iterations) {
  pfloat z_re = c_re, z_im = c_im;
  pint32 i{0};
  pint32 pmax_iterations{max_iterations};
  pbool32 active{i < pmax_iterations};

  while (any(active)) {
    masked(active, active) = z_re * z_re + z_im * z_im <= 4.f;

    if (!any(active)) {
      break;
    }

    pfloat new_re = z_re * z_re - z_im * z_im;
    pfloat new_im = 2.f * z_re * z_im;

    z_re = c_re + new_re;
    z_im = c_im + new_im;

    masked(i, active) = i + pint32{1};
    masked(active, active) = i < pmax_iterations;
  }

  return i;
}

void mandelbrot_loop(int *dst, int width = 1080, int height = 720,
                     float cxmin = -2, float cxmax = 1, float cymin = -1,
                     float cymax = 1, int max_iterations = 256) {
  float dx = (cxmax - cxmin) / (float)width;
  float dy = (cymax - cymin) / (float)height;

  for (size_t i = 0; i < height; i++) {
    pfloat y = cymin + (float)i * dy;

    for (size_t j = 0; j < width; j += pfloat::width) {
      pfloat pj{(float)j};
      for (size_t p = 1; p < pfloat::width; p++) {
        pj.data[p] = pj.data[0] + (float)p;
      }

      pfloat x = cxmin + pj * dx;

      pint32 result = mandelbrot(x, y, max_iterations);

      size_t index = i * static_cast<size_t>(width) + j;
      store(&dst[index], result);
    }
  }
}

int main(void) {
  int width = 1920;
  int height = 1080;
  int size = width * height;

  int *out_mandel = new int[static_cast<unsigned long>(size)];
  mandelbrot_loop(out_mandel, width, height);
  delete[] out_mandel;

  std::cout << "Max kr8md width/lanes (bytes): " << KR8MD_MAX_VEC_REGISTER_SIZE
            << std::endl;
  std::cout << "sizeof(pfloat): " << sizeof(pfloat) << std::endl;

  return 0;
}