# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/gmr/pico-sdk/tools/pioasm"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pioasm"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pioasm-install"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
