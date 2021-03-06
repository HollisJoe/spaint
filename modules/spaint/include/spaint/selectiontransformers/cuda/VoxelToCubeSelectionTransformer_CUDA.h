/**
 * spaint: VoxelToCubeSelectionTransformer_CUDA.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#ifndef H_SPAINT_VOXELTOCUBESELECTIONTRANSFORMER_CUDA
#define H_SPAINT_VOXELTOCUBESELECTIONTRANSFORMER_CUDA

#include "../interface/VoxelToCubeSelectionTransformer.h"

namespace spaint {

/**
 * \brief An instance of this class can be used to expand a selection of individual voxels into a selection of voxel cubes around the initial voxels using CUDA.
 */
class VoxelToCubeSelectionTransformer_CUDA : public VoxelToCubeSelectionTransformer
{
  //#################### CONSTRUCTORS ####################
public:
  /**
   * \brief Constructs a voxel to cube selection transformer that uses CUDA.
   *
   * \param radius  The (Manhattan) radius (in voxels) to select around each initial voxel.
   */
  explicit VoxelToCubeSelectionTransformer_CUDA(int radius);

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  /** Override */
  virtual void transform_selection(const Selection& inputSelectionMB, Selection& outputSelectionMB) const;
};

}

#endif
