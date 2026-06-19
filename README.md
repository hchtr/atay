# atay

C project focused on building a clean, performant rendering layer from scratch using [SDL](https://www.libsdl.org/).

## Developer Tooling

* **Language Standard:** C17
* **Build System:** CMake with Ninja
* **LSP Support:** Automatically links `compile_commands.json` to the root directory for seamless clangd/LSP detection
  
## Getting Started

### Clone
This project uses Git submodules for dependencies. To clone the repository and fetch SDL, use:

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
