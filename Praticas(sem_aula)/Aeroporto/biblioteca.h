
void Pilotos();
void gerenciarPilotos();
void consultarPiloto();
char *gerarID(const char *tipo_voo);
int idExiste(const char *id);

/*
Uteis
*/
void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes);
void limparBuffer();
void letrasMinusculas(char *str);
