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
- Refer to [Dependencies](#dependencies) before proceeding
- Run CMake to build the project - feel free to build any project type you want
  - ```$ cmake ..```
  
### Dependencies
- Debian/Ubuntu/Mint: ```$ sudo apt install build-essential libXmu-dev libXi-dev libgl-dev cmake```
- RedHat/CentOS/Fedora: ```$ sudo yum install libXmu-devel libXi-devel libGL-devel cmake```
- Mac OS X: ```$ brew install Caskroom/cask/xquartz```
  
### Notes
- The project has been tested using the GCC and MSVC compilers
- When building a project for Visual Studio, run in release mode
  - Some bug exists when run in debug mode where the application appears to run normally, but meshes are not rendered at all
