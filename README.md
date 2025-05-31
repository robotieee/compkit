# esp32.pio.template

Template with developer experience setup. PlatformIO + Cpp + CI/CD + Linter + Formatter.

> If the codebase using this template is not a library, remove the files: `library.json`, `build_test.cpp`, `.github/workflows/publish.yml`.

## Getting Started

1. Clone the repository

```bash
git clone https://github.com/platformio/esp32.pio.template.git
```

2. Install PlatformIO Core (CLI)

[PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html)

```bash
pip install platformio
```

3. Install PlatformIO IDE (VSCode with PlatformIO Extension)

[PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/vscode.html)

4. Install the recommended extensions

Look at the `.vscode/extensions.json` file to see the recommended extensions.

> When you open the project in VSCode, it will automatically show the extensions to install.

5. Run the commands to install the dependencies and build the project

```bash
pio install
pio run -e esp32dev --target compiledb
```
