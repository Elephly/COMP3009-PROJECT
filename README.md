# N3DIL
The "Nick 3D & Image Library"

### Prerequisites
- Git
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
- Debian/Ubuntu/Mint: ```$ sudo apt-get install -y build-essential libxmu-dev libxi-dev libgl-dev libgl1-mesa-dev libglu1-mesa-dev git cmake```
- RedHat/CentOS/Fedora: ```$ sudo yum install libXmu-devel libXi-devel libGL-devel git cmake```
- Mac OS X: ```$ brew install Caskroom/cask/xquartz git cmake```
  
### Notes
- The project has been tested using the GCC and MSVC compilers
- When building a project for Visual Studio, run in release mode
  - Some bug exists when run in debug mode where the application appears to run normally, but meshes are not rendered at all
