#include "simplificar.h"
#include "evaluar.h"
#include "logica.h"

int main(int argc, char **argv) {
	/*
	 * "\\((.+) OR (.+)\\) AND (\\1|\\2)"
	 * "(.+) (AND|OR) \\1"
	 */


	//printf(">> %s\n", "((((b OR b) AND b) OR (b AND b)) AND q) OR b");
	//printf(">> %s\n", parse("((b OR b) AND q) AND b", ejecutarRegex));

	//"v y ((f y (f y v)) o v)"

	printf(">> %s\n", parse("v y ((f y (f y v)) o v)", simplificar));


	//evaluar || simplificar

	return EXIT_SUCCESS;
}
