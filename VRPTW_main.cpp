#include "VRPTW_map.h"
int main(){
    const char* filename = "solomon-1987-c1/C101_025.xml";
    Map test(filename);
    std::cout<<test.get_distance(1,2)<<std::endl;
    return 0;
}