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

int scan_problems(Problem *probs) {
    const char *dirs[] = {"problems/001-050", NULL};

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
                    count++;
                }
            }
        }
        closedir(d);
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
        if (diff <= 10) d[0]++;
        else if (diff <= 20) d[1]++;
        else if (diff <= 30) d[2]++;
        else if (diff <= 40) d[3]++;
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

        if (strstr(line, "**Solved Problems :**")) {
            fprintf(out, "**Solved Problems :** %d/800+ (%.1f%%)\n", count, count * 100.0 / 800);

        }
        else if (strstr(line, "| 5-10%")) {
            fprintf(out, "| 5-10%% | %d |\n", d[0]);
        }
        else if (strstr(line, "| 15-20%")) {
            fprintf(out, "| 15-20%% | %d |\n", d[1]);
        }
        else if (strstr(line, "| 25-30%")) {
            fprintf(out, "| 25-30%% | %d |\n", d[2]);
        }
        else if (strstr(line, "| 35-40%")) {
            fprintf(out, "| 35-40%% | %d |\n", d[3]);
        }
        else if (strstr(line, "| 45%+")) {
            fprintf(out, "| 45%%+ | %d |\n", d[4]);
        }
        else if (strstr(line, "## Solved problems")) {
            fprintf(out, "%s\n\n", line);
            fprintf(out, "| # | Title | Difficulty | Time |\n");
            fprintf(out, "|---|-------|------------|------|\n");

            for (int i = 0; i < count; i++) {
                fprintf(out, "| %d | Problem %d | %d%% | - |\n",probs[i].number,probs[i].number,probs[i].difficulty);
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