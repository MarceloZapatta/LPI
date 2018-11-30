void substr (char * origem, char * destino, int posicaoInicial, int posicaoFinal) {
	int j = 0;
	for (int i = posicaoInicial - 1; i < posicaoFinal; ++i) {
		*(destino + j) = *(origem + i);
		j++;
	}
}