// Copyright 2024 Semenova Veronika
#include "tbb/semenova_v_fil_Gauss/include/ops_tbb.hpp"


int Min(int b, int c) {
    return (b < c) ? b : c;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}


bool ImageFilGauss::validation() {
  internal_order_test();

  return !taskData->inputs.empty() && !taskData->outputs.empty() && !taskData->inputs_count.empty() &&
         !taskData->outputs_count.empty() && taskData->inputs[0] != nullptr && taskData->outputs[0] != nullptr &&
         taskData->outputs_count[1] == taskData->inputs_count[1] && taskData->outputs_count[0] >= 3 &&
         +taskData->outputs_count[1] >= 3;  // the image size <>= size of filter core
}

bool ImageFilGauss::pre_processing() {
  internal_order_test();

  try {
    n = taskData->inputs_count[0];
    m = taskData->inputs_count[1];

    image = new int*[n];
    filteredImage = new int*[n];
    for (int i = 0; i < n; ++i) {
      image[i] = new int[m];
      filteredImage[i] = new int[m];
    }

    int* d = reinterpret_cast<int*>(taskData->inputs[0]);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; j++) {
        image[i][j] = d[i * n + j];
        image[i][j] = Max(0, Min(255, image[i][j]));
        filteredImage[i][j] = image[i][j];
      }
    }
  } catch (...) {
    return false;
  }

  return true;
}

bool ImageFilGauss::run() {
  internal_order_test();
  try {
    tbb::parallel_for(
      tbb::blocked_range2d<int>(1, n - 1, 1, m - 1), [&](const tbb::blocked_range2d<int>& r) {
        for(int i = r.rows().begin(); i != r.rows().end(); ++i) {
          for(int j = r.cols().begin(); j != r.cols().end(); ++j) {
            double sum = image[i - 1][j - 1] * kernel[0][0] + image[i - 1][j] * kernel[0][1] + image[i - 1][j + 1] * kernel[0][2] +
                         image[i][j - 1] * kernel[1][0] + image[i][j] * kernel[1][1] + image[i][j + 1] * kernel[1][2] +
                         image[i + 1][j - 1] * kernel[2][0] + image[i + 1][j] * kernel[2][1] + image[i + 1][j + 1] * kernel[2][2];
            filteredImage[i][j] = (int)sum;
          }
        }
      }
    );

  } catch (...) {
    return false;
  }
  return true;
}

bool ImageFilGauss::post_processing() {
  internal_order_test();
  try {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        filteredImage[i][j] = Max(0, Min(255, filteredImage[i][j]));
      }
    }
    int* d = reinterpret_cast<int*>(taskData->outputs[0]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i * n + j] = filteredImage[i][j];
      }
    }

    /*for (int i = 0; i < n; ++i) {
      delete[] image[i];
      delete[] filteredImage[i];
    }
    delete[] image;
    delete[] filteredImage;*/
  }
   catch (...) {
    return false;
  }
  return true;
}
