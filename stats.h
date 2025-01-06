#ifndef FETCH_FETCH_STATS_H
#define FETCH_FETCH_STATS_H

typedef struct {
	char *label;
	char *version;
} FetchStat;

/**
 * Gets Fastfetch version information.
 */
char* fastfetch();

/**
 * Gets Neofetch version information.
 */
char* neofetch();

/**
 * Gets onefetch version information.
 */
char* onefetch();

#define STATS_SIZE 3
/**
 * Gets all stats.
 */
FetchStat* get_stats();

#endif
