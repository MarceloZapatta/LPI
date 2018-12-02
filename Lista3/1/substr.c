char * substr (char * origem, int posicaoInicial, int posicaoFinal) {
	int j = 0;
	char * destino = (char *) malloc(sizeof(char *) *  (posicaoFinal - posicaoInicial + 1));

	for (int i = posicaoInicial - 1; i < posicaoFinal; ++i) {
		*(destino + j) = *(origem + i);
		j++;
	}

	*(destino + j) = '\0';
	return destino;
}