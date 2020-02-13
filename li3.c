fopen
fgets
strtok
strsep
strcpy
strdup -> new = strdup(str)

void read_with_fgets(FILE * f){
	int len = 8;
	char cli_code[len];
	while( fgets(cli_code, len, f)){
		printf("%s",cli_code);
	}
}

