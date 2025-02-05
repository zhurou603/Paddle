// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <memory>
#include <vector>

#include "paddle/fluid/framework/operator.h"
#include "paddle/fluid/operators/controlflow/op_variant.h"
#include "paddle/fluid/operators/controlflow/pylayer_op.h"
#include "paddle/fluid/string/string_helper.h"

namespace paddle {
namespace framework {
class ProgramDesc;
}  // namespace framework
}  // namespace paddle

namespace paddle {
namespace operators {

void PrepareSafeEagerDeletionOnPyLayerOpAndPyLayerGradOp(
    const framework::ProgramDesc &program,
    int block_id,
    const std::vector<std::unique_ptr<framework::OperatorBase>> &all_ops);

void PrepareSafeEagerDeletionOnPyLayerOpAndPyLayerGradOp(
    const framework::ProgramDesc &program,
    const std::vector<OpVariant> &pylayer_ops,
    const std::vector<OpVariant> &pylayer_grad_ops);

}  // namespace operators
}  // namespace paddle
