//
// Created by Reaper on 2023/9/8.
//

#include "Mesh.h"
#include <fstream>

Mesh::Mesh(const string &filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File open failed" << endl;
        exit(0);
    }
    string line;
    bool no2xyFlag = true;
    bool bd2noFlag = true;
    bool el2noFlag = true;

    while (getline(fin, line)) {
        if (line == "# Mesh vertex coordinates" && no2xyFlag) {
            for (int i = 0; i < 100; i++) {
                getline(fin, line);
                // 以空格为分界读取两个double型数据
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1);
                double x = stod(xStr);
                double y = stod(yStr);
                // 新建对象
                No2xy no2xy;
                no2xy.set(x, y);
                // 向vector中添加对象
                no2xyVec.push_back(no2xy);
            }
            no2xyFlag = false;
        }

        if (line == "# Elements" && bd2noFlag) {
            for (int i = 0; i < 45; i++) {
                getline(fin, line);
                // 以空格为分界读取两个int型数据
                int no1Value, no2Value;
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1); // 此处应该可以使用>>更为优雅地实现，见DAY2/read_elm.cpp
                no1Value = stoi(xStr);
                no2Value = stoi(yStr);
                // 新建对象
                Bd2no bd2no;
                bd2no.set(i + 1, no1Value, no2Value);
                // 将对象添加到vector中
                bd2noVec.push_back(bd2no);
            }
            bd2noFlag = false;
        }

        if (line == "# Geometric entity indices") {
            for (int i = 0; i < 45; i++) {
                getline(fin, line);
                int bd = stoi(line);
                bd2noVec[i].set("bd", bd);
            }
        }

        if (line == "157 # number of elements" && el2noFlag) {
            // getline(fin, line);
            for (int i = 0; i < 157; i++) {
                getline(fin, line);
                int no1, no2, no3;
                fin >> no1 >> no2 >> no3;
                El2no el2no;
                el2no.set(no1, no2, no3);
                el2noVec.push_back(el2no);
            }
            el2noFlag = false;
        }
    }
    fin.close();
}

Mesh::~Mesh() {
    int size = bd2noVec.size() + el2noVec.size() + no2xyVec.size();
    cout << "Mesh: " << size << endl;
    bd2noVec.clear();
    el2noVec.clear();
    no2xyVec.clear();
}

string Mesh::display_sorted(int type, string attr, bool is_ascending) {
    string result;
    switch (type) {
        case 0: {
            sort(el2noVec.begin(), el2noVec.end(), [&attr, &is_ascending](El2no a, El2no b) {
                return a.get(attr) < b.get(attr) == is_ascending;
            });
            for (auto &i: el2noVec) {
                i.display();
                //将数据存入string中
                result += "El2no:" + to_string(i.get_id()) + "\n";
                result += "no1: " + to_string(i.get("no1")) + "\n";
                result += "no2: " + to_string(i.get("no2")) + "\n";
                result += "no3: " + to_string(i.get("no3")) + "\n";
            }
            break;
        }
        case 1: {
            sort(bd2noVec.begin(), bd2noVec.end(), [&attr, &is_ascending](Bd2no a, Bd2no b) {
                return a.get(attr) < b.get(attr) == is_ascending;
            });
            for (auto &i: bd2noVec) {
                i.display();
                //将数据存入string中
                result += "Bd2no:" + to_string(i.get_id()) + "\n";
                result += "bd: " + to_string(i.get("bd")) + "\n";
                result += "no1: " + to_string(i.get("no1")) + "\n";
                result += "no2: " + to_string(i.get("no2")) + "\n";
            }
            break;
        }
        case 2: {
            sort(no2xyVec.begin(), no2xyVec.end(), [&attr, &is_ascending](No2xy a, No2xy b) {
                return a.get(attr) < b.get(attr) == is_ascending;
            });
            for (auto &i: no2xyVec) {
                i.display();
                //将数据存入string中
                result += "No2xy:" + to_string(i.get_id()) + "\n";
                result += "x: " + to_string(i.get("x")) + "\n";
                result += "y: " + to_string(i.get("y")) + "\n";

            }
            break;
        }
        default:
            cout << "Error: Invalid type" << endl;

    }
    return result;
}

