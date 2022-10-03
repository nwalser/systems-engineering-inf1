#include <stdio.h>

#define BUFSIZE 128 * 32

int main(void) {
    char *cmd = "echo 'Hi, your webserver has a few holes in it. So I was able to get until this point. Hope you can fix them, that no one gets harmed. Regards... :)' >> ../you-have-been-hacked-README.txt";
    
    char buf[BUFSIZE];
    FILE *fp;

    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        // Do whatever you want here...
        printf("OUTPUT: %s", buf);
    }

    if (pclose(fp)) {
        printf("Command not found or exited with error status\n");
        return -1;
    }

    return 0;
}