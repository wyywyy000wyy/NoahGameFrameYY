set(ProjectName "Tutorial3")
file(GLOB Tutorial3_ROOT_Cpp
	*.cpp)
file(GLOB Tutorial3_ROOT_Hpp 
	*.h)

add_library(Tutorial3 STATIC
	${Tutorial3_ROOT_Cpp}
	${Tutorial3_ROOT_Hpp})
	
set_target_properties( Tutorial3 PROPERTIES OUTPUT_NAME_DEBUG "Tutorial3")
set_target_properties( Tutorial3 PROPERTIES PREFIX "")
set_target_properties( Tutorial3 PROPERTIES 
	FOLDER "Tutorial/Tutorial3"
	ARCHIVE_OUTPUT_DIRECTORY ${NFOutPutDir}
	RUNTIME_OUTPUT_DIRECTORY ${NFOutPutDir}
	LIBRARY_OUTPUT_DIRECTORY ${NFOutPutDir} )
link_NFSDK("Tutorial3")

if(UNIX)
	target_link_libraries(Tutorial3 -static-libstdc++)
	add_definitions(
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)

else()
	target_link_libraries(Tutorial3 -static-libstdc++)
	add_definitions(
		-DWIN
		-D_USRDLL
		-DELPP_NO_DEFAULT_LOG_FILE
	)
endif()