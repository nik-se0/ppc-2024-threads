// Copyright 2024 Semenova Veronika
#include <gtest/gtest.h>

#include <random>
#include <vector>

#include "core/perf/include/perf.hpp"
#include "seq/semenova_v_image_filter_ver_Gauss/include/fvG.hpp"

double Timer() {
  auto current = std::chrono::high_resolution_clock::now();
  return static_cast<double>(current.time_since_epoch().count()) * 1e-8;
}

TEST(semenova_v_image_filter_ver_Gauss, test_pipeline_run) {
  size_t n = 2000;
  size_t m = 2000;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) {
        image[i * m + j] = 10;
        filteredImage[i * m + j] = 10;
      } else {
        image[i * m + j] = 0;
        filteredImage[i * m + j] = 0;
      }
    }
  }

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  auto testTaskSeq = std::make_shared<ImageFilterVerGauss>(taskDataSeq);

  // Create Perf attributes
  auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  perfAttr->num_running = 10;
  perfAttr->current_timer = &Timer;

  auto perfResults = std::make_shared<ppc::core::PerfResults>();
  auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSeq);
  perfAnalyzer->pipeline_run(perfAttr, perfResults);
  ppc::core::Perf::print_perf_statistic(perfResults);

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (i == j) {
        EXPECT_EQ(filteredImage[i * m + j], 3);
      } else {
        if (i == j + 1 || j == i + 1) {
          EXPECT_EQ(filteredImage[i * m + j], 2);
        } else {
          EXPECT_EQ(filteredImage[i * m + j], 0);
        }
      }
    }
  }
}

TEST(semenova_v_image_filter_ver_Gauss, test_task_run) {
  size_t n = 2000;
  size_t m = 2000;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) {
        image[i * m + j] = 10;
        filteredImage[i * m + j] = 10;
      } else {
        image[i * m + j] = 0;
        filteredImage[i * m + j] = 0;
      }
    }
  }

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();

  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataSeq->inputs_count.emplace_back(n);
  taskDataSeq->inputs_count.emplace_back(m);

  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataSeq->outputs_count.emplace_back(n);
  taskDataSeq->outputs_count.emplace_back(m);

  auto testTaskSeq = std::make_shared<ImageFilterVerGauss>(taskDataSeq);

  // Create Perf attributes
  auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  perfAttr->num_running = 10;
  perfAttr->current_timer = &Timer;

  auto perfResults = std::make_shared<ppc::core::PerfResults>();
  auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSeq);
  perfAnalyzer->pipeline_run(perfAttr, perfResults);
  ppc::core::Perf::print_perf_statistic(perfResults);

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (i == j) {
        EXPECT_EQ(filteredImage[i * m + j], 3);
      } else {
        if (i == j + 1 || j == i + 1) {
          EXPECT_EQ(filteredImage[i * m + j], 2);
        } else {
          EXPECT_EQ(filteredImage[i * m + j], 0);
        }
      }
    }
  }
}
