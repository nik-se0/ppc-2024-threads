// Copyright 2024 Semenova Veronika
#include <gtest/gtest.h>

#include <random>
#include <vector>

#include "seq/semenova_v_ver_Gauss/include/ops_seq.hpp"

std::vector<int> CreateRandomVector(size_t n) {
  // std::srand(0);
  std::vector<int> vec(n);
  for (size_t i = 0; i < n; i++) {
    vec[i] = std::rand() % 256;
  }
  return vec;
}

TEST(semenova_v_ver_Gauss_seq, Creat_empty_task) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_with_empty_outputs_and_inputs) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_TRUE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_inputs1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_inputs2) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_inputs3) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_outputs1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_outputs2) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_without_outputs3) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_with_wrong_matrix_size1) {
  size_t n = 3;
  size_t m = 3;
  size_t a = 6;
  size_t b = 6;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(a);
  taskDataSeq->outputs_count.emplace_back(b);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_with_wrong_matrix_size2) {
  size_t n = 2;
  size_t m = 2;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  ASSERT_FALSE(ImageFilterVerGauss.validation());
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_with_outputs_and_inputs1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ASSERT_TRUE(ImageFilterVerGauss.pre_processing());
  }
}
TEST(semenova_v_ver_Gauss_seq, Creat_task_with_outputs_and_inputs2) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ASSERT_TRUE(ImageFilterVerGauss.pre_processing());
  }
}
TEST(semenova_v_ver_Gauss_seq, Run_task1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ASSERT_TRUE(ImageFilterVerGauss.run());
  }
}
TEST(semenova_v_ver_Gauss_seq, Run_task2) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ASSERT_TRUE(ImageFilterVerGauss.run());
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_post_processing1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_post_processing2) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>((image).data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_run_correct1) {
  size_t n = 3;
  size_t m = 3;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 50, 3, 4, 4, 0, 7, 8, 98};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 4, 15, 0, 7, 8, 98};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (size_t i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_run_correct2) {
  size_t n = 4;
  size_t m = 4;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {1, 50, 3, 125, 1, 4, 0, 69, 0, 7, 8, 98, 0, 0, 0, 0};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 125, 1, 9, 28, 69, 0, 3, 19, 98, 0, 0, 0, 0};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (size_t i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_correct_pre_processing) {
  size_t n = 4;
  size_t m = 4;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = {285, 285, 285, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ImageFilterVerGauss.post_processing();

    for (size_t i = 0; i < n * m; ++i) {
      EXPECT_EQ(filteredImage[i], res[i]);
    }
  }
}
TEST(semenova_v_ver_Gauss_seq, Task_correct_with_random_image) {
  size_t n = 10;
  size_t m = 10;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);
  image = CreateRandomVector(n * m);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  std::vector<int> res(n * m);
  res = {1, 50, 3, 125, 1, 9, 28, 69, 0, 3, 19, 98, 0, 0, 0, 0};

  ImageFilterVerGauss ImageFilterVerGauss(taskDataSeq);
  if (ImageFilterVerGauss.validation()) {
    ImageFilterVerGauss.pre_processing();
    ImageFilterVerGauss.run();
    ASSERT_TRUE(ImageFilterVerGauss.post_processing());
  }
}
