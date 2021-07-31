#define SWAP_W(_A_, _B_) {int tmpx = _A_.x; int tmpv = _A_.val; _A_.x = _B_.x; _A_.val = _B_.val; _B_.x = tmpx; _B_.val = tmpv;}
#define SWAP(_A_, _B_) {int tmp = _A_; _A_ = _B_; _B_ = tmp;}
#define MAXHEAPIFY_UP() \
                if (maxheap[cur] > maxheap[(cur - 1) / 2]) {\
                    int tmp = maxheap[cur];\
                    maxheap[cur] = maxheap[(cur - 1) / 2];\
                    maxheap[(cur - 1) / 2] = tmp;\
                }

struct wall {
    int x;
    int val;
};

void qsort_(struct wall *wall_list, int num) {
    int p = num - 1;
    int l = 0, r = 0;
    
    if (num <= 1) {
        return;
    }
    
    while(r < num) {
        if (wall_list[r].x < wall_list[p].x) {
            SWAP_W(wall_list[r], wall_list[l]);
            l++;
        } else if (wall_list[r].x == wall_list[p].x) {
            if (wall_list[r].val < wall_list[p].val) {
                SWAP_W(wall_list[r], wall_list[l]);
                l++;
            } 
        }
        r++;
    }
    
    SWAP_W(wall_list[l], wall_list[p]);
    
    qsort_(wall_list, l);
    qsort_(wall_list + l + 1, num - l - 1);
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    struct wall wall_list[20000] = {0, };
    int maxheap[20000] = {0, }, hi = 0;
    int i, preheight = 0;
    int **ret;
    
    ret = malloc(sizeof(int *) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    
    for (i = 0 ; i < buildingsSize ; i++) {
        wall_list[i * 2].x = buildings[i][0];
        wall_list[i * 2].val = buildings[i][2] * (-1);
        wall_list[i * 2 + 1].x = buildings[i][1];
        wall_list[i * 2 + 1].val = buildings[i][2];
    }
    
    qsort_(wall_list, buildingsSize * 2);
    
    for(i = 0 ; i < buildingsSize * 2 ; i++) {
        //printf("[%d,%d] ", wall_list[i].x, wall_list[i].val);
        if (wall_list[i].val < 0) {
            int cur = hi;
            
            maxheap[hi] = wall_list[i].val * (-1);
            
            while((cur - 1) / 2 > 0) {
                MAXHEAPIFY_UP();
                
                cur = (cur - 1) / 2;
            }
            
            if (cur > 0 && cur < 3) {
                MAXHEAPIFY_UP(); 
            }
 
            hi++;
        } else {///////////////////////////////////////////////////////////////////////
            int j, target = wall_list[i].val;
            
            for (j = 0 ; j < hi ; j++) {
                if (maxheap[j] == target) {
                    hi--;
                    maxheap[j] = maxheap[hi];
                    //printf("j:%d t:%d ", j, target);
                    
                    while(j * 2 + 2 < hi) {
                        //printf("j:%d ", j);
                        if (maxheap[j * 2 + 1] > maxheap[j * 2 + 2]) {
                            if (maxheap[j] <= maxheap[j * 2 + 1]) {
                                SWAP(maxheap[j], maxheap[j * 2 + 1]);
                                j = j * 2 + 1;                                
                            } else {
                                break;
                            }
                        } else {
                            if (maxheap[j] <= maxheap[j * 2 + 2]) {
                                SWAP(maxheap[j], maxheap[j * 2 + 2]);
                                j = j * 2 + 2;
                            } else {
                                break;
                            }
                        }
                    }
                    
                    if (j * 2 + 1 < hi && maxheap[j] < maxheap[j * 2 + 1]) {
                        SWAP(maxheap[j], maxheap[j * 2 + 1]);
                    }
                    break;
                }
            }
        }
        
        if (hi == 0) {
            maxheap[0] = 0;
        }
        
        if (maxheap[0] != preheight) {
            ret[*returnSize] = malloc(sizeof(int) * 2);
            ret[*returnSize][0] = wall_list[i].x;
            ret[*returnSize][1] = maxheap[0];
            preheight = maxheap[0];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize) += 1;
        }
/*
        {
            int j;
            
            printf("[");
            for (j = 0 ; j < hi ; j++) {
                printf("%d ", maxheap[j]);
            }
            printf("]\n");
        }
*/
    }
    
    return ret;
}