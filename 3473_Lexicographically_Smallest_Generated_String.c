#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generateString(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int L = n + m - 1;

    char* ans = malloc(L + 1);
    for(int i = 0; i < L; i++) ans[i] = '?';
    ans[L] = '\0';

    for(int i = 0; i < n; i++) {
        if(str1[i] == 'T') {
            for(int j = 0; j < m; j++) {
                if(ans[i + j] == '?' || ans[i + j] == str2[j]) {
                    ans[i + j] = str2[j];
                } else {
                    free(ans);
                    return strdup("");
                }
            }
        }
    }

    for(int i = 0; i < L; i++) {
        if(ans[i] == '?')
            ans[i] = 'a';
    }

    for(int i = 0; i < n; i++) {
        if(str1[i] == 'F') {
            int match = 1;
            for(int j = 0; j < m; j++) {
                if(ans[i + j] != str2[j]) {
                    match = 0;
                    break;
                }
            }

            if(match) {
                int fixed = 0;
                for(int j = m - 1; j >= 0; j--) {
                    int pos = i + j;
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c != str2[j]) {
                            char old = ans[pos];
                            ans[pos] = c;

                            int ok = 1;
                            for(int k = 0; k < n; k++) {
                                if(str1[k] == 'T') {
                                    for(int t = 0; t < m; t++) {
                                        if(ans[k + t] != str2[t]) {
                                            ok = 0;
                                            break;
                                        }
                                    }
                                }
                                if(!ok) break;
                            }

                            if(ok) {
                                fixed = 1;
                                break;
                
                            }
                            ans[pos] = old;
                        }


                    }
                    if(fixed) break;
                }
                if(!fixed) {
                    free(ans);
                    return strdup("");
                }
            }
        }
    }
    return ans;
}
