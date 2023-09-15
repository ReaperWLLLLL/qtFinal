//
// Created by Reaper on 2023/9/8.
//

#ifndef FINALHW_MESH_H
#define FINALHW_MESH_H
#define VACUUM_PERMITTIVITY 8.854187817e-12

#include "El2no.h"
#include "No2xy.h"
#include "Bd2no.h"
#include <vector>
#include <algorithm>
#include "lapacke.h"
#include "sqlite3.h"
#include "string"

class Mesh {
private:

    //数据库
    sqlite3 *db;
    void db_init();
public:
    explicit Mesh(const string& filename);
    Mesh();
    ~Mesh();

    string display_sorted(int type, string attr, bool is_ascending);

    string display_mid(int type, string attr, double upperbound, double lowerbound);

    bool add(El2no el2no);

    bool add(Bd2no bd2no);

    bool add(No2xy no2xy);

    bool del(int no1, int no2, int no3);

    bool del(int no1, int no2);

    bool del(double no1);

    void solve();

    bool add_record();

    string qurry_record();

    vector<Bd2no> bd2noVec;
    vector<El2no> el2noVec;
    vector<No2xy> no2xyVec;
    vector<double> record;


};


#endif //FINALHW_MESH_H
