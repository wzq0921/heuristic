#pragma once
#include <iostream>
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"
#include <string>


typedef struct customer
{
    int pos_x;
    int pos_y;
    double serve_time;
    double need;
    int begin_window;
    int end_window;
} customer;

typedef struct truck{
    int capacity;
    int max_travel_time;
}truck;

class Map
{
    std::vector<customer> customer_list;
    std::string Map_name;
    int truck_num;
    truck t;
    
public:
    Map(std::string file_name);
    int get_distance(int p1, int p2);
    customer get_customer(int index);
};