#include <stdio.h>
#include<string.h>
#define MAXLINE 100
void copy(char from[], char to[]);
char *mygets(char *buf, size_t size);
char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄
/*입력 줄 가운데 가장 긴 줄 프린트 */
int main()
{
    int len;
    int max;
    max = 0;
    while (mygets(line, sizeof(line)) != NULL) {
        len = strlen(line);
        if (len > max) {
               max = len;
               copy(line, longest);
        }
    }
    if (max > 0) // 입력 줄이 있었다면
        printf("%s", longest);
        return 0;
}
/* copy: from을 to에 복사; to가 충분히 크다고 가정*/
void copy(char from[], char to[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
          ++i;
}

char *mygets(char *buf, size_t size) {
        if (buf != NULL && size > 0) {
            if (fgets(buf, size, stdin)) {
                buf[strcspn(buf, "\n")] = '\0';
                return buf;
            }
           *buf = '\0';  /* clear buffer at end of file */
        }
        return NULL;
}
