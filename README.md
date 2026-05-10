# ROBOTIEEE Compkit

## Como instalar no Arduino IDE para usuários

> Se você estiver usando o Arduino IDE, você pode instalar o Compkit facilmente através do Gerenciador de Bibliotecas. [Compkit na página oficial do Arduino](https://docs.arduino.cc/libraries/compkit/)

1. Abra o Arduino IDE
2. Abra o Gerenciador de Bibliotecas
3. Procure por "Compkit"
4. Clique em "Instalar"

## Primeiros passos para desenvolvedores

1. Clone o repositório

```bash
git clone https://github.com/robotieee/compkit.git
```

2. Instale o PlatformIO Core (CLI)

[PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html)

```bash
pip install platformio
```

3. Instale o PlatformIO IDE (VS Code com a extensão PlatformIO)

[PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/vscode.html)

4. Instale as extensões recomendadas

Consulte o arquivo `.vscode/extensions.json` para ver as extensões recomendadas.

> Ao abrir o projeto no VS Code, as extensões a instalar serão sugeridas automaticamente.

5. Execute os comandos para instalar as dependências e compilar o projeto

```bash
pio install
pio run -e esp32dev --target compiledb
```
