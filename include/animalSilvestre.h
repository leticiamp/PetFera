#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

using namespace std;

class AnimalSilv{
	private:
		string m_autorizacao_ibama;
		/* Certamente é erro duplicar. Assim, consta
		no PDF. Verificar com o Prof. */
	protected:

	public:
		AnimalSilv();
		~AnimalSilv();
};

#endif // _ANIMAL_SILVESTRE_H_