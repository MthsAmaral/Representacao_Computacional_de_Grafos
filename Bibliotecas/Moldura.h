void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF) {
	int i;

	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI, LI);
	printf("%c", 201);
	gotoxy(CF, LI);
	printf("%c", 187);
	gotoxy(CI, LF);
	printf("%c", 200);
	gotoxy(CF, LF);
	printf("%c", 188);
	for (i = CI + 1; i < CF; i++) {
		gotoxy(i, LI);
		printf("%c", 205);
		gotoxy(i, LF);
		printf("%c", 205);
	}
	for (i = LI + 1; i < LF; i++) {
		gotoxy(CI, i);
		printf("%c", 186);
		gotoxy(CF, i);
		printf("%c", 186);
	}
	textbackground(7);
	textcolor(0);
}

void FundoQuadro(int CI, int LI, int CF, int LF, int Cor) {
	int L = LI + 1, C = CI + 1;
	char linha[150] = "";

	while (CI < CF - 1) {
		strcat(linha, " ");
		CI++;
	}
	textbackground(Cor);
	while (L < LF) {
		gotoxy(C, L);
		printf("%s", linha);
		L++;
	}
}

void Sombra(int CI, int LI, int CF, int LF, int CorF) {
	int i;
	textbackground(CorF);
	for (i = LI; i < LF; i++) {
		gotoxy(CF + 1, i + 1);
		printf("  ");
	}
	for (i = CI; i < CF + 2; i++) {
		gotoxy(i + 1, LF + 1);
		printf(" ");
	}
	textbackground(7);
}

void Titulo(int CI, int CF, char *Titulo, int Linha) {
	int pos = (CF + CI) / 2 - (strlen(Titulo) + 2) / 2;

	if (strlen(Titulo)) {
		textbackground(0);
		textcolor(14);
		gotoxy(pos, Linha);
		printf(" %s ", Titulo);
		textcolor(0);
		textbackground(7);
	}
}

void RetiraCursor(void) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void LigaCursor(void) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Dimensao(char *C, char *L) {
	char linha[30];

	strcpy(linha, "mode con cols=");
	strcat(linha, C);
	strcat(linha, " lines=");
	strcat(linha, L);
	system(linha);
}

void LimpaLinha(int Num) {
	gotoxy(2, Num);
	printf("                                                                                                  ");
}

void LimpaTela(void) {
	int i;

	for (i = 2; i < 48; i++)
		LimpaLinha(i);
}

void LinhaMoldura(int Linha, int CorF, int CorT) {
	int i;
	textbackground(CorF);
	textbackground(CorT);
	gotoxy(1, Linha);
	printf("%c", 204);
	gotoxy(100, Linha);
	printf("%c", 185);
	for (i = 2; i < 100; i++) {
		gotoxy(i, Linha);
		printf("%c", 205);
	}
}

void ColunaMoldura(int LI, int LF, int Coluna, int CorF, int CorT) {
	int i;

	textbackground(CorF);
	textbackground(CorT);
	gotoxy(Coluna, LI);
	printf("%c", 203);
	gotoxy(Coluna, LF);
	printf("%c", 202);
	for (i = LI + 1; i < LF; i++) {
		gotoxy(Coluna, i);
		printf("%c", 186);
	}
}

void CaixaTexto(int CI, int LI, int CF, int LF, int CorT, int CorF, char* titulo) {
	Moldura(CI, LI, CF, LF, CorT, CorF);
	FundoQuadro(CI, LI, CF, LF, CorF);
	Sombra(CI, LI, CF, LF, 0);
	Titulo(CI, CF, titulo, LI);
}

void ExibeTexto(int TamC, int Linha, int CorT, int CorF, char *texto, char *titulo) {
	int CI = TamC / 2 - (strlen(texto) / 2 + 2), CF = TamC / 2 + (strlen(texto) / 2 + 2), LI = Linha - 1, LF = Linha + 1;

	CaixaTexto(CI,LI,CF,LF,CorT,CorF,titulo);
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(TamC / 2 - strlen(texto) / 2, LI + 1);
	printf("%s", texto);
}

void MolduraCompleta(int CI, int LI, int CF, int LF, int CorT, int CorF) {
	FundoQuadro(CI,LI,CF,LF,CorF);
	Moldura(CI,LI,CF,LF,CorT,CorF);
}

void MsgFim(void) {
	Dimensao("100", "30");
	Moldura(1, 1, 100, 30, 0, 3);
	FundoQuadro(1, 1, 100, 30, 3);

	ExibeTexto(100, 4, 0, 7, "TRABALHO BIMESTRAL - TEORIA DOS GRAFOS", "");
	ExibeTexto(100, 9, 0, 14, "REPRESENTACAO GRAFICA", "");
	ExibeTexto(100, 14, 0, 7, "102421080 - MATHEUS AMARAL MATOS", "");
	ExibeTexto(100, 19, 0, 7, "102421080 - MATHEUS OLIVEIRA DA SILVA", "");
	ExibeTexto(100, 26, 0, 7, "PROF. daniela ", "");
}
