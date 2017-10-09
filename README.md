# N3DIL
Nick's 3D & Image Library

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
- Debian/Ubuntu/Mint:
  - ```$ sudo apt-get install -y build-essential libxmu-dev libxi-dev libgl-dev libgl1-mesa-dev libglu1-mesa-dev git cmake```
- RedHat/CentOS/Fedora:
  - ```$ sudo yum groupinstall -y "Development Tools" "Development Libraries"```
  - ```$ sudo yum install -y libXmu-devel libXi-devel libGL-devel mesa-libGL-devel mesa-libGLU-devel git cmake```
- Mac OS X: Install Xcode and then do the following:
  - ```$ xcode-select --install```
  - ```$ brew install Caskroom/cask/xquartz git cmake```
  
### Notes
- The project has been tested using the GCC and MSVC compilers
- Building the project currently requires bash to build glew, therefore the only way to build the project on Windows is with Windows 10, with developer mode enabled, and with Windows Subsystem for Linux enabled
- When building a project for Visual Studio, run in release mode
  - Some bug exists when running in debug mode where the application appears to run normally, but meshes are not rendered at all
