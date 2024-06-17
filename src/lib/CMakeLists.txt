# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
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
	 Avaliacoes.cpp
	 Cliente.cpp
	 Dados.cpp
	 Hospede.cpp
	 Hotel.cpp
 	 Pagamentos.cpp
 	 Pessoa.cpp
	 Quarto.cpp
	 Quarto_Luxo.cpp
	 Quarto_Simples.cpp
	 Quarto_Suite.cpp
	 Reserva.cpp

)
add_library(Include ${SOURCE_FILES} ${HEADER_FILES})
