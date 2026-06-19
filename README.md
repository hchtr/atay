# Atay Rendering Layer

The name **Atay** (أتاي, pronounced "ah-tay") is the Moroccan Arabic word for "tea", which perfectly fits the project's minimalist and refreshing approach.
  
## Getting Started

### Clone
This project uses Git submodules for dependencies. To clone the repository, use:

```bash
git clone --recursive git@github.com:hchtr/atay.git
```

### Configure
Choose between the **Debug** or **Release** CMake presets:

```bash
# Debug
cmake --preset Debug

# Release
cmake --preset Release
```

### Build
Once configured, initiate the *Ninja* generator using the corresponding preset:

```bash
# Debug
cmake --build --preset Debug

# Release
cmake --build --preset Release
```
