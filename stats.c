#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

/**
 * Calls a shell command and returns the output as a string.
 *
 * Falls back to "Not installed" if the command fails.
 */
char* app_version(const char *command) {
	FILE *fp;
	// NOTE 50 should be more than enough space for version info.
	char buffer[50];

	fp = popen(command, "r");
	if (fp == NULL) {
		return "Not installed";
	}

	fgets(buffer, sizeof(buffer), fp);
	pclose(fp);

	return strdup(buffer);
}

/**
 * Splits outputs in the format `"Appname x.y.z\n"` into `"x.y.z"`.
 */
char* extract_named_version(const char *version_info) {
	int start;
	int end;
	int len;

	len = strlen(version_info);
	for (start = 0; version_info[start] != ' ' && start < len; start++);
	for (end = start; version_info[end] != '\n' && end < len; end++);
	return strndup(version_info + start + 1, end - start - 1);
}

char* neofetch() {
	// NOTE Version in the format "Neofetch x.x.x"
	char *out = app_version("neofetch --version");
	return extract_named_version(out);
}

char* onefetch() {
	// NOTE Version in the format "onefetch x.x.x"
	char *out = app_version("onefetch --version");
	return extract_named_version(out);
}

FetchStat* get_stats() {
	FetchStat *stats = malloc(STATS_SIZE * sizeof(FetchStat));
	stats[0].label = "Neofetch";
	stats[0].version = neofetch();
	stats[1].label = "onefetch";
	stats[1].version = onefetch();
	return stats;
}
