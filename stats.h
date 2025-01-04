#ifndef FETCH_FETCH_STATS_H
#define FETCH_FETCH_STATS_H

typedef struct {
	char *label;
	char *version;
} FetchStat;

/**
 * Gets Neofetch version information.
 */
char* neofetch();

#define STATS_SIZE 1
/**
 * Gets all stats.
 */
FetchStat* get_stats();

#endif
