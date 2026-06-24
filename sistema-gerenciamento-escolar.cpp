#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

struct Alunos {
	int matricula = {};
	std::string nome_completo = {};
	std::string data_nascimento = {};
	
	std::string contado_responsavel[3][1] = {
		{}, //nome
		{}, //contato
		{} //gmail
	};
	
	float notas[7][3] = {
		{0, 0, 0}, //portugues
		{0, 0, 0}, //matematica
		{0, 0, 0}, //ciencias
		{0, 0, 0}, //historia
		{0, 0, 0}, //geografia
		{0, 0, 0}, //fisica
		{0, 0, 0} //filosofia
	};
	
	float mediasNotas[7][1] = {
		{0}, //portugues
		{0}, //matematica
		{0}, //ciencias
		{0}, //historia
		{0}, //geografia
		{0}, //fisica
		{0} //filosofia
	};
	
	float media_geral = {};
};

void relatorio_turma(std::vector<Alunos>& aluno){
	int final = aluno.size() - 1;
	float media_geral_escolar = {};
	int acimaDa_media = 0;
	int abaixoDa_media = 0;
	
	for(int i = 0; i < aluno.size(); i++){
		media_geral_escolar = aluno[i].media_geral;
		
		if(aluno[i].media_geral >= 6){
			acimaDa_media += 1;
		}
			else{
				abaixoDa_media += 1;
			}
	}
	
	media_geral_escolar = media_geral_escolar / aluno.size();
	
	std::cout<<"╔════════════════════════════════════════"<<std::endl;
	std::cout<<"║  RELATÓRIO DE DESEMPENHO - GERAL       "<<std::endl;
	std::cout<<"╠════════════════════════════════════════"<<std::endl;
	std::cout<<"║                                        "<<std::endl;
	std::cout<<"║ 1."<<aluno[final].nome_completo<<" - "<<"Média: "<<aluno[final].media_geral<<std::endl;
	std::cout<<"║ 2."<<aluno[final - 1].nome_completo<<" - "<<"Média: "<<aluno[final - 1].media_geral<<std::endl;
	std::cout<<"║ 3."<<aluno[final - 2].nome_completo<<" - "<<"Média: "<<aluno[final - 2].media_geral<<std::endl;
	std::cout<<"║                                        "<<std::endl;
	std::cout<<"║ ESTATÍSTICAS:                          "<<std::endl;
	std::cout<<"║ ├─ Média geral: "<<media_geral_escolar<<std::endl;
	std::cout<<"║ ├─ Aluno com melhor nota: "<<aluno[final].nome_completo<<std::endl;
	std::cout<<"║ ├─ Aluno com pior nota: "<<aluno[0].nome_completo<<std::endl;
	std::cout<<"║ ├─ Alunos acima da média: "<<acimaDa_media<<std::endl;
	std::cout<<"║ └─ Alunos abaixo da média: "<<abaixoDa_media<<std::endl;
	std::cout<<"╚════════════════════════════════════════"<<std::endl;
}

void lista_por_media (std::vector<Alunos>& aluno){
	int contador = 1;
	
	std::cout<<"╔════════════════════════════════════════"<<std::endl;
	std::cout<<"║  ALUNOS ORDENADOS POR MÉDIA            "<<std::endl;
	std::cout<<"╠════════════════════════════════════════"<<std::endl;
	
	for(int i = aluno.size() - 1; i >= 0; i--){
		std::cout<<"║ "<<contador<<". "<<aluno[i].nome_completo<<" - Média: "<<aluno[i].media_geral<<std::endl;
		contador++;
	}
	
	std::cout<<"╚════════════════════════════════════════"<<std::endl;
}

