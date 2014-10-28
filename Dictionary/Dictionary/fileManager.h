#define CHUNK 1024 /* read 1024 bytes at a time */

#define read			"r"
#define write			"a"
#define fileLocation	"dictionary.txt"

void readFile();
char *readLine(int lineNumber);

void writeFile();

void readInput();