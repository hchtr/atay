# atay

a C project focused on building a clean, performant rendering layer from scratch using [SDL](https://www.libsdl.org/).

## Getting Started

### Clone
This project uses Git submodules for dependencies. To clone the repository and fetch SDL, use:

```bash
git clone --recursive git@github.com:hchtr/atay.git
```

### Configure
Choose between the **Debug** or **Release** CMake presets:

```bash
# configure Debug build
cmake --preset Debug

# configure Release build
cmake --preset Release
```

### Build
Once configured, initiate the *Ninja* build system using the corresponding preset:

```bash
# build Debug binary
cmake --build --preset Debug

# build Release binary
cmake --build --preset Release
```
