CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(MeuProjeto)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/animal
                    include/anfibio/
                    include/ave/
                    include/reptil/
                    include/funcionario/
                    include/mamifero/
                    include/system/)
ADD_EXECUTABLE(main src/system/main.cpp
              src/funcionario/funcionario.cpp
              src/funcionario/tratador.cpp
              src/funcionario/veterinario.cpp
              src/animal/animal.cpp
              src/anfibio/anfibio.cpp
              src/anfibio/anfibioExotico.cpp
              src/anfibio/anfibioNativo.cpp
              src/animal/animalExotico.cpp
              src/animal/animalNativo.cpp
              src/animal/animalSilvestre.cpp
              src/mamifero/mamifero.cpp
              src/mamifero/mamiferoExotico.cpp
              src/mamifero/mamiferoNativo.cpp
              src/reptil/reptil.cpp
              src/reptil/reptilExotico.cpp
              src/reptil/reptilNativo.cpp
              src/ave/ave.cpp
              src/ave/aveExotico.cpp
              src/ave/aveNativo.cpp
              src/system/system.cpp
)