string Mesh::display_mid(int type, string attr, double upperbound, double lowerbound) {
    string result;
    switch (type) {
        case 0: {
            vector<El2no> temp;
            copy_if(el2noVec.begin(), el2noVec.end(), back_inserter(temp), [&attr, &upperbound, &lowerbound](El2no a) {
                return a.get(attr) <= upperbound && a.get(attr) >= lowerbound;
            });
            for (auto &i: temp) {
                i.display();
                //将数据存入string中
                result += "El2no:" + to_string(i.get_id()) + "\n";
                result += "no1: " + to_string(i.get("no1")) + "\n";
                result += "no2: " + to_string(i.get("no2")) + "\n";
                result += "no3: " + to_string(i.get("no3")) + "\n";
            }
            break;
        }
        case 1: {
            vector<Bd2no> temp;
            copy_if(bd2noVec.begin(), bd2noVec.end(), back_inserter(temp), [&attr, &upperbound, &lowerbound](Bd2no a) {
                return a.get(attr) <= upperbound && a.get(attr) >= lowerbound;
            });
            for (auto &i: temp) {
                i.display();
                //将数据存入string中
                result += "Bd2no:" + to_string(i.get_id()) + "\n";
                result += "bd: " + to_string(i.get("bd")) + "\n";
                result += "no1: " + to_string(i.get("no1")) + "\n";
                result += "no2: " + to_string(i.get("no2")) + "\n";

            }
            break;
        }
        case 2: {
            vector<No2xy> temp;
            copy_if(no2xyVec.begin(), no2xyVec.end(), back_inserter(temp), [&attr, &upperbound, &lowerbound](No2xy a) {
                return a.get(attr) <= upperbound && a.get(attr) >= lowerbound;
            });
            for (auto &i: temp) {
                i.display();
                //将数据存入string中
                result += "No2xy:" + to_string(i.get_id()) + "\n";
                result += "x: " + to_string(i.get("x")) + "\n";
                result += "y: " + to_string(i.get("y")) + "\n";

            }
            break;
        }
        default:
            cout << "Error: Invalid type" << endl;
    }

    return result;

}

bool Mesh::add(El2no el2no) {
    // 判断是否已经存在
    for (auto &i: el2noVec) {
        if (i.get("no1") == el2no.get("no1") && i.get("no2") == el2no.get("no2") && i.get("no3") == el2no.get("no3")) {
            cout << "Error: Element already exists" << endl;
            return false;
        }
    }
    el2noVec.push_back(el2no);
    return true;
}

bool Mesh::add(Bd2no bd2no) {
    // 判断是否已经存在
    for (auto &i: bd2noVec) {
        if (i.get("bd") == bd2no.get("bd") && i.get("no1") == bd2no.get("no1") && i.get("no2") == bd2no.get("no2")) {
            cout << "Error: Boundary already exists" << endl;
            return false;
        }
    }
    bd2noVec.push_back(bd2no);
    return true;
}

bool Mesh::add(No2xy no2xy) {
    // 判断是否已经存在
    for (auto &i: no2xyVec) {
        if (i.get("x") == no2xy.get("x") && i.get("y") == no2xy.get("y")) {
            cout << "Error: Node already exists" << endl;
            return false;
        }
    }
    no2xyVec.push_back(no2xy);
    return true;
}

bool Mesh::del(int no1, int no2, int no3) {
    //EL2NO的删除函数
    for (auto i = el2noVec.begin(); i != el2noVec.end(); i++) {
        if (i->get("no1") == no1 && i->get("no2") == no2 && i->get("no3") == no3) {
            el2noVec.erase(i);
            return true;
        }
    }
    cout << "Error: Element not found" << endl;
    return false;
}

