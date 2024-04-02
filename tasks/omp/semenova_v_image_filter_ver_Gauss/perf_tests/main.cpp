// Copyright 2024 Semenova Veronika
#include <gtest/gtest.h>

#include <omp.h>
#include <random>
#include <vector>

#include "core/perf/include/perf.hpp"
#include "omp/semenova_v_image_filter_ver_Gauss/include/fvG_omp.hpp"

double Timer() {
    return omp_get_wtime();
}

TEST(semenova_v_image_filter_ver_Gauss_omp, test_pipeline_run) {
  size_t n = 4000;
  size_t m = 4000;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if (i == j) {
        image[i * m + j] = 10;
        filteredImage[i * m + j] = 10;
      } else {
        image[i * m + j] = 0;
        filteredImage[i * m + j] = 0;
      }
    }
  }

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  auto testTaskSeq = std::make_shared<ImageFilterVerGauss>(taskDataOmp);

  // Create Perf attributes
  auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  perfAttr->num_running = 10;
  perfAttr->current_timer = &Timer;

  auto perfResults = std::make_shared<ppc::core::PerfResults>();
  auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSeq);
  perfAnalyzer->pipeline_run(perfAttr, perfResults);
  ppc::core::Perf::print_perf_statistic(perfResults);

  for (size_t i = 1; i < n - 1; ++i) {
    for (size_t j = 1; j < m - 1; ++j) {
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

TEST(semenova_v_image_filter_ver_Gauss_omp, test_task_run) {
  size_t n = 4000;
  size_t m = 4000;
  std::vector<int> image(n * m);
  std::vector<int> filteredImage(n * m);

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if (i == j) {
        image[i * m + j] = 10;
        filteredImage[i * m + j] = 10;
      } else {
        image[i * m + j] = 0;
        filteredImage[i * m + j] = 0;
      }
    }
  }

  std::shared_ptr<ppc::core::TaskData> taskDataOmp = std::make_shared<ppc::core::TaskData>();

  taskDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(image.data()));
  taskDataOmp->inputs_count.emplace_back(n);
  taskDataOmp->inputs_count.emplace_back(m);

  taskDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>((filteredImage).data()));
  taskDataOmp->outputs_count.emplace_back(n);
  taskDataOmp->outputs_count.emplace_back(m);

  auto testTaskSeq = std::make_shared<ImageFilterVerGauss>(taskDataOmp);

  // Create Perf attributes
  auto perfAttr = std::make_shared<ppc::core::PerfAttr>();
  perfAttr->num_running = 10;
  perfAttr->current_timer = &Timer;

  auto perfResults = std::make_shared<ppc::core::PerfResults>();
  auto perfAnalyzer = std::make_shared<ppc::core::Perf>(testTaskSeq);
  perfAnalyzer->pipeline_run(perfAttr, perfResults);
  ppc::core::Perf::print_perf_statistic(perfResults);

  for (size_t i = 1; i < n - 1; ++i) {
    for (size_t j = 1; j < m - 1; ++j) {
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
