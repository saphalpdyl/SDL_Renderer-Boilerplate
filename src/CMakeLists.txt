set(CMAKE_CXX_STANDARD 20) # Setting C++ Standard

add_executable(${PROJECT_NAME} 
	main.cpp 

	# Custom Functions
	SDL_Functions.cpp 
	
	) # Create executable named PROJECT_NAME

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