bool Mesh::del(int no1, int no2) {
    //BD2NO的删除函数
    for (auto i = bd2noVec.begin(); i != bd2noVec.end(); i++) {
        if (i->get("no1") == no1 && i->get("no2") == no2) {
            bd2noVec.erase(i);
            return true;
        }
    }
    cout << "Error: Boundary not found" << endl;
    return false;
}

bool Mesh::del(double no1) {
    //NO2XY的删除函数
    for (auto i = no2xyVec.begin(); i != no2xyVec.end(); i++) {
        if (i->get("x") == no1) {
            no2xyVec.erase(i);
            return true;
        }
    }
    cout << "Error: Node not found" << endl;
    return false;
}

void Mesh::solve() {
    //生成并初始化系数矩阵
    int size = no2xyVec.size();
    auto *A = new double[size * size];
    for (int i = 0; i < size * size; i++) {
        A[i] = 0;
    }

    for (auto &i: el2noVec) {
        int no1 = i.get("no1");
        int no2 = i.get("no2");
        int no3 = i.get("no3");
        double x1 = no2xyVec[no1].get("x");
        double y1 = no2xyVec[no1].get("y");
        double x2 = no2xyVec[no2].get("x");
        double y2 = no2xyVec[no2].get("y");
        double x3 = no2xyVec[no3].get("x");
        double y3 = no2xyVec[no3].get("y");
        double area = (x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - x3 * y2) / 2;
        double parm = VACUUM_PERMITTIVITY / (4 * area);
        double a1 = x2 * y3 - x3 * y2;
        double a2 = x3 * y1 - x1 * y3;
        double a3 = x1 * y2 - x2 * y1;
        double b1 = y2 - y3;
        double b2 = y3 - y1;
        double b3 = y1 - y2;
        double c1 = x3 - x2;
        double c2 = x1 - x3;
        double c3 = x2 - x1;
        A[no1 * size + no1] += parm * (b1 * b1 + c1 * c1);
        A[no1 * size + no2] += parm * (b1 * b2 + c1 * c2);
        A[no1 * size + no3] += parm * (b1 * b3 + c1 * c3);
        A[no2 * size + no1] += parm * (b2 * b1 + c2 * c1);
        A[no2 * size + no2] += parm * (b2 * b2 + c2 * c2);
        A[no2 * size + no3] += parm * (b2 * b3 + c2 * c3);
        A[no3 * size + no1] += parm * (b3 * b1 + c3 * c1);
        A[no3 * size + no2] += parm * (b3 * b2 + c3 * c2);
        A[no3 * size + no3] += parm * (b3 * b3 + c3 * c3);
    }

    //获取6、7、14、15边界的端点，存入vector中
    vector<int> HV;
    for (auto &i: bd2noVec) {
        if (i.get("bd") == 6 || i.get("bd") == 7 || i.get("bd") == 14 || i.get("bd") == 15) {
            HV.push_back(i.get("no1"));
            HV.push_back(i.get("no2"));
        }
    }
    //将vector中的元素去重
    sort(HV.begin(), HV.end());
    HV.erase(unique(HV.begin(), HV.end()), HV.end());
    for(auto &i:HV){
        for(int j =0 ;j<size;j++){
            A[i*size+j]=0;
        }
        A[i*size+i]=1;
    }

    //获取5、13、16边界的端点，存入vector中
    vector<int> GND;
    for (auto &i: bd2noVec) {
        if (i.get("bd") == 5 || i.get("bd") == 13 || i.get("bd") == 16) {
            GND.push_back(i.get("no1"));
            GND.push_back(i.get("no2"));
        }
    }
    //将vector中的元素去重
    sort(GND.begin(), GND.end());
    GND.erase(unique(GND.begin(), GND.end()), GND.end());
    for(auto &i:GND){
        for(int j =0 ;j<size;j++){
            A[i*size+j]=0;
        }
        A[i*size+i]=1;
    }
    //生成并初始化右端项
    auto *b = new double[size];
    for (int i = 0; i < size; i++) {
        b[i] = 0;
    }

    for(auto &i:HV){
        b[i]=1;
    }

    //@Test: 打印系数矩阵
    for (int i = 0; i < size * size; i++) {
        cout << A[i] << " ";
        if ((i + 1) % size == 0) {
            cout << endl;
        }
    }


//lapacke求解方程，结果存储在record中
    int n = size;
    int nrhs = 1;
    int lda = n;
    int ldb = 1;
    int *ipiv = (int *) malloc(sizeof(int) * n);
    int info;
    info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);
    if (info > 0) {
        cout << "The diagonal element of the triangular factor of A,\n";
        cout << "U(" << info << "," << info << ") is zero, so that A is singular;\n";
        cout << "the solution could not be computed.\n";
        exit(1);
    }
    if (info < 0) exit(1);
    for (int i = 0; i < size; i++) {
        record.push_back(b[i]);
    }
    //@Test: 打印解向量
    for (int i = 0; i < size; i++) {
        cout << record[i] << endl;
    }
    free(ipiv);
    free(A);
    free(b);
}

