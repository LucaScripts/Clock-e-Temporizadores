# Define a versão mínima necessária do CMake para este projeto
cmake_minimum_required(VERSION 3.13)

# Define os padrões de linguagem C e C++
set(CMAKE_C_STANDARD 11)   # Usa a versão C11
set(CMAKE_CXX_STANDARD 17) # Usa a versão C++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Exporta os comandos de compilação

# ==============================
# Configuração específica para o VS Code com Raspberry Pi Pico
# ==============================

# Verifica o sistema operacional para definir o diretório do usuário
if(WIN32)
    set(USERHOME $ENV{USERPROFILE}) # Para Windows
else()
    set(USERHOME $ENV{HOME})        # Para Linux/Mac
endif()

# Define as versões das ferramentas usadas
set(sdkVersion 2.1.0)          # Versão do SDK do Pico
set(toolchainVersion 13_3_Rel1) # Versão do Toolchain do compilador
set(picotoolVersion 2.1.0)      # Versão do picotool

# Configuração do caminho do VS Code para o Pico SDK
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode}) # Inclui o arquivo de configuração se existir
endif()

# ==============================
# Definição da placa usada (Raspberry Pi Pico W)
# ==============================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# ==============================
# Configuração do projeto
# ==============================
# Nome do projeto e linguagens utilizadas
project(Clock_temporizador C CXX ASM)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()

# ==============================
# Configuração do executável
# ==============================
# Define o nome do executável e o arquivo-fonte principal
add_executable(Clock_temporizador Clock_temporizador.c)

# Define o nome do programa e a versão
pico_set_program_name(Clock_temporizador "Clock_temporizador")
pico_set_program_version(Clock_temporizador "0.1")

# ==============================
# Configuração de saída do programa (UART e USB)
# ==============================
# Ativa a saída de depuração via UART (porta serial)
pico_enable_stdio_uart(Clock_temporizador 1)

# Ativa a saída de depuração via USB (para comunicação com o computador)
pico_enable_stdio_usb(Clock_temporizador 1)

# ==============================
# Inclusão de bibliotecas e dependências
# ==============================
# Adiciona a biblioteca padrão do Raspberry Pi Pico
target_link_libraries(Clock_temporizador
        pico_stdlib)

# Adiciona os diretórios de inclusão (headers) ao projeto
target_include_directories(Clock_temporizador PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Adiciona a biblioteca de temporizadores do Raspberry Pi Pico
target_link_libraries(Clock_temporizador 
        hardware_timer
)

# Gera os arquivos binários adicionais necessários para a programação do Pico
pico_add_extra_outputs(Clock_temporizador)
