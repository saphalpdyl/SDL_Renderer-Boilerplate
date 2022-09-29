if [ ! -d "./build-cmake" ] 
then
	echo "Directory : build-cmake doesn't exists. Creating directory 'build-cmake'... "
	mkdir build-cmake
fi

cd build-cmake
cmake .. -G Ninja
ninja

./src/sdl_renderer_boilerplate
