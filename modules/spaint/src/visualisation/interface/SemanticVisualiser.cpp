/**
 * spaint: SemanticVisualiser.cpp
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#include "visualisation/interface/SemanticVisualiser.h"

#include <itmx/base/MemoryBlockFactory.h>
using itmx::MemoryBlockFactory;

namespace spaint {

//#################### CONSTRUCTORS ####################

SemanticVisualiser::SemanticVisualiser(size_t maxLabelCount)
: m_labelColoursMB(MemoryBlockFactory::instance().make_block<Vector3u>(maxLabelCount))
{}

//#################### DESTRUCTOR ####################

SemanticVisualiser::~SemanticVisualiser() {}

//#################### PUBLIC MEMBER FUNCTIONS ####################

void SemanticVisualiser::render(const SpaintVoxelScene *scene, const ORUtils::SE3Pose *pose, const ITMLib::ITMIntrinsics *intrinsics, const ITMLib::ITMRenderState *renderState,
                                const std::vector<Vector3u>& labelColours, LightingType lightingType, float labelAlpha, ITMUChar4Image *outputImage) const
{
  // Update the label colours in the memory block.
  Vector3u *labelColoursData = m_labelColoursMB->GetData(MEMORYDEVICE_CPU);
  for(size_t i = 0, size = std::min(m_labelColoursMB->dataSize, labelColours.size()); i < size; ++i)
  {
    labelColoursData[i] = labelColours[i];
  }
  m_labelColoursMB->UpdateDeviceFromHost();

  // Render using the new label colours.
  render_internal(scene, pose, intrinsics, renderState, lightingType, labelAlpha, outputImage);
}

}
