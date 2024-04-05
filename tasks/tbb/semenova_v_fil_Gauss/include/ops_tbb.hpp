// Copyright 2024 Semenova Veronika
#pragma once

#include <string>
#include <vector>

#include "core/task/include/task.hpp"

class ImageFilGauss : public ppc::core::Task {
 public:
  explicit ImageFilGauss(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  ~ImageFilGauss() {
   if(image!=nullptr){
    for(int i = 0; i < n; ++i) {
      delete[] image[i];
    }
    delete[] image;
   }
   if(filteredImage!=nullptr){
    for(int i = 0; i < n; ++i) {
         delete[] filteredImage[i];
    }
    delete[] filteredImage;
   }
  }
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
     double kernel[3][3] = {
         {1.0 / 16, 2.0 / 16, 1.0 / 16}, {2.0 / 16, 4.0 / 16, 2.0 / 16}, {1.0 / 16, 2.0 / 16, 1.0 / 16} };
     int** image=nullptr;
     int** filteredImage=nullptr;
     int n, m;
};
