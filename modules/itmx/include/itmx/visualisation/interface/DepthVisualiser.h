/**
 * itmx: DepthVisualiser.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#ifndef H_ITMX_DEPTHVISUALISER
#define H_ITMX_DEPTHVISUALISER

#include <ITMLib/Objects/RenderStates/ITMRenderState.h>

#include "../../base/ITMImagePtrTypes.h"

namespace itmx {

/**
 * \brief An instance of a class deriving from this one can be used to render a depth visualisation of an InfiniTAM scene.
 */
class DepthVisualiser
{
  //#################### ENUMERATIONS ####################
public:
  /**
   * \brief An enumeration specifying the different types of depth calculation that are supported.
   */
  enum DepthType
  {
    /** Calculates the Euclidean distance of each voxel hit by the raycast from the camera centre. */
    DT_EUCLIDEAN,

    /** Calculates the perpendicular distance of each voxel hit by the raycast from the plane containing the camera centre. */
    DT_ORTHOGRAPHIC
  };

  //#################### DESTRUCTOR ####################
public:
  /**
   * \brief Destroys the depth visualiser.
   */
  virtual ~DepthVisualiser() {}

  //#################### PUBLIC ABSTRACT MEMBER FUNCTIONS ####################
public:
  /**
   * \brief Renders a depth view of the specified scene from the specified camera pose.
   *
   * \param depthType         The type of depth calculation to use.
   * \param cameraPosition    The camera position (in world space).
   * \param cameraLookVector  The camera look vector.
   * \param renderState       The render state corresponding to the specified camera pose.
   * \param voxelSize         The size of an InfiniTAM voxel (in metres).
   * \param invalidDepthValue The depth value to use for pixels whose rays do not intersect the scene.
   * \param outputImage       The image into which to write the depth visualisation of the scene.
   */
  virtual void render_depth(DepthType depthType, const Vector3f& cameraPosition, const Vector3f& cameraLookVector, const ITMLib::ITMRenderState *renderState,
                            float voxelSize, float invalidDepthValue, const ITMFloatImage_Ptr& outputImage) const = 0;
};

//#################### TYPEDEFS ####################

typedef boost::shared_ptr<const DepthVisualiser> DepthVisualiser_CPtr;

}

#endif
