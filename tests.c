/* Author:
 * Date:
 * File:
 * Description:
 */

/* stardard library includes*/
#include <stdio.h>

/* project includes */
#include "file_info.h"

int test_file_info() {
    int fails = 0;

    //test single file
    file_s *file = get_info(".");
    if (file == NULL) {
        fprintf(stderr, "failed to open file\n");
        fails++;
    }

    //test adding a file
    if (add_file(file, ".") == 0) {
        fprintf(stderr, "failed to add file\n");
        fails++;
    }

    free_file_s(file);

    return fails;
}

int main(int argc, char const *argv[]) {
    int t_fails = 0;
    t_fails += test_file_info();

    if (t_fails > 0) {
        printf("Total test fails: %d\n", t_fails);
    } else {
        printf("All tests PASSED!\n");
    }
    return 0;
}