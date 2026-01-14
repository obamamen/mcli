#include "mcli.h"
#include <stdio.h>
#include <string.h>

#define LINE_CAP 32

int main(void)
{
    if (mcli_initialize() != mcli_ok) return 1;
    if (mcli_raw_mode(true) != mcli_ok) return 1;

    char line[LINE_CAP];
    size_t len = 0;

    printf("> ");
    fflush(stdout);

    while (true)
    {
        int key = mcli_getkey_nb();
        if (key == MCLI_KEY_NONE) continue;

        if (mcli_is_enter(key))
        {
            if (len > 0)
            {
                line[len] = '\0';

                if (strcmp(line, "/hello") == 0)
                {
                    printf(
                        "\n" MCLI_FG_CYAN "Hello World!" MCLI_RESET "\n");
                }
                else if (strcmp(line, "/exit") == 0)
                {
                    break;
                }
                else
                {
                    printf("\n"
                        MCLI_FG_RED
                        "ECHO: <"MCLI_RESET"%s"MCLI_FG_RED">"
                        MCLI_RESET
                        "\n", line);
                }
            }

            len = 0;
            printf("> ");
            fflush(stdout);
        }

        else if (mcli_is_backspace(key))
        {
            if (len > 0)
            {
                len--;
                mcli_cursor_back(1);
                mcli_clear_to_end();
                fflush(stdout);
            }
        }

        else if (mcli_is_printable(key))
        {
            if (len < LINE_CAP - 1)
            {
                line[len++] = (char)key;
                putchar(key);
                fflush(stdout);
            } else
            {
                putchar(MCLI_CHAR_BEL);
            }
        }
    }

    mcli_raw_mode(false);
    mcli_cleanup();
    return 0;
}
