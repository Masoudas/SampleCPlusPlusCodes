cmake_minimum_required(VERSION "3.7.1")
project ("SampleCPlusPlusCodes")	# The name of the project.

add_executable("${PROJECT_NAME}" "Main.cpp" "ATourOfC++11/STLStrings_36/StringClass_2/Operations/3_IO_Operations.cpp" "ATourOfC++11/STLStrings_36/StringClass_2/Operations/4_Numerical_Conversion.cpp" "ATourOfC++11/STLStrings_36/StringClass_2/Operations/5_Iterators.cpp")	# The executable required to create the project.

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) # ${CMAKE_INSTALL_PREFIX}/bin
install(FILES "Main.cpp" DESTINATION src) #${CMAKE_INSTALL_PREFIX}/src

add_subdirectory("Build")
