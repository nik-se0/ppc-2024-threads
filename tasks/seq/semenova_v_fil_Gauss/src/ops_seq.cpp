// Copyright 2024 Semenova Veronika
#include "seq/semenova_v_fil_Gauss/include/ops_seq.hpp"

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
        image[i][j] = std::max(0, std::min(255, image[i][j]));
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
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < m - 1; ++j) {
        double sum = 0;
        /* for (int x = -1; x <= 1; ++x) {
              for (int y = -1; y <= 1; ++y) {
              sum += image[i + x][j + y] * kernel[x + 1][y + 1];
    }
  }
  */
        sum = image[i - 1][j - 1] * kernel[0][0] + image[i - 1][j] * kernel[0][1] + image[i - 1][j + 1] * kernel[0][2] +
              image[i][j - 1] * kernel[1][0] + image[i][j] * kernel[1][1] + image[i][j + 1] * kernel[1][2] +
              image[i + 1][j - 1] * kernel[2][0] + image[i + 1][j] * kernel[2][1] + image[i + 1][j + 1] * kernel[2][2];
        filteredImage[i][j] = (int)sum;
      }
    }
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
        filteredImage[i][j] = std::max(0, std::min(255, filteredImage[i][j]));
      }
    }
    int* d = reinterpret_cast<int*>(taskData->outputs[0]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i * n + j] = filteredImage[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      delete[] image[i];
      delete[] filteredImage[i];
    }
    delete[] image;
    delete[] filteredImage;
  }
   catch (...) {
    return false;
  }
  return true;
}
