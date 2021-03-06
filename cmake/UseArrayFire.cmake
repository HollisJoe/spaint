######################
# UseArrayFire.cmake #
######################

OPTION(WITH_ARRAYFIRE "Build with ArrayFire support?" OFF)

IF(WITH_ARRAYFIRE)
  FIND_PACKAGE(ArrayFire)

  INCLUDE_DIRECTORIES(SYSTEM ${ArrayFire_INCLUDE_DIRS})
  ADD_DEFINITIONS(-DWITH_ARRAYFIRE)
ENDIF()
