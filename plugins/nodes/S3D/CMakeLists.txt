project(S3D)

if (FRAPPER_BUILD_NODES_S3D OR FRAPPER_BUILD_DEMO)
  message( STATUS "Adding plugins from directory S3D")
  add_subdirectory( CharonWorkflow )
  add_subdirectory( CharonWorkflowIterator )
  add_subdirectory( CImgListToOgre )
  add_subdirectory( MaskEditNode )
  add_subdirectory( OgreToCImgList )
  add_subdirectory( OpenMvgFeatureFinder )
  add_subdirectory( OpenMvgGlobalSfM )
  add_subdirectory( pointcloud2DepthCue )
  add_subdirectory( PointCloud2VertexBuffer )
  add_subdirectory( PointCloudReader )
  add_subdirectory( PreComputation )
  add_subdirectory( StereoView )
  add_subdirectory( ToFLib )
else()  
  message( STATUS "Skipping plugins from directory S3D")
endif()


