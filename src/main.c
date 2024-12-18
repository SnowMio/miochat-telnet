#include <stdio.h>

#include "message.h"

int port;

void display_banner() {
  printf("%s\n", " _____ ______   ___  ________  ________  ___  ___  ________  "
                 "_________   ");
  printf("%s\n", "|\\   _ \\  _   \\|\\  \\|\\   __  \\|\\   ____\\|\\  \\|\\  "
                 "\\|\\   __  \\|\\___   ___\\ ");
  printf("%s\n", "\\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\|\\  \\ \\  \\___|\\ "
                 "\\  \\\\\\  \\ \\  \\|\\  \\|___ \\  \\_| ");
  printf("%s\n", " \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\    \\ "
                 "\\   __  \\ \\   __  \\   \\ \\  \\  ");
  printf("%s\n", "  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\____\\ "
                 "\\  \\ \\  \\ \\  \\ \\  \\   \\ \\  \\ ");
  printf("%s\n", "   \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\ \\_______\\ "
                 "\\__\\ \\__\\ \\__\\ \\__\\   \\ \\__\\");
  printf(
      "%s\n",
      "    \\|__|     "
      "\\|__|\\|__|\\|_______|\\|_______|\\|__|\\|__|\\|__|\\|__|    \\|__|");
  printf("%s\n", "                                                             "
                 "            ");
  printf("%s\n", "                                                             "
                 "            ");
  printf("%s\n", "                                                             "
                 "            ");
}

int main(int argc, char *argv[]) {
  display_banner();
  printf("MioChat Telnet\n");

  if (argc != 2) {
    /* error_message("Hello!"); */
    printf("Server is running on port %d", port);
  }
  return 0;
}
