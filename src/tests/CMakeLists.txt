# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	catch.hpp
	Avaliacoes.h
	Cliente.h
	Dados.h
	Hospede.h
	Hotel.h
 	Pagamentos.h
 	Pessoa.h
	Quarto.h
	Quarto_Luxo.h
	Quarto_Simples.h
	Quarto_Suite.h
	Reserva.h
)

set(SOURCE_FILES	
	tests.cpp
)

set(LIBRARY_NAME Include)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests ${LIBRARY_NAME})
