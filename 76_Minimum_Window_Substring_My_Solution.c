char * minWindow(char * s, char * t){
    char *ps, *pt;
    int pos[100000] = {0, };
    int t_map[256] = {0, };
    int s_map[256] = {0, };
    int t_list[55] = {0, };
    int pos_e = 0, pos_s = 0, list_idx = 0;
    int length = 0, min_length = 100001, start = 0, end = 0;
    int i;
    
    pt = t;
    while(*pt != 0) {
        if (t_map[*pt] == 0) {
            t_list[list_idx] = *pt;
            list_idx++;
        }
        t_map[*pt]++;
        pt++;
    }
    
    ps = s;
    while(*ps != 0) {
        if (t_map[*ps] > 0) {
            pos[pos_e] = length;
            //printf("\npos[%d]:%d ", pos_e, length);
            pos_e++;
            s_map[*ps]++;

            while(true) {
                for (i = 0 ; i < list_idx ; i++) {
                    if (s_map[t_list[i]] < t_map[t_list[i]]) {
                        break;
                    }
                }

                if (i == list_idx) {
                    int cur_length = pos[pos_e - 1] - pos[pos_s];
                    //printf("[%d, %d] ", pos[pos_s], pos[pos_e - 1]);
                    if (cur_length < min_length) {
                        min_length = cur_length;
                        start = pos[pos_s];
                        end = pos[pos_e - 1];
                    }
                    s_map[s[pos[pos_s]]]--;
                    pos_s++;
                } else {
                    break;
                }
            }

        }
        
        length++;
        ps++;
    }

    //printf("\n[%d, %d, %d] ", min_length, start, end);
    if (min_length >= 100001) {
        return "";
    }

    s[end + 1] = 0;
    return (s + start);
}