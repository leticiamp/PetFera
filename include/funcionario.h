#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>

using namespace std;

class Funcionario{
	private:
		int m_id;
		string m_nome;
		string m_cpf;
		short m_idade;
		short m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;
		
	protected:

	public:
		Funcionario();
		~Funcionario();

		// type method(type);
		// type method(type);

};


#endif // _FUNCIONARIO_H_