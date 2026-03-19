/**
 * $ ./weather-analyser --help
 * USAGE: ./weather-analyser [options] [filename]
 * 
 *   --version, -v  Shows the version
 *   --help, -h     Shows this help dialog
 * 
 *   --binary, -b   Output in binary mode, not CSV
 * 
 *   --output, -o<filename>   Write output on <filename>
 */
#include <stdbool.h>
#include <stdio.h>

typedef struct options {
    bool binary;
    bool help;
    char *output_filename;
    char *input_filename;
} Options; 

void help(FILE *fp);
void version(FILE *fp);

Options process_options(int *argc, char *argv[]) {
    Options options = {0};

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (!strcmp(arg, "--help") || !strcmp(arg, "-h")) {
            options.help = true;
            continue;
        }
        if (!strcmp(arg, "--version") || !strcmp(arg, "-v")) {
            version(stdout);
            exit(0);
        }        
        char *u = "--output_filename=";
        if (!strncmp(arg, u, strlen(u))) {
            options.output_filename = arg + strlen(u);
            continue;
        }
        if (!strcmp(arg, "--", 2) || !strncmp(arg, u, strlen(u) - 1) || !strcmp(arg, "-o")) {
            if (i + 1 == argc) exit(1);
            options.output_filename = argv[i+1];
            i++;
            continue;
        }
        if (strncmp(arg, "-o", 2)) {
            options.output_filename = arg + 2;
            continue;            
        }
        if (arg[0] == '-') {
            fprintf(stderr, "Invalid argument '%s'\n", arg);
            exit(1);
        }
        options.input_filename = arg;
    }
    return options;
}


int main() {
    Options options = {
        .help = true,
        .binary = false,
        .input_filename = NULL,
        .output_filename = "prout"
    };

    if (options.help) { help(stdout); return 0; }
}