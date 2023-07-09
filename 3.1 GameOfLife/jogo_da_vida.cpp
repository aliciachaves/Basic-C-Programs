#include "jogo_da_vida.h"

// Cria um jogo cujo torus tem l linhas e c colunas.
// Todas as células são inicializadas como mortas.
JogoDaVida::JogoDaVida(int l, int c) {
	vivas_.resize(l, std::vector<bool>(c, false));
}

// Retorna o estado da célula [i, j].
// Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
bool JogoDaVida::viva(int i, int j) {
	if (i >= 0 && i < linhas() && j >= 0 && j < colunas()) {
		return vivas_[i][j];
	}
	else {
		throw ExcecaoCelulaInvalida{ i, j };
	}
}

// Altera o estado da célula [i, j] para morta.
// Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
void JogoDaVida::Matar(int i, int j) {
	if (i >= 0 && i < linhas() && j >= 0 && j < colunas()) {
		vivas_[i][j] = false;
	}
	else {
		throw ExcecaoCelulaInvalida{ i, j };
	}
}

// Altera o estado da célula [i, j] para viva.
// Pré-condição: 0 <= i < #linhas e 0 <= j < #colunas
void JogoDaVida::Reviver(int i, int j) {
	if (i >= 0 && i < linhas() && j >= 0 && j < colunas()) {
		vivas_[i][j] = true;
	}
	else {
		throw ExcecaoCelulaInvalida{ i, j };
	}
}

// Executa a próxima iteração do jogo da vida.
// Ou seja, altera os estado da matriz,
// de forma que ela fique igual ao da próxima iteração.
void JogoDaVida::ExecutarProximaIteracao() {
	std::vector<std::vector<bool>> proximas_vivas(linhas(), std::vector<bool>(colunas(), false));

	for (int i = 0; i < linhas(); i++) {
		for (int j = 0; j < colunas(); j++) {
			int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);

			if (vivas_[i][j] && (vizinhas_vivas == 2 || vizinhas_vivas == 3)) {
				proximas_vivas[i][j] = true;
			}
			else if (!vivas_[i][j] && vizinhas_vivas == 3) {
				proximas_vivas[i][j] = true;
			}
		}
	}

	vivas_ = proximas_vivas;
}


int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
	static const std::vector<std::pair<int, int>> vizinhos = {
	  {-1, -1}, {-1, 0}, {-1, 1},
	  {0, -1},           {0, 1},
	  {1, -1},  {1, 0},  {1, 1}
	};

	int n = 0;
	for (const auto& vizinho : vizinhos) {
		int vizinhoX = (x + vizinho.first + linhas()) % linhas();
		int vizinhoY = (y + vizinho.second + colunas()) % colunas();
		if (viva(vizinhoX, vizinhoY)) {
			n++;
		}
	}
	return n;
}
