cmake_minimum_required(Version = 3.8)
project ("SampleCPlusPlusCodes")	# The name of the project.

add_executable(${"PROJECT_NAME"} "Main.cpp")	# The executable required to create the project.

install(TARGETS ${"PROJECT_NAME"} DESTINATION bin) # ${CMAKE_INSTALL_PREFIX}/bin
install(TARGETS "Main.cpp" DESTINATION src) #${CMAKE_INSTALL_PREFIX}/src
