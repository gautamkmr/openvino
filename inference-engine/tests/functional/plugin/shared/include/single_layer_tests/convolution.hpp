// Copyright (C) 2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "functional_test_utils/layer_test_utils.hpp"
#include "ngraph_functions/builders.hpp"
#include "ngraph_functions/utils/ngraph_helpers.hpp"

typedef std::tuple<
        InferenceEngine::SizeVector,
        InferenceEngine::SizeVector,
        std::vector<ptrdiff_t>,
        std::vector<ptrdiff_t>,
        InferenceEngine::SizeVector,
        size_t,
        ngraph::op::PadType> convSpecificParams;
typedef std::tuple<
        convSpecificParams,
        InferenceEngine::Precision,
        InferenceEngine::Precision,
        InferenceEngine::SizeVector,
        LayerTestsUtils::TargetDevice> convLayerTestParamsSet;
namespace LayerTestsDefinitions {


class ConvolutionLayerTest : public testing::WithParamInterface<convLayerTestParamsSet>, public LayerTestsUtils::FuncTestsCommon {
public:
    static std::string getTestCaseName(testing::TestParamInfo<convLayerTestParamsSet> obj);

protected:
    void SetUp() override;
};

}  // namespace LayerTestsDefinitions