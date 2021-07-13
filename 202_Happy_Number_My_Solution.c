char ** findRepeatedDnaSequences(char * s, int* returnSize){
    int hash[1050000] = {0, };
    int trans[256] = {0, };
    int value = 0, cnt = 0;
    char ** ret = malloc(sizeof(char*) * 0);
    
    *returnSize = 0;
    trans[0] = 'A';
    trans[1] = 'C';
    trans[2] = 'G';
    trans[3] = 'T';
    trans['A'] = 0;
    trans['C'] = 1;
    trans['G'] = 2;
    trans['T'] = 3;
    while (*s != 0) {
        value <<= 2;
        value &= 0xFFFFF;
        value |= trans[*s];
        cnt++;

        if (cnt >= 10) {
            hash[value]++;
            //printf("[%d,%d]", value, hash[value]);
            if (hash[value] == 2) {
                int i, val = value;

                (*returnSize)++;
                ret = realloc(ret, sizeof(char*) * (*returnSize));
                ret[(*returnSize) - 1] = malloc(sizeof(char) * 11);
                for (i = 9 ; i >= 0 ; i--) {
                    ret[(*returnSize) - 1][i] = trans[val % 4];
                    val /= 4;
                }
                ret[(*returnSize) - 1][10] = 0;
            } 
        }

        s++;
    }
    

    return ret;
}