void merge (std::vector<Alunos>& aluno, int esquerda, int meio, int direita){
	
	int i, j, k;
	int n1 = meio - esquerda + 1;
	int n2 = direita - meio;
	
	std::vector<Alunos> esquerdaVec(n1), direitaVec(n2);
	
	for(int i = 0; i < n1; i++){
		esquerdaVec[i] = aluno[esquerda + i];
	}
	for(int j = 0; j < n2; j++){
		direitaVec[j] = aluno[meio + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = esquerda;
	
	while(i < n1 && j < n2){
		
		if(esquerdaVec[i].media_geral <= direitaVec[j].media_geral){
			aluno[k] = esquerdaVec[i];
			i++;
		}
			else{
				aluno[k] = direitaVec[j];
				j++;
			}
		k++;
	}
	
	while(i < n1){
		aluno[k] = esquerdaVec[i];
		i++;
		k++;
	}
	
	while(j < n2){
		aluno[k] = direitaVec[j];
		j++;
		k++;
	}
}

void mergeSort (std::vector<Alunos>& aluno, int esquerda, int direita){
	
	if (esquerda < direita){
		int meio = esquerda + (direita - esquerda) / 2;
		
		mergeSort (aluno, esquerda, meio);
		mergeSort (aluno, meio + 1, direita);
		
		merge(aluno, esquerda, meio, direita);
	}
}

void cadastrarAluno(std::vector<Alunos>& aluno, int &Qte) {
	
	std::string nome, data, responsavel, responsavel_contato, responsavel_gmail;
	int opcao;
	
	Alunos novoAluno; //struct temporario para criar a ficha do aluno
	
	std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
	std::cout<<"║   SISTEMA DE CADASTRO DE ALUNOS    ║"<<std::endl;
	std::cout<<"╚════════════════════════════════════╝"<<std::endl;
	
	while(true){
		std::cin.ignore();
		//ADICIONAR O NOME DO ALUNO
		std::cout<<"Aluno: "<<Qte<<std::endl;
		std::cout<<"Nome completo do aluno: ";
		std::getline(std::cin, nome);
		
		novoAluno.nome_completo = nome;
		
		//ADICIONAR A DATA DE NASCIMENTO
		std::cout<<"Data de nascimento do aluno (digite em digitos '__/__/____'): ";
		std::cin>>data;
		
		novoAluno.data_nascimento = data;
		
		//ADICIONAR O NOME DO RESPONSÁVEL
		std::cout<<"Nome do responsável do aluno (Primeiro nome): ";
		std::cin>>responsavel;
		
		novoAluno.contado_responsavel[0][0] = responsavel;
		
		//ADICIONAR O CONTATO NO RESPONSAVEL 
		std::cout<<"Contato do responsável do aluno (deixe os números juntos): ";
		std::cin>>responsavel_contato;
		
		novoAluno.contado_responsavel[1][0] = responsavel_contato;
		
		//ADICIONAR O GMAIL DO RESPONSAVEL
		std::cout<<"Gmail do responsável do aluno: ";
		std::cin>>responsavel_gmail;
		
		novoAluno.contado_responsavel[2][0] = responsavel_gmail;
		
		//ADICIONAR MATRICULA
		std::cout<<"Matrícula: "<<Qte + 2026<<std::endl;
		
		novoAluno.matricula = Qte + 2026;
		
		//ADICIONAR O STRUCT NO VECTOR
		aluno.push_back(novoAluno);
		
		std::cout<<"Deseja continuar? [0 para não / digite outro numero para continuar]: ";
		std::cin>>opcao;
		
		Qte += 1;
		
		if(opcao == 0){
			break;
			
			std::cout<<std::endl<<std::endl;
		}
		
		std::cout<<std::endl<<std::endl;
		
		continue;
	}
}

void listarAlunos (std::vector<Alunos>& aluno, bool &mostrarMedias) {
	
	if(aluno.size() == 0){
		std::cout<<"Não tem alunos cadastrados para listar."<<std::endl;
	}
	
	if(mostrarMedias == false){
		for(int a = 0; a < aluno.size(); a++){
		std::cout<<"\n╔═══════════════════════════════════════════"<<std::endl;
		std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
		std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
		std::cout<<"╠════════════════════════════════════════════"<<std::endl;
		std::cout<<"║ Data de nascimento: "<<aluno[a].data_nascimento<<std::endl;
		std::cout<<"║ Nome do responsável: "<<aluno[a].contado_responsavel[0][0]<<std::endl;
		std::cout<<"║ Contato do responsável: "<<aluno[a].contado_responsavel[1][0]<<std::endl;
		std::cout<<"║ Gmail do responsável: "<<aluno[a].contado_responsavel[2][0]<<std::endl;
		std::cout<<"║ Notas de Português: "<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<< aluno[a].notas[0][2]<<std::endl;
		std::cout<<"║ Notas de Matemática: "<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<< aluno[a].notas[1][2]<<std::endl;
		std::cout<<"║ Notas de Ciências: "<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<< aluno[a].notas[2][2]<<std::endl;
		std::cout<<"║ Notas de História: "<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<< aluno[a].notas[3][2]<<std::endl;
		std::cout<<"║ Notas de Geografia: "<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<< aluno[a].notas[4][2]<<std::endl;
		std::cout<<"║ Notas de Física: "<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<< aluno[a].notas[5][2]<<std::endl;
		std::cout<<"║ Notas de Filosofia: "<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<< aluno[a].notas[6][2]<<std::endl;
		std::cout<<"╚════════════════════════════════════════════"<<std::endl;
		}
	}
		else if(mostrarMedias == true){
			for(int a = 0; a < aluno.size(); a++){
			std::cout<<"\n╔═══════════════════════════════════════════"<<std::endl;
			std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
			std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
			std::cout<<"╠════════════════════════════════════════════"<<std::endl;
			std::cout<<"║ Média de Português: "<<aluno[a].mediasNotas[0][0]<<std::endl;
			std::cout<<"║ Média de Matemática: "<<aluno[a].mediasNotas[1][0]<<std::endl;
			std::cout<<"║ Média de Ciências: "<<aluno[a].mediasNotas[2][0]<<std::endl;
			std::cout<<"║ Média de História: "<<aluno[a].mediasNotas[3][0]<<std::endl;
			std::cout<<"║ Média de Geografia: "<<aluno[a].mediasNotas[4][0]<<std::endl;
			std::cout<<"║ Média de Física: "<<aluno[a].mediasNotas[5][0]<<std::endl;
			std::cout<<"║ Média de Filosofia: "<<aluno[a].mediasNotas[6][0]<<std::endl;
			std::cout<<"╚════════════════════════════════════════════"<<std::endl;
			}
			
			mostrarMedias = false;
		}	
}

void buscarNome (std::vector<Alunos>& aluno, bool &adicionarNota, int disciplina) {
	bool alunoEncontrado = false;
	std::string nome;
	int opcao, unidade;
	float nota;
	
	//Parte da buscar sem alterar a nota
	if(adicionarNota == false){
		
		while(true){
			std::cin.ignore();
			std::cout<<"Nome do aluno: ";
			std::getline(std::cin, nome);
			
			for(int a = 0; a < aluno.size(); a++){
				if(aluno[a].nome_completo == nome){
					alunoEncontrado = true;
					
					std::cout<<"\n╔════════════════════════════════════════════"<<std::endl;
					std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
					std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
					std::cout<<"╠════════════════════════════════════════════"<<std::endl;
					std::cout<<"║ Data de nascimento: "<<aluno[a].data_nascimento<<std::endl;
					std::cout<<"║ Nome do responsável: "<<aluno[a].contado_responsavel[0][0]<<std::endl;
					std::cout<<"║ Contato do responsável: "<<aluno[a].contado_responsavel[1][0]<<std::endl;
					std::cout<<"║ Gmail do responsável: "<<aluno[a].contado_responsavel[2][0]<<std::endl;
					std::cout<<"║ Notas de Português: "<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<< aluno[a].notas[0][2]<<std::endl;
					std::cout<<"║ Notas de Matemática: "<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<< aluno[a].notas[1][2]<<std::endl;
					std::cout<<"║ Notas de Ciências: "<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<< aluno[a].notas[2][2]<<std::endl;
					std::cout<<"║ Notas de História: "<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<< aluno[a].notas[3][2]<<std::endl;
					std::cout<<"║ Notas de Geografia: "<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<< aluno[a].notas[4][2]<<std::endl;
					std::cout<<"║ Notas de Física: "<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<< aluno[a].notas[5][2]<<std::endl;
					std::cout<<"║ Notas de Filosofia: "<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<< aluno[a].notas[6][2]<<std::endl;
					std::cout<<"╚════════════════════════════════════════════"<<std::endl;
				}
			}
			
			if(alunoEncontrado == false){
				std::cout<<"O aluno não foi localizado, gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
				std::cin>>opcao;
				
				if(opcao == 0){
						break;
					}
						else{
							continue;
						}
			}
				else{
					std::cout<<"Gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
					std::cin>>opcao;
					
					if(opcao == 0){
						break;
					}
						else{
							alunoEncontrado = false;
							continue;
						}
				}	
		}
	}
		//caso a função tenha sido chamada para alterar/adicionar nota
		else if(adicionarNota == true){
			
			std::cin.ignore();
			std::cout<<"Nome do aluno: ";
			std::getline(std::cin, nome);
			
			for(int a = 0; a < aluno.size(); a++){
				
				if(aluno[a].nome_completo == nome){
					
					alunoEncontrado = true;
					
					std::cout<<"\n╔═══════════════════════════════════════════"<<std::endl;
					std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
					std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
					std::cout<<"╚════════════════════════════════════════════"<<std::endl;
					
					switch(disciplina){
						case 0:
							std::cout<<"Notas de português: ";
							std::cout<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<<aluno[a].notas[0][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[0][0] = std::round(((aluno[a].notas[0][0] + aluno[a].notas[0][1] + aluno[a].notas[0][2]) / 3) * 100.0) / 100.0;
							break;
						case 1:
							std::cout<<"Notas de matemática: ";
							std::cout<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<<aluno[a].notas[1][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[1][0] = std::round(((aluno[a].notas[1][0] + aluno[a].notas[1][1] + aluno[a].notas[1][2]) / 3) * 100.0) / 100.0;
							break;
						case 2:
							std::cout<<"Notas de ciências: ";
							std::cout<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<<aluno[a].notas[2][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[2][0] = std::round(((aluno[a].notas[2][0] + aluno[a].notas[2][1] + aluno[a].notas[2][2]) / 3) * 100.0) / 100.0;
							break;
						case 3:
							std::cout<<"Notas de história: ";
							std::cout<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<<aluno[a].notas[3][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[3][0] = std::round(((aluno[a].notas[3][0] + aluno[a].notas[3][1] + aluno[a].notas[3][2]) / 3) * 100.0) / 100.0;
							break;
						case 4:
							std::cout<<"Notas de geografia: ";
							std::cout<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<<aluno[a].notas[4][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[4][0] = std::round(((aluno[a].notas[4][0] + aluno[a].notas[4][1] + aluno[a].notas[4][2]) / 3) * 100.0) / 100.0;
							break;
						case 5:
							std::cout<<"Notas de física: ";
							std::cout<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<<aluno[a].notas[5][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[5][0] = std::round(((aluno[a].notas[5][0] + aluno[a].notas[5][1] + aluno[a].notas[5][2]) / 3) * 100.0) / 100.0;
							break;
						case 6:
							std::cout<<"Notas de filosofia: ";
							std::cout<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<<aluno[a].notas[6][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[6][0] = std::round(((aluno[a].notas[6][0] + aluno[a].notas[6][1] + aluno[a].notas[6][2]) / 3) * 100.0) / 100.0;
							break;
					}
					
					aluno[a].media_geral = ((aluno[a].mediasNotas[0][0]) + (aluno[a].mediasNotas[1][0]) + (aluno[a].mediasNotas[2][0]) + (aluno[a].mediasNotas[3][0]) + (aluno[a].mediasNotas[4][0]) + (aluno[a].mediasNotas[5][0]) + (aluno[a].mediasNotas[6][0])) / 7;
					aluno[a].media_geral = std::round(aluno[a].media_geral * 100.0) / 100.0;
				}
			}
		}
}

void buscarMatricula (std::vector<Alunos>& aluno, bool &adicionarNota, int disciplina) {
	
	bool alunoEncontrado = false;
	int opcao, numero_matricula;
	float nota;
	
	if(adicionarNota == false){
		while(true){
		
		std::cout<<"Número da matricula: ";
		std::cin>>numero_matricula;
		
		for(int a = 0; a < aluno.size(); a++){
			
			if(aluno[a].matricula == numero_matricula){
				
				alunoEncontrado = true;
				
				std::cout<<"\n╔════════════════════════════════════════════"<<std::endl;
				std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
				std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
				std::cout<<"╠════════════════════════════════════════════"<<std::endl;
				std::cout<<"║ Data de nascimento: "<<aluno[a].data_nascimento<<std::endl;
				std::cout<<"║ Nome do responsável: "<<aluno[a].contado_responsavel[0][0]<<std::endl;
				std::cout<<"║ Contato do responsável: "<<aluno[a].contado_responsavel[1][0]<<std::endl;
				std::cout<<"║ Gmail do responsável: "<<aluno[a].contado_responsavel[2][0]<<std::endl;
				std::cout<<"║ Notas de Português: "<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<< aluno[a].notas[0][2]<<std::endl;
				std::cout<<"║ Notas de Matemática: "<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<< aluno[a].notas[1][2]<<std::endl;
				std::cout<<"║ Notas de Ciências: "<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<< aluno[a].notas[2][2]<<std::endl;
				std::cout<<"║ Notas de História: "<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<< aluno[a].notas[3][2]<<std::endl;
				std::cout<<"║ Notas de Geografia: "<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<< aluno[a].notas[4][2]<<std::endl;
				std::cout<<"║ Notas de Física: "<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<< aluno[a].notas[5][2]<<std::endl;
				std::cout<<"║ Notas de Filosofia: "<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<< aluno[a].notas[6][2]<<std::endl;
				std::cout<<"╚════════════════════════════════════════════"<<std::endl;
			}
		}
		
		if(alunoEncontrado == false){
			
			std::cout<<"O aluno não foi localizado, gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
			std::cin>>opcao;
			
			if(opcao == 0){
					break;
				}
					else{
						continue;
					}
		}
			else{
				std::cout<<"Gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
				std::cin>>opcao;
				
				if(opcao == 0){
					break;
				}
					else{
						alunoEncontrado = false;
						continue;
					}
			}	
		}
	}
		else if(adicionarNota == true){
		
			std::cout<<"Número da matricula: ";
			std::cin>>numero_matricula;
			
			for(int a = 0; a < aluno.size(); a++){
				
				if(aluno[a].matricula == numero_matricula){
					
					alunoEncontrado = true;
					
					std::cout<<"\n╔═══════════════════════════════════════════"<<std::endl;
					std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
					std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
					std::cout<<"╚════════════════════════════════════════════"<<std::endl;
					
					switch(disciplina){
						case 0:
							std::cout<<"Notas de português: ";
							std::cout<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<<aluno[a].notas[0][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[0][0] = std::round(((aluno[a].notas[0][0] + aluno[a].notas[0][1] + aluno[a].notas[0][2]) / 3) * 100.0) / 100.0;
							break;
						case 1:
							std::cout<<"Notas de matemática: ";
							std::cout<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<<aluno[a].notas[1][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[1][0] = std::round(((aluno[a].notas[1][0] + aluno[a].notas[1][1] + aluno[a].notas[1][2]) / 3) * 100.0) / 100.0;
							break;
						case 2:
							std::cout<<"Notas de ciências: ";
							std::cout<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<<aluno[a].notas[2][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[2][0] = std::round(((aluno[a].notas[2][0] + aluno[a].notas[2][1] + aluno[a].notas[2][2]) / 3) * 100.0) / 100.0;
							break;
						case 3:
							std::cout<<"Notas de história: ";
							std::cout<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<<aluno[a].notas[3][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[3][0] = std::round(((aluno[a].notas[3][0] + aluno[a].notas[3][1] + aluno[a].notas[3][2]) / 3) * 100.0) / 100.0;
							break;
						case 4:
							std::cout<<"Notas de geografia: ";
							std::cout<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<<aluno[a].notas[4][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[4][0] = std::round(((aluno[a].notas[4][0] + aluno[a].notas[4][1] + aluno[a].notas[4][2]) / 3) * 100.0) / 100.0;
							break;
						case 5:
							std::cout<<"Notas de física: ";
							std::cout<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<<aluno[a].notas[5][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[5][0] = std::round(((aluno[a].notas[5][0] + aluno[a].notas[5][1] + aluno[a].notas[5][2]) / 3) * 100.0) / 100.0;
							break;
						case 6:
							std::cout<<"Notas de filosofia: ";
							std::cout<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<<aluno[a].notas[6][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[6][0] = std::round(((aluno[a].notas[6][0] + aluno[a].notas[6][1] + aluno[a].notas[6][2]) / 3) * 100.0) / 100.0;
							break;
					}
					
					aluno[a].media_geral = ((aluno[a].mediasNotas[0][0]) + (aluno[a].mediasNotas[1][0]) + (aluno[a].mediasNotas[2][0]) + (aluno[a].mediasNotas[3][0]) + (aluno[a].mediasNotas[4][0]) + (aluno[a].mediasNotas[5][0]) + (aluno[a].mediasNotas[6][0])) / 7;
					aluno[a].media_geral = std::round(aluno[a].media_geral * 100.0) / 100.0;
				}
			}
		}
	
}

void buscarresponsavel (std::vector<Alunos>& aluno, bool &adicionarNota, int disciplina) {
	bool alunoEncontrado = false;
	std::string responsavel = {};
	int opcao = {};
	float nota = {};
	
	if(adicionarNota == false){
		
		while(true){
		std::cout<<"Nome do responsável do aluno: ";
		std::cin>>responsavel;
		
		for(int a = 0; a < aluno.size(); a++){
			
			if(aluno[a].contado_responsavel[0][0] == responsavel){
				alunoEncontrado = true;
				
				std::cout<<"\n╔════════════════════════════════════════════"<<std::endl;
				std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
				std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
				std::cout<<"╠════════════════════════════════════════════"<<std::endl;
				std::cout<<"║ Data de nascimento: "<<aluno[a].data_nascimento<<std::endl;
				std::cout<<"║ Nome do responsável: "<<aluno[a].contado_responsavel[0][0]<<std::endl;
				std::cout<<"║ Contato do responsável: "<<aluno[a].contado_responsavel[1][0]<<std::endl;
				std::cout<<"║ Gmail do responsável: "<<aluno[a].contado_responsavel[2][0]<<std::endl;
				std::cout<<"║ Notas de Português: "<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<< aluno[a].notas[0][2]<<std::endl;
				std::cout<<"║ Notas de Matemática: "<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<< aluno[a].notas[1][2]<<std::endl;
				std::cout<<"║ Notas de Ciências: "<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<< aluno[a].notas[2][2]<<std::endl;
				std::cout<<"║ Notas de História: "<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<< aluno[a].notas[3][2]<<std::endl;
				std::cout<<"║ Notas de Geografia: "<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<< aluno[a].notas[4][2]<<std::endl;
				std::cout<<"║ Notas de Física: "<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<< aluno[a].notas[5][2]<<std::endl;
				std::cout<<"║ Notas de Filosofia: "<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<< aluno[a].notas[6][2]<<std::endl;
				std::cout<<"╚════════════════════════════════════════════"<<std::endl;
			}
		}
		
		if(alunoEncontrado == false){
			std::cout<<"O aluno não foi localizado, gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
			std::cin>>opcao;
			
			if(opcao == 0){
					break;
				}
					else{
						continue;
					}
		}
			else{
				std::cout<<"Gostaria de continuar a busca? [0 para não / digite outro numero para continuar]: ";
				std::cin>>opcao;
				
				if(opcao == 0){
					break;
				}
					else{
						alunoEncontrado = false;
						continue;
					}
			}	
		}
	}
		else if(adicionarNota == true){
			
			std::cout<<"Nome do responsável do aluno: ";
			std::cin>>responsavel;
			
			for(int a = 0; a < aluno.size(); a++){
				
				if(aluno[a].contado_responsavel[0][0] == responsavel){
					
					alunoEncontrado = true;
					
					std::cout<<"\n╔═══════════════════════════════════════════"<<std::endl;
					std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
					std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
					std::cout<<"╚════════════════════════════════════════════"<<std::endl;
					
					switch(disciplina){
						case 0:
							std::cout<<"Notas de português: ";
							std::cout<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<<aluno[a].notas[0][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[0][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[0][0] = std::round(((aluno[a].notas[0][0] + aluno[a].notas[0][1] + aluno[a].notas[0][2]) / 3) * 100.0) / 100.0;
							break;
						case 1:
							std::cout<<"Notas de matemática: ";
							std::cout<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<<aluno[a].notas[1][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[1][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[1][0] = std::round(((aluno[a].notas[1][0] + aluno[a].notas[1][1] + aluno[a].notas[1][2]) / 3) * 100.0) / 100.0;
							break;
						case 2:
							std::cout<<"Notas de ciências: ";
							std::cout<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<<aluno[a].notas[2][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[2][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[2][0] = std::round(((aluno[a].notas[2][0] + aluno[a].notas[2][1] + aluno[a].notas[2][2]) / 3) * 100.0) / 100.0;
							break;
						case 3:
							std::cout<<"Notas de história: ";
							std::cout<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<<aluno[a].notas[3][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[3][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[3][0] = std::round(((aluno[a].notas[3][0] + aluno[a].notas[3][1] + aluno[a].notas[3][2]) / 3) * 100.0) / 100.0;
							break;
						case 4:
							std::cout<<"Notas de geografia: ";
							std::cout<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<<aluno[a].notas[4][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[4][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[4][0] = std::round(((aluno[a].notas[4][0] + aluno[a].notas[4][1] + aluno[a].notas[4][2]) / 3) * 100.0) / 100.0;
							break;
						case 5:
							std::cout<<"Notas de física: ";
							std::cout<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<<aluno[a].notas[5][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[5][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[5][0] = std::round(((aluno[a].notas[5][0] + aluno[a].notas[5][1] + aluno[a].notas[5][2]) / 3) * 100.0) / 100.0;
							break;
						case 6:
							std::cout<<"Notas de filosofia: ";
							std::cout<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<<aluno[a].notas[6][2]<<std::endl;
							
							do{
								std::cout<<"Digite a nota da 1° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][0] = nota;
							
							do{
								std::cout<<"Digite a nota da 2° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][1] = nota;
							
							do{
								std::cout<<"Digite a nota da 3° Unidade: ";
								std::cin>>nota;
							}while((nota > 10) || (nota < 0));
							
							aluno[a].notas[6][2] = nota;
							
							std::cout<<"Notas adicionadas com sucesso!"<<std::endl;
							adicionarNota = false;
							
							aluno[a].mediasNotas[6][0] = std::round(((aluno[a].notas[6][0] + aluno[a].notas[6][1] + aluno[a].notas[6][2]) / 3) * 100.0) / 100.0;
							break;
					}
					
					aluno[a].media_geral = ((aluno[a].mediasNotas[0][0]) + (aluno[a].mediasNotas[1][0]) + (aluno[a].mediasNotas[2][0]) + (aluno[a].mediasNotas[3][0]) + (aluno[a].mediasNotas[4][0]) + (aluno[a].mediasNotas[5][0]) + (aluno[a].mediasNotas[6][0])) / 7;
					aluno[a].media_geral = std::round(aluno[a].media_geral * 100.0) / 100.0;
			}
		}
	}
}

void buscarAluno (std::vector<Alunos>& aluno, bool &adicionarNota, int disciplina){
	int opcao = {};
	
	std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
	std::cout<<"║            BUSCAR ALUNO            ║"<<std::endl;
	std::cout<<"╠════════════════════════════════════╣"<<std::endl;
	std::cout<<"║ Qual a forma de busca?             ║"<<std::endl;
	std::cout<<"╠════════════════════════════════════╣"<<std::endl;
	std::cout<<"║ 1. Nome do aluno                   ║"<<std::endl;
	std::cout<<"║ 2. Matrícula                       ║"<<std::endl;
	std::cout<<"║ 3. Nome do responsável             ║"<<std::endl;
	std::cout<<"╚════════════════════════════════════╝"<<std::endl;
	std::cout<<"║ Escolha uma opção acima: ";
	std::cin>>opcao;

	switch(opcao){
		case 1:
			buscarNome(aluno, adicionarNota, disciplina);
			break;
		case 2:
			buscarMatricula(aluno, adicionarNota, disciplina);
			break;
		case 3:
			buscarresponsavel(aluno, adicionarNota, disciplina);
			break;
		default:
			std::cout<<"Escolha uma opção válida!"<<std::endl;
			buscarAluno(aluno, adicionarNota, disciplina);
			break;
	}
}

void lancarNotas (std::vector<Alunos>& aluno, bool &adicionarNota) {
	int disciplina = {};
	
	while(true){
		std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
		std::cout<<"║            LANÇAR NOTAS            ║"<<std::endl;
		std::cout<<"╠════════════════════════════════════╣"<<std::endl;
		std::cout<<"║ Qual a disciplina?                 ║"<<std::endl;
		std::cout<<"╠════════════════════════════════════╣"<<std::endl;
		std::cout<<"║ 1. Português                       ║"<<std::endl;
		std::cout<<"║ 2. Matemática                      ║"<<std::endl;
		std::cout<<"║ 3. Ciências                        ║"<<std::endl;
		std::cout<<"║ 4. História                        ║"<<std::endl;
		std::cout<<"║ 5. Geografia                       ║"<<std::endl;
		std::cout<<"║ 6. Física                          ║"<<std::endl;
		std::cout<<"║ 7. Filosofia                       ║"<<std::endl;	
		std::cout<<"╚════════════════════════════════════╝"<<std::endl;
		std::cout<<"║ Escolha uma opção acima: ";
		std::cin>>disciplina;
		
		if((disciplina > 7) || (disciplina < 1)){
			std::cout<<"Selecione uma opção válida!"<<std::endl;
			continue;
		}
			else{
				adicionarNota = true;
				buscarAluno(aluno, adicionarNota, disciplina - 1);
				break;
			}
	}
}

void verMedia (std::vector<Alunos>& aluno, bool &mostrarMedias){
	mostrarMedias = true;
	
	listarAlunos(aluno, mostrarMedias);
}

void relatorioIndividual (std::vector<Alunos>& aluno){
	std::string nome = {};
	
	std::cin.ignore();
	std::cout<<"Nome completo do aluno: ";
	std::getline(std::cin, nome);
	
	for(int i = 0; i < aluno.size(); i++){
		
		if(aluno[i].nome_completo == nome){
			std::string status = {};
			std::string maior_media = {};
			std::string menor_media = {};
			
			int contador_de_0 = 0; //verificar se teve mais de uma matéria com nota 0
			
			float mediaP = (aluno[i].notas[0][0] + aluno[i].notas[0][1] + aluno[i].notas[0][2]) / 3;
			if(mediaP == 0){
				contador_de_0 += 1;
			}
			float mediaM = (aluno[i].notas[1][0] + aluno[i].notas[1][1] + aluno[i].notas[1][2]) / 3;
			if(mediaM == 0){
				contador_de_0 += 1;
			}
			float mediaC = (aluno[i].notas[2][0] + aluno[i].notas[2][1] + aluno[i].notas[2][2]) / 3;
			if(mediaC == 0){
				contador_de_0 += 1;
			}
			float mediaH = (aluno[i].notas[3][0] + aluno[i].notas[3][1] + aluno[i].notas[3][2]) / 3;
			if(mediaH == 0){
				contador_de_0 += 1;
			}
			float mediaG = (aluno[i].notas[4][0] + aluno[i].notas[4][1] + aluno[i].notas[4][2]) / 3;
			if(mediaG == 0){
				contador_de_0 += 1;
			}
			float mediaF = (aluno[i].notas[5][0] + aluno[i].notas[5][1] + aluno[i].notas[5][2]) / 3;
			if(mediaF == 0){
				contador_de_0 += 1;
			}
			float mediaFilo = (aluno[i].notas[6][0] + aluno[i].notas[6][1] + aluno[i].notas[6][2]) / 3;
			if(mediaFilo == 0){
				contador_de_0 += 1;
			}
			
			std::vector<float> lista_notas = {mediaP, mediaM, mediaC, mediaH, mediaG, mediaF, mediaFilo};
			
			std::sort(lista_notas.begin(), lista_notas.end());
			
			//verificar qual a melhor disciplina
			if(lista_notas.back() == mediaP){
				maior_media = "Português";
			}
				else if(lista_notas.back() == mediaM){
					maior_media = "Matemática";
				}
					else if(lista_notas.back() == mediaC){
						maior_media = "Ciências";
					}
						else if(lista_notas.back() == mediaH){
							maior_media = "História";
						}
							else if(lista_notas.back() == mediaG){
								maior_media = "Geografia";
							}
								else if(lista_notas.back() == mediaF){
									maior_media = "Fisíca";
								}
									else if(lista_notas.back() == mediaFilo){
										maior_media  = "Filosofia";
									}
									
			//verificar qual a pior disciplina
			if(contador_de_0 >= 2){
				menor_media = "Mais de uma matéria teve média igual a 0";
			}
				else{
					if(lista_notas[0] == mediaP){
					menor_media = "Português";
				}
					else if(lista_notas[0] == mediaM){
						menor_media = "Matemática";
					}
						else if(lista_notas[0] == mediaC){
							menor_media = "Ciências";
						}
							else if(lista_notas[0] == mediaH){
								menor_media = "História";
							}
								else if(lista_notas[0] == mediaG){
									menor_media = "Geografia";
								}
									else if(lista_notas[0] == mediaF){
										menor_media = "Fisíca";
									}
										else if(lista_notas[0] == mediaFilo){
											menor_media  = "Filosofia";
										}
				}
			
			//verificar status do aluno	
			if(aluno[i].media_geral >= 6){
				status = "Aprovado";
			}
				else{
					status = "Reprovado";
				}
			
			std::cout<<"╔════════════════════════════════════════"<<std::endl;
			std::cout<<"║  DESEMPENHO DO ALUNO: "<<nome<<std::endl;
			std::cout<<"╠════════════════════════════════════════"<<std::endl;
			std::cout<<"║ Matrícula:"<<aluno[i].matricula<<std::endl;
			std::cout<<"║ Responsável:"<<aluno[i].contado_responsavel[0][0]<<std::endl;
			std::cout<<"║"<<std::endl;
			std::cout<<"║ MÉDIA POR DISCIPLINA: "<<std::endl;
			std::cout<<"║ ├─ Português: "<<std::round(mediaP * 100.0) / 100.0<<std::endl;
			std::cout<<"║ ├─ Matemática: "<<std::round(mediaM * 100.0) / 100.0<<std::endl;
			std::cout<<"║ ├─ Ciências: "<<std::round(mediaC * 100.0) / 100.0<<std::endl;
			std::cout<<"║ ├─ História: "<<std::round(mediaH * 100.0) / 100.0<<std::endl;
			std::cout<<"║ ├─ Geografia: "<<std::round(mediaG * 100.0) / 100.0<<std::endl;
			std::cout<<"║ ├─ Física: "<<std::round(mediaF * 100.0) / 100.0<<std::endl;
			std::cout<<"║ └─ Filosofia: "<<std::round(mediaFilo * 100.0) / 100.0<<std::endl;
			std::cout<<"║"<<std::endl;
			std::cout<<"║ RESUMO:"<<std::endl;
			std::cout<<"║ Média Geral: "<<aluno[i].media_geral<<std::endl;
			std::cout<<"║ Melhor disciplina:"<<maior_media<<std::endl;
			std::cout<<"║ Pior disciplina:"<<menor_media<<std::endl;
			std::cout<<"║ Status:"<<status<<std::endl;
			std::cout<<"╚════════════════════════════════════════"<<std::endl;
		}
	}
}

void relatorioGeral (std::vector<Alunos>& aluno){
	bool ordenarMedia = false;
	
	mergeSort(aluno, 0, aluno.size() - 1);
	relatorio_turma(aluno);
}

void gerarRelatorioDeDesempenho (std::vector<Alunos>& aluno){
	bool Relatorio_Individual = {};
	int opcao = {};
	
	while(true){
		std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
		std::cout<<"║        SISTEMA DE RELATÓRIO        ║"<<std::endl;
		std::cout<<"╠════════════════════════════════════╣"<<std::endl;
		std::cout<<"║ Escolha uma das opções abaixo:     ║"<<std::endl;
		std::cout<<"║ 1. Relatório individual (aluno)    ║"<<std::endl;
		std::cout<<"║ 2. Relatório geral (sistema)       ║"<<std::endl;
		std::cout<<"╚════════════════════════════════════╝"<<std::endl;
		std::cout<<"║ Opção: ";
		std::cin>>opcao;
		
		if((opcao > 2) || (opcao < 1)){
			std::cout<<"Escolha uma opção válida!"<<std::endl;
			continue;
		}
			else if(opcao == 1){
				relatorioIndividual (aluno);
				break;
			}
				else if(opcao == 2){
					relatorioGeral (aluno);
					break;
				}
	}
}

void ordenar_por_media (std::vector<Alunos>& aluno){
	mergeSort(aluno, 0, aluno.size() - 1);
	lista_por_media(aluno);
}

void alterar_dados (std::vector<Alunos>& aluno, int posicao_do_aluno){
	int opcao = {};
	std::string alterar = {};
	
	std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
	std::cout<<"║     SISTEMA DE DADOS DO ALUNO      ║"<<std::endl;
	std::cout<<"╠════════════════════════════════════╣"<<std::endl;
	std::cout<<"║ Qual dado deseja alterar abaixo:   ║"<<std::endl;
	std::cout<<"║ 1. Alterar nome                    ║"<<std::endl;
	std::cout<<"║ 2. alterar data de nascimento      ║"<<std::endl;
	std::cout<<"║ 3. Nome do responsável             ║"<<std::endl;
	std::cout<<"║ 4. Número de contato               ║"<<std::endl;
	std::cout<<"║ 5. Gmail                           ║"<<std::endl;
	std::cout<<"╚════════════════════════════════════╝"<<std::endl;
	std::cout<<"║ Escolha uma opção acima: ";
	std::cin>>opcao;
	
	switch(opcao){
		case 1:
			std::cin.ignore();
			
			std::cout<<"Digite o nome do aluno: ";
			std::getline(std::cin, alterar);
			
			aluno[posicao_do_aluno].nome_completo = alterar;
			break;
		case 2:
			std::cout<<"Digite a data de nascimento do aluno (digite em digitos '__/__/____'): ";
			std::cin>>alterar;
			
			aluno[posicao_do_aluno].data_nascimento = alterar;
			break;
		case 3:
			std::cout<<"Digite o nome do responsável do aluno (primeiro nome): ";
			std::cin>>alterar;
			
			aluno[posicao_do_aluno].contado_responsavel[0][0] = alterar;
			break;
		case 4:
			std::cout<<"Digite numero de contato do responsável do aluno (deixe os números juntos): ";
			std::cin>>alterar;
			
			aluno[posicao_do_aluno].contado_responsavel[1][0] = alterar;
			break;
		case 5:
			std::cout<<"Digite o Gmail do responsável do aluno (primeiro nome): ";
			std::cin>>alterar;
			
			aluno[posicao_do_aluno].contado_responsavel[2][0] = alterar;
			break;
		default: 
			std::cout<<"Escolha uma opção válida"<<std::endl;
			
			alterar_dados(aluno, posicao_do_aluno);
			break;
	}
	
}

void editar_dados_de_aluno (std::vector<Alunos>& aluno){
	int posicao_do_aluno = {};
	
	std::cout<<"Qual a matrícula que deseja alterar os dados: ";
	std::cin>>posicao_do_aluno;
	
	for(int i = 0; i < aluno.size(); i++){
		
		if(posicao_do_aluno == aluno[i].matricula){
			std::cout<<"Aluno encontrado: "<<aluno[i].nome_completo<<std::endl;
			
			posicao_do_aluno = i; //ir direto no aluno sem precisar fazer outro for
			
			alterar_dados(aluno, posicao_do_aluno);
			break;
		}
			else if(i >= aluno.size() - 1){
				std::cout<<"Aluno não localizado"<<std::endl;
			}
	}
}

void confirmar_apagamento (std::vector<Alunos>& aluno, int a){
	int apagar_matricula = {};	

	std::cout<<"\n╔════════════════════════════════════════════"<<std::endl;
	std::cout<<"║ Matrícula "<<aluno[a].matricula<<std::endl;
	std::cout<<"║ Aluno: "<<aluno[a].nome_completo<<std::endl;
	std::cout<<"╠════════════════════════════════════════════"<<std::endl;
	std::cout<<"║ Data de nascimento: "<<aluno[a].data_nascimento<<std::endl;
	std::cout<<"║ Nome do responsável: "<<aluno[a].contado_responsavel[0][0]<<std::endl;
	std::cout<<"║ Contato do responsável: "<<aluno[a].contado_responsavel[1][0]<<std::endl;
	std::cout<<"║ Gmail do responsável: "<<aluno[a].contado_responsavel[2][0]<<std::endl;
	std::cout<<"║ Notas de Português: "<<aluno[a].notas[0][0]<<" | "<<aluno[a].notas[0][1]<<" | "<< aluno[a].notas[0][2]<<std::endl;
	std::cout<<"║ Notas de Matemática: "<<aluno[a].notas[1][0]<<" | "<<aluno[a].notas[1][1]<<" | "<< aluno[a].notas[1][2]<<std::endl;
	std::cout<<"║ Notas de Ciências: "<<aluno[a].notas[2][0]<<" | "<<aluno[a].notas[2][1]<<" | "<< aluno[a].notas[2][2]<<std::endl;
	std::cout<<"║ Notas de História: "<<aluno[a].notas[3][0]<<" | "<<aluno[a].notas[3][1]<<" | "<< aluno[a].notas[3][2]<<std::endl;
	std::cout<<"║ Notas de Geografia: "<<aluno[a].notas[4][0]<<" | "<<aluno[a].notas[4][1]<<" | "<< aluno[a].notas[4][2]<<std::endl;
	std::cout<<"║ Notas de Física: "<<aluno[a].notas[5][0]<<" | "<<aluno[a].notas[5][1]<<" | "<< aluno[a].notas[5][2]<<std::endl;
	std::cout<<"║ Notas de Filosofia: "<<aluno[a].notas[6][0]<<" | "<<aluno[a].notas[6][1]<<" | "<< aluno[a].notas[6][2]<<std::endl;
	std::cout<<"╚════════════════════════════════════════════"<<std::endl;
	std::cout<<"║ Deseja apagar este aluno? [1 - SIM / 0 - NÃO]: ";
	std::cin>>apagar_matricula;
	
	switch(apagar_matricula){
		case 1:
			std::swap(aluno[a], aluno[aluno.size() - 1]);
			aluno.pop_back();
			
			std::cout<<"Aluno deletado com sucesso!"<<std::endl;
			break;
		case 0:
			std::cout<<"O cancelamento foi encerrado!"<<std::endl;
			break;
		default:
			std::cout<<"Escolha uma opção válida"<<std::endl;
			confirmar_apagamento(aluno, a);
			break;
	}
}

void deletar_aluno (std::vector<Alunos>& aluno){
	int posicao_do_aluno = {};
	
	std::cout<<"Qual a matrícula que deseja apagar: ";
	std::cin>>posicao_do_aluno;
	
	for(int i = 0; i < aluno.size(); i++){
		
		if(posicao_do_aluno == aluno[i].matricula){
			std::cout<<"Aluno encontrado: "<<aluno[i].nome_completo<<std::endl;
			
			posicao_do_aluno = i; //ir direto no aluno sem precisar fazer outro for
			
			confirmar_apagamento(aluno, posicao_do_aluno);
			break;
		}
			else if(i >= aluno.size() - 1){
				std::cout<<"Aluno não localizado"<<std::endl;
			}
	}
}

void menuPrincipal(std::vector<Alunos>& aluno, int &Qte, bool &encerrarExecucao, bool& adicionarNota, bool &mostrarMedias) {
	int opcao = {};
	
	std::cout<<"\n╔════════════════════════════════════╗"<<std::endl;
	std::cout<<"║   SISTEMA DE REGISTRO DE ALUNOS    ║"<<std::endl;
	std::cout<<"╠════════════════════════════════════╣"<<std::endl;
	std::cout<<"║ 1. Cadastrar aluno                 ║"<<std::endl;
	std::cout<<"║ 2. Listar alunos                   ║"<<std::endl;
	std::cout<<"║ 3. Buscar aluno                    ║"<<std::endl;
	std::cout<<"║ 4. Lançar/Atualizar notas          ║"<<std::endl;
	std::cout<<"║ 5. Ver média dos alunos            ║"<<std::endl;
	std::cout<<"║ 6. Gerar relatório de desempenho   ║"<<std::endl;
	std::cout<<"║ 7. Alunos ordenados por média      ║"<<std::endl;
	std::cout<<"║ 8. Editar dados de aluno           ║"<<std::endl;
	std::cout<<"║ 9. Deletar aluno                   ║"<<std::endl;
	std::cout<<"║ 0. Sair                            ║"<<std::endl;
	std::cout<<"╚════════════════════════════════════╝"<<std::endl;
	std::cout<<"║ Escolha uma opção acima: ";
	std::cin>>opcao;
	
	switch(opcao){
		case 1:
			cadastrarAluno(aluno, Qte);
			break;
		case 2:
			listarAlunos(aluno, mostrarMedias);
			break;
		case 3:
			buscarAluno(aluno, adicionarNota, 0);
			break;
		case 4:
			lancarNotas(aluno, adicionarNota);
			break;
		case 5:
			verMedia(aluno, mostrarMedias);
			break;
		case 6:		
			gerarRelatorioDeDesempenho(aluno);
			break;
		case 7:
			ordenar_por_media(aluno);
			break;
		case 8:
			editar_dados_de_aluno(aluno);
			break;
		case 9:
			deletar_aluno(aluno);
			break;
		case 0:
			encerrarExecucao = true;
			break;
		default:
			std::cout<<"Escolha uma opção válida!"<<std::endl;
			break;
	}
}

int main() {
	int Qte = 1; //quantidade de alunos e usado para definir a matricula
	bool adicionarNota = false; //variavel para alterar o funcionamento das funções de busca para alterar nota
	bool encerrarExecucao = false; //encerrar o loop do while no main
	bool mostrarMedias = false; //ver as medias de todos os alunos em lista
	
	std::vector<Alunos> aluno;
	
	while(true){
		menuPrincipal(aluno, Qte, encerrarExecucao, adicionarNota, mostrarMedias);
		
		if(encerrarExecucao == true) {
			break;
		}
			else{
				continue;
			}
	}
	
	return 0;
}
