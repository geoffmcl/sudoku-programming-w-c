/* display_strats_in_clear.c
 *
 * Copyright (C) 2015  Giulio Zambon  - http://zambon.com.au/
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "display_strats_in_clear.h"

void display_strats_in_clear() {
#ifdef LOG_IN_OUT
    printf("--- display_strats_in_clear >>>\n");
#endif

  for (int k = 0; k < n_strats_used; k++) {
      int used = strats_used[k];
    int level = used / 10;
    int k_strat = used - level * 10;
    if (level < n_levels) {
        if (k_strat < n_strat_all[level]) {
            printf(" '%s'", strat_all_names[level][k_strat]);
        }
        else {
            printf("\nError: used %d: k_strat %d not less that %d", used, k_strat, n_strat_all[level]);
            break;
        }
    }
    else {
        printf("\nError: used %d: level %d not less that %d", used, level, n_levels);
        break;
    }
    }
  printf("\n");
#ifdef LOG_IN_OUT
  printf("<<< display_strats_in_clear ---\n");
#endif

  }
