
struct event {
    char ch;
    struct state *next;
};

struct state {
    char *name;
    struct event events[10];
};

struct state Final = {
    "Final",
    {
        {0, 0},
        {'\0', 0},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', 0},
        {'e', 0},
        {'E', 0},  
    }
};

struct state NumsAfterE = {
    "NumsAfterE",
    {
        {0, 0},
        {'\0', &Final},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', &NumsAfterE},
        {'e', 0},
        {'E', 0},  
    }
};

struct state APlusMinusAfterE = {
    "APlusMinusAfterE",
    {
        {0, 0},
        {'\0', 0},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', &NumsAfterE},
        {'e', 0},
        {'E', 0},  
    }
};

struct state eE = {
    "eE",
    {
        {0, 0},
        {'\0', 0},
        {'-', &APlusMinusAfterE},
        {'+', &APlusMinusAfterE},
        {'.', 0},
        {'0', &NumsAfterE},
        {'e', 0},
        {'E', 0},  
    }
};

struct state NumsAfterDot = {
    "NumsAfterDot",
    {
        {0, 0},
        {'\0', &Final},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', &NumsAfterDot},
        {'e', &eE},
        {'E', &eE},  
    }
};

struct state ADotAfterNum = {
    "ADotAfterNum",
    {
        {0, 0},
        {'\0', &Final},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', &NumsAfterDot},
        {'e', &eE},
        {'E', &eE},  
    }
};

struct state ADotBeforeNum = {
    "ADotBeforeNum",
    {
        {0, 0},
        {'\0', 0},
        {'-', 0},
        {'+', 0},
        {'.', 0},
        {'0', &NumsAfterDot},
        {'e', 0},
        {'E', 0},  
    }
};

struct state NumsBeforeDot = {
    "NumsBeforeDot",
    {
        {0, 0},
        {'\0', &Final},
        {'-', 0},
        {'+', 0},
        {'.', &ADotAfterNum},
        {'0', &NumsBeforeDot},
        {'e', &eE},
        {'E', &eE},  
    }
};

struct state FirstPlusMinus = {
    "FirstPlusMinus",
    {
        {0, 0},
        {'\0', 0},
        {'-', 0},
        {'+', 0},
        {'.', &ADotBeforeNum},
        {'0', &NumsBeforeDot},
        {'e', 0},
        {'E', 0},  
    }
};

struct state root = {
    "root",
    {
        {0, 0},
        {'\0', 0},
        {'-', &FirstPlusMinus},
        {'+', &FirstPlusMinus},
        {'.', &ADotBeforeNum},
        {'0', &NumsBeforeDot},
        {'e', 0},
        {'E', 0},  
    }
};

bool isNumber(char * s){
    struct state *cur = &root;
    char hashmap[256] = {0, };
    char *pre = s;
    int i;
    
    hashmap[(int)'\0'] = 1;
    hashmap[(int)'-'] = 2;
    hashmap[(int)'+'] = 3;
    hashmap[(int)'.'] = 4;
    
    for (i = 48 ; i <= 57 ; i++) {
        hashmap[i] = 5;
    }
    
    hashmap[(int)'e'] = 6;
    hashmap[(int)'E'] = 7;
    
    while(*pre) {
        int val = hashmap[*s];
        struct state *origin = cur;
        
        //printf("%c, %d  ", *s, *s);
        if (val > 0 && cur->events[val].next != 0) {
            //printf(" : %s[%d] -> %s\n", cur->name, i
            //       , (cur->events[val].next == 0) ? "NULL" : cur->events[val].next->name);
            cur = cur->events[val].next;
        } else {
            return false;
        }
        
        pre = s;
        s++;
    }
    
    return true;
}