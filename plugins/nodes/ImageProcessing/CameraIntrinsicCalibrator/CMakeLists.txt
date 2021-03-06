project(CameraIntrinsicCalibrator)

set( res_header
	CameraIntrinsicCalibrator.h
	CameraIntrinsicCalibratorPlugin.h
	)

set( res_moc
	CameraIntrinsicCalibrator.h
	CameraIntrinsicCalibratorPlugin.h
	)

set( res_source
	CameraIntrinsicCalibrator.cpp
	CameraIntrinsicCalibratorPlugin.cpp
	)

set( res_description
	CameraIntrinsicCalibrator.xml
	)

# Check ImageCalibratorNode node dependencies..
	#---- OpenCV -------
	FIND_PACKAGE(OpenCV REQUIRED HINTS ${THIRDPARTY_DIR}/opencv )

	IF( OpenCV_FOUND )
		message("CV Found")
		# add additional include directories
		set( add_include_dir
			${OpenCV_INCLUDE_DIRS}
		)

		# Add additional library dependencies
		set( add_link_lib
			${OpenCV_LIBS}
		)

		include( add_project )
	
	ENDIF() # OpenCV_FOUND
	
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
message("OPENMP FOUND")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()