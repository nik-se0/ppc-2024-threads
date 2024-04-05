// Copyright 2024 Semenova Veronika
#pragma once

#include <string>
#include <utility>
#include <vector>

#include "core/task/include/task.hpp"
using namespace std;

class ImageFilterVerGauss : public ppc::core::Task {
 public:
  explicit ImageFilterVerGauss(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
     double kernel[3][3] = {
         {1.0 / 16, 2.0 / 16, 1.0 / 16}, {2.0 / 16, 4.0 / 16, 2.0 / 16}, {1.0 / 16, 2.0 / 16, 1.0 / 16} };
     int** image;
     int** filteredImage;
     int n, m;
};
