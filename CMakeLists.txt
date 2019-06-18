CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(MeuProjeto)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/)
ADD_EXECUTABLE(main src/main.cpp
              src/funcionario.cpp
              src/tratador.cpp
              src/veterinario.cpp
              src/animal.cpp
              src/anfibio.cpp
              src/anfibioExotico.cpp
              src/anfibioNativo.cpp
              src/animalExotico.cpp
              src/animalNativo.cpp
              src/animalSilvestre.cpp
              src/mamifero.cpp
              src/mamiferoExotico.cpp
              src/mamiferoNativo.cpp
              src/reptil.cpp
              src/reptilExotico.cpp
              src/reptilNativo.cpp
              src/ave.cpp
              src/aveExotico.cpp
              src/aveNativo.cpp
              src/system.cpp
)
