# N3DIL
Nick's 3D & Image Library

## Contents
- [Description](#description)
  - [Demo Controls](#demo-controls)
- [Setup](#setup)
  - [Prerequisites](#prerequisites)
  - [Build Instructions](#build-instructions)
  - [Dependencies](#dependencies)
  - [Notes](#notes)

## Description
This was a term project for COMP3009, my third year computer graphics course. At
the time, my goal for the project was to take what I was learning and make an
object oriented abstraction for OpenGL which I thought would be easier to work
with for general use. It's debatable whether or not I actually achieved anything
near my goal, but I was still proud of the results.

Contrary to the name, the project doesn't actually build a framework or library
which can be linked, but instead it builds an executable demo scene which I had
used to highlight features I implemented for the course project. As such, there
are many aspects of the project's design which I wish I had made more robust,
but I will not make efforts to change these things in the foreseeable future, so
please enjoy the animated running men demo scene.

#### Demo Controls
| Key          | Action                                                                           |
| ------------ | -------------------------------------------------------------------------------- |
| W            | Move camera forward along camera forward vector                                  |
| A            | Move camera left along camera right vector                                       |
| S            | Move camera backward along camera forward vector                                 |
| D            | Move camera right along camera right vector                                      |
| Q            | Move camera up along world up vector                                             |
| C            | Move camera down along world up vector                                           |
| UP           | Pitch camera up about camera right vector (look up)                              |
| LEFT         | Yaw camera left about world up vector (look left)                                |
| DOWN         | Pitch camera down about camera right vector (look down)                          |
| RIGHT        | Yaw camera right about world up vector (look right)                              |
| SPACE        | Toggle play/pause cat-faced manikin running animation                            |
| ENTER/RETURN | Stop cat-faced manikin animation (resets pose)                                   |
| I            | Move cat-faced manikin forward                                                   |
| J            | Yaw cat-faced manikin left                                                       |
| K            | Move cat-faced manikin backward                                                  |
| L            | Yaw cat-faced manikin right                                                      |
| SHIFT + K    | Toggle create/destroy running manikin group                                      |
| SHIFT + L    | Toggle cat-faced manikin animation looping                                       |
| -            | Slow cat-faced manikin animation speed                                           |
| +            | Hasten cat-faced manikin animation speed                                         |
| F            | Toggle wire frame rendering                                                      |
| ESC          | Quit game (ignored in unity editor)                                              |

## Setup
The remainder of this document details how to go about cloning and building this
project in your own environment.

#### Prerequisites
- All Platforms:
  - Git
  - CMake 3.x.x
- Debian/Ubuntu/Mint:
  - ```$ sudo apt-get install -y build-essential```
- RedHat/CentOS/Fedora:
  - ```$ sudo yum groupinstall -y "Development Tools" "Development Libraries"```
- Mac OS X: Install Xcode and then do the following:
  - ```$ xcode-select --install```
- Windows 10: This is incredibly tedious, but for now this is the solution:
  - Enable Developer Mode through Windows Control Panel
  - Enable Windows Subsystem for Linux feature through Windows Control Panel
  - Install Bash on Ubuntu on Windows
  - Open Bash and do the following:
    - ```sudo apt-get update && sudo apt-get install -y build-essential git cmake```

#### Build Instructions
- Clone the project recursively to check out submodules
  - ```$ git clone https://github.com/nicholaschiasson/N3DIL.git --recursive```
- Create a build directory for CMake to do its work, then go to that directory
  - ```$ mkdir N3DIL/build```
  - ```$ cd N3DIL/build```
- Refer to [Dependencies](#dependencies) before proceeding
- Run CMake to build the project - feel free to build any project type you want
  - ```$ cmake ..```

#### Dependencies
- Debian/Ubuntu/Mint:
  - ```$ sudo apt-get install -y libxmu-dev libxi-dev libgl-dev libgl1-mesa-dev libglu1-mesa-dev```
- RedHat/CentOS/Fedora:
  - ```$ sudo yum install -y libXmu-devel libXi-devel libGL-devel mesa-libGL-devel mesa-libGLU-devel```
- Mac OS X:
  - ```$ brew install Caskroom/cask/xquartz```

#### Notes
- The project has been tested using the GCC and MSVC compilers
- Building the project currently requires bash to build glew, therefore the only way to build the project on Windows is with Windows 10, with developer mode enabled, and with Windows Subsystem for Linux enabled
- When building a project for Visual Studio, run in release mode
  - Some bug exists when running in debug mode where the application appears to run normally, but meshes are not rendered at all
- Mac OS X is not actually supported
  - The project can be built on Mac OS X but requires CMake to be run with a flag to include the Core Foundation framework and then some manual modification to the CMakeCache.txt file after generating the project in order to properly link GL, GLU, and X11
  - Beyond that, the executable actually throws an obscure runtime exception whose cause is still unknown, meaning the project is completely broken for Mac OS X
