# ForceD3D9On12

### Introduction
This project provides DLL wrappers for the DirectX 1-9 graphics components. Its purpose is to disable the use of the Direct3D 9 user-mode display driver provided by GPU vendors. This forces the runtimes to use [D3D9On12](https://github.com/microsoft/D3D9On12) instead.

It may fix some driver-specific issues, and it may introduce a lot of others. Don't be surprised if many games have graphics or performance issues, or just plain crash with this.

D3D9On12 is a completely independent project. No support will be provided for it here.

### Requirements
- Windows 10 or 11
- DirectX 12 compatible GPU (feature level 11_0 or better)

### Installation

Download the latest binary release from the [releases](https://github.com/narzoul/ForceD3D9On12/releases) page. Unzip the file and copy the extracted DLLs from either the x86 folder (for 32-bit applications) or the x64 folder (for 64-bit applications) to the target application's install directory, next to where the main executable (.exe) file is located.

[D3D9On12](https://github.com/microsoft/D3D9On12) should be preinstalled on Windows 10/11. Alternatively, it could be built from source following the instructions on its page.

### Uninstallation
Delete the previously copied DLLs from the application's directory.

### Development
ForceD3D9On12 is developed in C++ using Microsoft Visual Studio Community 2022.

### License
Licensed under the [BSD Zero Clause License](LICENSE.txt).
