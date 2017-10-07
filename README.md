# N3DIL
The "Nick 3D & Image Library"

### Prerequisites
- CMake 3.x.x

### Build Instructions
- Clone the project recursively to check out submodules
  - ```$ git clone https://github.com/nicholaschiasson/N3DIL.git --recursive```
- Create a build directory for CMake to do its work, then go to that directory
  - ```$ mkdir N3DIL/build```
  - ```$ cd N3DIL/build```
- Run CMake to build the project - feel free to build any project type you want
  - ```$ cmake ..```
  
### Notes
- The project has been tested using the GCC and MSVC compilers
- When building a project for Visual Studio, run in release mode
  - Some bug exists when run in debug mode where the application appears to run normally, but meshes are not rendered at all
- When building for GNU Makefiles on a Linux system, refer to the following dependencies list before running CMake

### Dependencies
- libxi-dev
