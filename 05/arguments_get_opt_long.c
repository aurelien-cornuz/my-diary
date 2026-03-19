/**
 * $ ./weather-analyser --help
 * USAGE: ./weather-analyser [options] [filename]
 *
 *   --version, -v         Shows the version
 *   --help, -h            Shows this help dialog
 *
 *   --binary, -b          Output in binary mode, not CSV
 *
 *   --output, -o <file>   Write output to <file>
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct options {
    bool   binary;
    char  *output_filename;
    char  *input_filename;
} Options;

void help(FILE *fp);
void version(FILE *fp);

Options process_options(int argc, char *argv[])
{
    Options options = {
        .binary          = false,
        .output_filename = NULL,
        .input_filename  = NULL,
    };

    static const struct option long_opts[] = {
        { "help",    no_argument,       NULL, 'h' },
        { "version", no_argument,       NULL, 'v' },
        { "binary",  no_argument,       NULL, 'b' },
        { "output",  required_argument, NULL, 'o' },
        { NULL,      0,                 NULL,  0  },
    };

    int c;
    while ((c = getopt_long(argc, argv, "hvbo:", long_opts, NULL)) != -1) {
        switch (c) {
        case 'h':
            help(stdout);
            exit(0);

        case 'v':
            version(stdout);
            exit(0);

        case 'b':
            options.binary = true;
            break;

        case 'o':
            options.output_filename = optarg;
            break;

        case '?':   /* getopt already printed an error message */
        default:
            exit(1);
        }
    }

    /* Remaining non-option argument: input filename */
    if (optind < argc) {
        if (optind + 1 < argc) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        options.input_filename = argv[optind];
    }

    return options;
}