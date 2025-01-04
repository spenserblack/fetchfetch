#include <stdio.h>
#include "art.h"
#include "stats.h"

int main(int argc, char *argv[]) {
	FetchStat *stats = get_stats();
	for (int line_index = 0; line_index < ART_HEIGHT || line_index < STATS_SIZE; line_index++) {
		if (line_index < ART_HEIGHT) {
			for (int col_index = 0; col_index < ART_WIDTH; col_index++) {
				putchar(art[line_index][col_index]);
			}
		} else {
			printf(ART_FILLER);
		}

		// NOTE We skip a line because it looks a little better.
		if (line_index != 0 && line_index <= STATS_SIZE) {
			printf(" %s: %s", stats[line_index - 1].label, stats[line_index - 1].version);
		}
		printf("\n");
	}
	return 0;
}
