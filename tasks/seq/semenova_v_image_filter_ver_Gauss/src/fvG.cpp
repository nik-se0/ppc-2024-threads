// Copyright 2024 Semenova Veronika
#include "seq/semenova_v_image_filter_ver_Gauss/include/fvG.hpp"

std::vector<std::vector<int>> convert12(int* array, size_t rows, size_t cols) {
  std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      result[i][j] = array[i * cols + j];
    }
  }
  return result;
}

bool ImageFilterVerGauss::validation() {
  internal_order_test();

return !taskData->inputs.empty() && !taskData->outputs.empty() && !taskData->inputs_count.empty() &&
         !taskData->outputs_count.empty() && taskData->inputs[0] != nullptr && taskData->outputs[0] != nullptr &&
         taskData->outputs_count[1] == taskData->inputs_count[1] && taskData->outputs_count[0] >= 3 &&
         +taskData->outputs_count[1] >= 3;  // the image size <>= size of filter core
}

bool ImageFilterVerGauss::pre_processing() {
  internal_order_test();

  n = taskData->inputs_count[0];
  m = taskData->inputs_count[1];

  image = convert12(reinterpret_cast<int*>(taskData->inputs[0]), n, m);

  for (auto& row : image) {
    for (int& pixel : row) {
      pixel = std::max(0, std::min(255, pixel));
    }
  }
  filteredImage = image;

  return true;
}

bool ImageFilterVerGauss::run() {
  internal_order_test();

  for (size_t i = 1; i < n - 1; ++i) {
    for (size_t j = 1; j < m - 1; ++j) {
      double sum = 0;
      /* for (size_t x = -1; x <= 1; ++x) {
            for (size_t y = -1; y <= 1; ++y) {
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

  return true;
}

bool ImageFilterVerGauss::post_processing() {
  internal_order_test();

  for (auto& row : filteredImage) {
    for (int& pixel : row) {
      pixel = std::max(0, std::min(255, pixel));
    }
  }

  int* d = reinterpret_cast<int*>(taskData->outputs[0]);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; j++) {
      d[i * n + j] = filteredImage[i][j];
    }
  }

  return true;
}
