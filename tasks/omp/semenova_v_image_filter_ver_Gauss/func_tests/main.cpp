// Copyright 2024 Semenova Veronika
#include <gtest/gtest.h>

#include <random>
#include <vector>

#include "omp/semenova_v_image_filter_ver_Gauss/include/fvG_omp.hpp"

std::vector<int> CreateRandomVector(int n) {
  // std::srand(0);
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    vec[i] = std::rand() % 256;
  }
  return vec;
}

TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_empty_task) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_with_empty_outputs_and_inputs) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_TRUE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_inputs1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_inputs2) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_inputs3) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_outputs1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_outputs2) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_without_outputs3) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_with_wrong_matrix_size1) {
  int n = 3;
  int m = 3;
  int a = 6;
  int b = 6;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(a);
  taskDataOmp->outputs_count.emplace_back(b);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_with_wrong_matrix_size2) {
  int n = 2;
  int m = 2;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_with_outputs_and_inputs1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ASSERT_TRUE(ImageFilterVerGauss.pre_processing());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Creat_task_with_outputs_and_inputs2) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ASSERT_TRUE(ImageFilterVerGauss.pre_processing());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Run_task1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ASSERT_TRUE(ImageFilterVerGauss.run());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Run_task2) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ASSERT_TRUE(ImageFilterVerGauss.run());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_post_processing1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_post_processing2) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_run_correct1) {
  int n = 3;
  int m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 50, 3, 4, 4, 0, 7, 8, 98};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 4, 15, 0, 7, 8, 98};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (int i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_run_correct2) {
  int n = 4;
  int m = 4;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 50, 3, 125, 1, 4, 0, 69, 0, 7, 8, 98, 0, 0, 0, 0};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 125, 1, 9, 28, 69, 0, 3, 19, 98, 0, 0, 0, 0};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (int i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_correct_pre_processing) {
  int n = 4;
  int m = 4;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {285, 285, 285, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (int i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_image_filter_ver_Gauss_omp, Task_correct_with_random_image) {
  int n = 10;
  int m = 10;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = CreateRandomVector(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 125, 1, 9, 28, 69, 0, 3, 19, 98, 0, 0, 0, 0};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataOmp);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
