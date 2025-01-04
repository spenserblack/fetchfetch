#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

/**
 * Calls a shell command and returns the output as a string.
 */
char* app_version(const char *command) {
	FILE *fp;
	// NOTE 50 should be more than enough space for version info.
	char buffer[50];

	fp = popen(command, "r");
	if (fp == NULL) {
		return NULL;
	}

	fgets(buffer, sizeof(buffer), fp);
	pclose(fp);

	return strdup(buffer);
}

char* neofetch() {
	// NOTE Version in the format "Neofetch x.x.x"
	int start;
	int end;
	int len;
	char *out = app_version("neofetch --version");
	if (out == NULL) {
		return "Not installed";
	}
	len = strlen(out);

	// TODO Handle unexpected output (no space or newline).
	for (start = 0; out[start] != ' ' && start < len; start++);
	for (end = start; out[end] != '\n' && end < len; end++);
	out[end] = '\0';

	return out + start + 1;
}

FetchStat* get_stats() {
	FetchStat *stats = malloc(STATS_SIZE * sizeof(FetchStat));
	stats[0].label = "Neofetch";
	stats[0].version = neofetch();
	return stats;
}