void Mesh::db_init() {
    //打开数据库
    int rc = sqlite3_open("phi.db", &db);
    if (rc) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        exit(0);
    } else {
        cout << "Opened database successfully" << endl;
    }

    //创建表record,如果表已经存在则不创建,以自增_id为主键，包含text类的系统时间和0-106个float类的phi变量
    string sql;
    sql += "CREATE TABLE IF NOT EXISTS record(";
    sql += "_id INTEGER PRIMARY KEY AUTOINCREMENT,";
    sql += "time TEXT NOT NULL,";
    for (int i = 0; i < 100; i++) {
        sql += "phi" + to_string(i) + " FLOAT,";
    }
    sql.pop_back();
    sql += ");";
    //将string转换为char*
    const char *sql1 = sql.c_str();
    char *zErrMsg = nullptr;
    rc = sqlite3_exec(db, sql1, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Table created successfully" << endl;
    }
}

bool Mesh::add_record() {
    //初始化数据库
    db_init();//初始化数据库，将其嵌套于此减少外层调用的函数数量
    //获取系统时间
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    char time[20];
    sprintf(time, "%d-%d-%d %d:%d:%d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min,
            ltm->tm_sec);

    //通过for循环将record中的值存入数据库
    string sql;
    sql += "INSERT INTO record(time,";
    for (int i = 0; i < 100; i++) {
        sql += "phi" + to_string(i) + ",";
    }
    sql.pop_back();
    sql += ") VALUES('" + string(time) + "',";
    for (int i = 0; i < 100; i++) {
        sql += to_string(record[i]) + ",";
    }
    //去除最后一个逗号
    sql.pop_back();

    sql += ");";
    cout << sql << endl;
    //将string转换为char*
    const char *sql1 = sql.c_str();
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, sql1, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return false;
    } else {
        cout << "Records created successfully" << endl;
        return true;
    }
}

string Mesh::qurry_record() {
    //将数据库中的表头和数据存入string中
    string sql;
    sql += "SELECT * FROM record;";
    const char *sql1 = sql.c_str();
    char *zErrMsg = nullptr;
    char **dbResult = nullptr;
    int nRow, nColumn;
    int rc = sqlite3_get_table(db, sql1, &dbResult, &nRow, &nColumn, &zErrMsg);
    if (rc != SQLITE_OK) {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
    string result;
    for (int i = 0; i < nColumn; i++) {
        result += dbResult[i];
        result += " ";
    }
    result += "\n";
    for (int i = nColumn; i < (nRow + 1) * nColumn; i++) {
        result += dbResult[i];
        result += " ";
        if ((i + 1) % nColumn == 0) {
            result += "\n";
        }
    }
    sqlite3_free_table(dbResult);
    //将表drop
    sql = "DROP TABLE record;";
    sql1 = sql.c_str();
    rc = sqlite3_exec(db, sql1, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Table dropped successfully" << endl;
    }
    sqlite3_close(db);
    std::cout << result << std::endl;
    return result;
}

Mesh::Mesh() {

}



