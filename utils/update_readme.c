/**
* README updater
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct {
    int number;
    int difficulty;
    char title[100];
}Problem;



int get_number(const char *name) {
    int num;

    if (sscanf(name,"problem_%d", &num) == 1){
        return num;
    }
    return -1;
}

int get_difficulty(const char *path) {
    FILE *f = fopen(path, "r");
    
    if (!f){
        return -1;
    }

    char line[256];
    int diff = -1;

    for (int i = 0; i < 30 && fgets(line,256,f); i++) {
        if (strstr(line, "Difficulty:")) {
            sscanf(line, "%*[^0-9]%d", &diff);
            break;
        }
    }

    fclose(f);
    return diff;
}

void get_title(const char *path, char *title) {
    FILE *f = fopen(path, "r");

    if (!f) {
        strcpy(title, "Unknown");
        return;
    }

    char line[256];
    int found = 0;

    for (int i = 0; i < 10 && fgets(line, 256, f); i++) {
        if (strstr(line, "Problem") && strstr(line, ":")) {

            char *colon = strchr(line, ':');
            if (colon && *(colon + 1)) {
                colon++;
                while (*colon == ' ') colon++;

                int j = 0;
                while (*colon && *colon != '\n' && *colon != '\r' && j < 99) {
                    title[j++] = *colon++;
                }
                title[j] = '\0';
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        sprintf(title, "Problem %d", -1);
    }

    fclose(f);
}

int compare_problems(const void *a, const void *b) {
    Problem *p1 = (Problem *)a;
    Problem *p2 = (Problem *)b;
    return p1->number - p2->number;
}

int scan_problems(Problem *probs) {
    const char *dirs[] = {"problems", NULL};

    int count = 0;

    for (int i = 0; dirs[i]; i++) {
        DIR *d = opendir(dirs[i]);
        if (!d) continue;

        struct dirent *entry;
        while ((entry = readdir(d))) {
            if (strncmp(entry->d_name, "problem_", 8) == 0) {
                int num = get_number(entry->d_name);
                if (num > 0) {
                    char path[300];
                    sprintf(path,"%s/%s",dirs[i],entry->d_name);

                    probs[count].number = num;
                    probs[count].difficulty = get_difficulty(path);
                    get_title(path,probs[count].title);
                    count++;
                }
            }
        }
        closedir(d);
    }

    if (count > 0) {
        qsort(probs, count, sizeof(Problem), compare_problems);
    }

    return count;
}


void update_readme(Problem *probs, int count) {
    FILE *f = fopen("README.md", "r");

    char content[50000];
    size_t len = fread(content,1,50000,f);
    content[len] = '\0';
    fclose(f);

    int d[5] = {0,0,0,0,0};

    for (int i = 0; i < count; i++){
        int diff = probs[i].difficulty;
        if (diff <= 0) d[0]++;
        else if (diff <= 1) d[1]++;
        else if (diff <= 2) d[2]++;
        else if (diff <= 3) d[3]++;
        else d[4]++;
    }

    char *p = content;
    FILE *out = fopen("README.md","w");
    char line[1024];

    while (*p) {
        int i = 0;
        while (*p && *p != '\n' && i < 1023) line[i++] = *p++;
        line[i] = '\0';
        if (*p == '\n') p++;

        if (strstr(line, "![Problems Solved]") || strstr(line, "[![Problems Solved]")) {
            fprintf(out, "[![Problems Solved](https://img.shields.io/badge/Problems-%d%%2F100-blue)](https://projecteuler.net)\n", count);
        }
        else if (strstr(line, "![Progress]") || strstr(line, "[![Progress]")) {
            fprintf(out, "[![Progress](https://img.shields.io/badge/Progress-%d%%25-yellow)](https://github.com/jeanbapd/Project-Euler-solutions/milestones)\n", count);
        }
       else if (strstr(line, "**Solved Problems :**")) {
            fprintf(out, "**Solved Problems :** %d/100 (%d%%)\n", count, count);
        }
       else if (strstr(line, "| Level 0 (Very Easy)")) {
           fprintf(out, "| Level 0 (Very Easy)  | %-15d |\n", d[0]);
       }
       else if (strstr(line, "| Level 1 (Easy)")) {
           fprintf(out, "| Level 1 (Easy)       | %-15d |\n", d[1]);
       }
       else if (strstr(line, "| Level 2 (Medium)")) {
           fprintf(out, "| Level 2 (Medium)     | %-15d |\n", d[2]);
       }
       else if (strstr(line, "| Level 3 (Hard)")) {
           fprintf(out, "| Level 3 (Hard)       | %-15d |\n", d[3]);
       }
       else if (strstr(line, "| Level 4+ (Very Hard)")) {
           fprintf(out, "| Level 4+ (Very Hard) | %-15d |\n", d[4]);
       }
        else if (strstr(line, "## Solved problems")) {
            fprintf(out, "%s\n\n", line);
            fprintf(out, "| # | Title               | Difficulty | Time (ms) |\n");
            fprintf(out, "|---|---------------------|------------|-----------|\n");

            for (int i = 0; i < count; i++) {
                fprintf(out, "| %d | %-19s | %d | - |\n",probs[i].number,probs[i].title,probs[i].difficulty);
            }

            while (*p && strncmp(p, "## ", 3) != 0) {
                while (*p && *p != '\n') p++;
                if (*p == '\n') p++;

            }
        }
        else {
            fprintf(out, "%s\n", line);
        }
    }
    fclose(out);
}


int main(void) {
    Problem probs[500];

    int count = scan_problems(probs);

    printf("Found %d problems\n", count);

    if (count > 0) {
        printf("Problems: ");
        for (int i = 0; i < count && i < 10; i++) {
            printf("%d", probs[i].number);
            if (i < count - 1 && i < 9) printf(", ");
        }
        if (count > 10) printf(", ...");
        printf("\n");
    }

    update_readme(probs,count);
    printf("README updated!\n");

    return EXIT_SUCCESS;
}
