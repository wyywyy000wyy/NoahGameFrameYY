set(ProjectName "Tutorial4")
file(GLOB Tutorial4_ROOT_Cpp
	*.cpp)
file(GLOB Tutorial4_ROOT_Hpp 
	*.h)

add_library(Tutorial4 STATIC
	${Tutorial4_ROOT_Cpp}
	${Tutorial4_ROOT_Hpp})
	
set_target_properties( Tutorial4 PROPERTIES OUTPUT_NAME_DEBUG "Tutorial4")
set_target_properties( Tutorial4 PROPERTIES PREFIX "")
set_target_properties( Tutorial4 PROPERTIES 
	FOLDER "Tutorial/Tutorial4"
	ARCHIVE_OUTPUT_DIRECTORY ${NFOutPutDir}
	RUNTIME_OUTPUT_DIRECTORY ${NFOutPutDir}
	LIBRARY_OUTPUT_DIRECTORY ${NFOutPutDir} )
link_NFSDK("Tutorial4")

if(UNIX)
	target_link_libraries(Tutorial4 -static-libstdc++)
	add_definitions(
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)

else()
	target_link_libraries(Tutorial4 -static-libstdc++)
	add_definitions(
		-DWIN
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)
endif()