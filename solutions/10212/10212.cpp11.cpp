#include <iostream> 
int main () { char tmp[255]; sprintf(tmp, "%d", &tmp); if( tmp[6] <= '4' && tmp[6] >= '0') printf("%s", "Korea"); else printf("%s", "Yonsei"); return 0; }