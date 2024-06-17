# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	 Pessoa.h
	 Avaliacao.h
	 Cliente.h
	 Hospede.h
	 Hotel.h
	 Pagamento.h
	 Quarto.h
	 Quarto_Luxo.h
	 Quarto_Simples.h
	 Quarto_Suite.h
	 Reserva.h
	 Dados.h
)

set(SOURCE_FILES
	Pessoa.cpp
	Avaliacao.cpp
	Cliente.cpp
	Hospede.cpp
	Hotel.cpp
	Pagamento.cpp
	Quarto.cpp
	Quarto_Luxo.cpp
	Quarto_Simples.cpp
	Quarto_Suite.cpp
	Reserva.cpp
	Dados.cpp

)
add_library(Include ${SOURCE_FILES} ${HEADER_FILES})
