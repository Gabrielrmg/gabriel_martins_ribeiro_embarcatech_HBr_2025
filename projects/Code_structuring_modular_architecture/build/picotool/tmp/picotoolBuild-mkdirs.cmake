# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/_deps/picotool-src"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/_deps/picotool-build"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/_deps"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/tmp"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/src/picotoolBuild-stamp"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/src"
  "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Repositorios/gabriel_martins_ribeiro_embarcatech_HBr_2025/projects/Code_structuring_modular_architecture/build/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
