#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>
#include "veterinario.h"
#include "tratador.h"

using namespace std;



class Animal{
	private:
		int m_id;
		string m_classe;
		string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		string m_dieta;
		Veterinario m_veterinario;
		Tratador m_tratador;
	protected:

	public:
		Animal();
		Animal(/*parâmetros*/);
		~Animal();

};


#endif // _ANIMAL_H_